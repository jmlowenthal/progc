#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>

#include <netinet/ip.h>
#include <netinet/tcp.h>

int main(int argc, char *argv[]) {
	
	if (argc != 3) {
		perror("Usage: extract <input file> <output file>");
		return -1;
	}

	// Open file
	FILE *file;
	if ((file = fopen(argv[1], "rb")) == 0) {
		perror("Cannot open file specified");
		return -2;
	}

	FILE *output_file = fopen(argv[2], "w");

	char buffer[sizeof(struct iphdr)];
	unsigned int offset = 0;

	do {
		
		fseek(file, offset, SEEK_SET);

		int r = fread(buffer, sizeof(char), sizeof(struct iphdr), file);
		
		if (r != sizeof(struct iphdr)) {
			break;
		}

		struct iphdr *header = (struct iphdr *) buffer;
		
		// Get TCP offset
		unsigned int ihl = header->ihl * 4;
		fseek(file, offset + ihl + 12, SEEK_SET);
		unsigned char data_offset;
		fread(&data_offset, sizeof(char), 1, file);
		data_offset = (data_offset >> 4) & 0xf;

		// Get data
		unsigned int header_length = ihl + data_offset * 4;
		fseek(file, offset + header_length, SEEK_SET);
		char tmp[ntohs(header->tot_len) - header_length];
		int r2 = fread(tmp, sizeof(char), sizeof(tmp), file);
		
		// Write out data
		int w = 0;
		while (w < r2) {
			int total = fwrite(tmp + w, sizeof(char), r2 - w, output_file);
			if (total < 0) {
				perror("Failed to write file");
				return -3;
			}
			w += total;
		}
		
		offset += ntohs(header->tot_len);

	}
	while (!feof(file));
	
	fclose(file);

	return 0;

}
