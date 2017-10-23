#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_CASES 8
char *cases[NUMBER_OF_CASES * 2] = {
	"./lab8 \"3\"",
	"./lab8 \"3+4\"",
	"./lab8 \"3+4*5\"",
	"./lab8 \"3+4*5+2\"",
	"./lab8 \"3+4*(5+2)\"",
	"./lab8 \"(3+4)*(5+2)\"",
	"./lab8 \"1 + 2\"",
	"./lab8 \"1-2\""
};

void main() {
	for (int i = 0; i < NUMBER_OF_CASES; ++i) {
		printf("Test %d: %s\n", i, cases[i]);
		system(cases[i]);
		printf("\n");
	}
}
