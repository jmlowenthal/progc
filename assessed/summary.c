#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>

#include <netinet/ip.h>
#include <netinet/tcp.h>

int main(int argc, char *argv[]) {
	
	if (argc != 2) {
		perror("Usage: summary <file>");
		return -1;
	}

	// Open file
	FILE *file;
	if ((file = fopen(argv[1], "rb")) == 0) {
		perror("Cannot open file specified");
		return -2;
	}

	unsigned char *src = NULL;
	unsigned char *dst = NULL;
	unsigned char ihl = 0;
	unsigned short ip_len = 0;
	unsigned char data_offset = 0;
	unsigned int packet_count = 0;


	// FIRST IP HEADER
	{
		char buffer[sizeof(struct iphdr)];

		int r = fread(buffer, sizeof(char), sizeof(struct iphdr), file);

		if (r != sizeof(struct iphdr)) {
			printf("Incomplete header found, terminating\n");
			return 0;
		}

		struct iphdr *header = (struct iphdr *) buffer;

		ihl = header->ihl;
		ip_len = ntohs(header->tot_len);
		
		// Network byte-order --> hacks
		src = (unsigned char *) &header->saddr;
		dst = (unsigned char *) &header->daddr;
	}

	// FIRST TCP HEADER
	{
		fseek(file, 12, SEEK_CUR);

		int r = fread(&data_offset, sizeof(char), 1, file);
		data_offset = (data_offset >> 4) & 0xf;

		if (r != 1) {
			printf("Error reading TCP header\n");
			return 0;
		}

	}


	// COUNT IP HEADERS
	{
		char buffer[sizeof(struct iphdr)];
		unsigned int offset = 0;

		do {
			
			fseek(file, offset, SEEK_SET);

			int r = fread(buffer, sizeof(char), sizeof(struct iphdr), file);
			
			if (r != sizeof(struct iphdr)) {
				break;
			}

			struct iphdr *header = (struct iphdr *) buffer;

			offset += ntohs(header->tot_len);
			++packet_count;

		}
		while (!feof(file));
	}
	
	// IP source and destination
	// IP IHL - header length
	// IP total length
	// TCP data offset
	// Number of packets
	printf(
			"%d.%d.%d.%d %d.%d.%d.%d %d %d %d %d\n",
			src[0], src[1], src[2], src[3],
			dst[0], dst[1], dst[2], dst[3],
			ihl,
			ip_len,
			data_offset,
			packet_count
		);

	fclose(file);

	return 0;

}
