#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *reverse(char *input) {
	
	if (NULL == input) {
		return NULL;
	}

	int len = strlen(input);
	char *output = malloc((len + 1) * sizeof(char));

	if (NULL == output) {
		return NULL;
	}

	for (int i = 0; i < len; ++i) {
		output[len - i - 1] = input[i];
	}

	output[len] = '\0';

	return output;

}

int main(int argc, char **argv) {
	for (int i = 1; i < argc; ++i) {
		char *revd = reverse(argv[i]);
		printf("%s -> %s\n", argv[i], revd);
		free(revd);
	}
	return 0;
}
