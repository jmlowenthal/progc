#include <ctype.h>
#include <string.h>
#include "revwords.h"

#define IS_CHAR(x) (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))

void reverse_substring(char str[], int start, int end) { 
	for (int i = start, j = end - 1; i < j; ++i, --j) {
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}


int find_next_start(char str[], int len, int i) { 
	for (; i < len; ++i) {
		if (IS_CHAR(str[i])) {
			return i;
		}
	}
	return len;
}

int find_next_end(char str[], int len, int i) {
	for (; i < len; ++i) {
		if (!IS_CHAR(str[i])) {
			return i;
		}
	}
	return len;
}

void reverse_words(char s[]) { 
	int start = 0;
	int end = 0;
	int len = strlen(s);
	while (end < len) {
		start = find_next_start(s, len, end);
		end = find_next_end(s, len, start);
		reverse_substring(s, start, end);
	}
}
