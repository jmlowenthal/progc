#include <stdlib.h>
#include <stdio.h>

#define NUMBER_OF_CASES 8

const char *cases[NUMBER_OF_CASES] = {
	"./lab10 \"3\"",
	"./lab10 \"3+4\"",
	"./lab10 \"3+4*5\"",
	"./lab10 \"3+4*5+2\"",
	"./lab10 \"3+4*(5+2)\"",
	"./lab10 \"(3+4)*(5+2)\"",
	"./lab10 \"1 + 2\"",
	"./lab10 \"1-2\"",
};

int main() {
	for (int i = 0; i < NUMBER_OF_CASES; ++i) {
		printf("%s\n", cases[i]);
		system(cases[i]);
		printf("\n");
	}
	return 0;
}
