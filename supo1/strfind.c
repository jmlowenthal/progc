#include <string.h>
#include <stdio.h>

char *strfind(const char *s, const char *f) {

	int lenS = strlen(s);
	if (lenS == 0) {
		return NULL;
	}
	
	int lenF = strlen(f);
	
	for (int i = 0; i < lenF - lenS; ++i) {
		int j = 0;
		int k = i;
		while (s[j] == f[k]) {
			++j, ++k;
			if (j == lenS) {
				return (char*)&f[i];
			}
		}
	}

	return NULL;
}

int main() {
	
	const char *str = "University of Cambridge";
	char *loc = strfind("of", str);

	printf("%s\n", str);
	for (int i = 0; i < (loc - str); ++i) {
		printf(" ");
	}
	printf("^\n");
}
