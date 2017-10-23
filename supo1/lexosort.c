#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

char lexoNormalise(char c) {
	// Normalise characters to the range [ (-26) – (-1) ]
	return ('A' <= c && c <= 'Z') ? -26 + (c - 'A')
		: ('a' <= c && c <= 'z') ? -26 + (c - 'a')
		: c;
}

int compareTo(char a, char b) {
	// Normalise characters
	char aNorm = lexoNormalise(a);
	char bNorm = lexoNormalise(b);
	
	// Same normalisation => upper- and lower-case variants
	if (aNorm == bNorm) {
		return a - b;
	}
	else {
		return aNorm - bNorm;
	}
}

void bubblesort(char array[], unsigned int length) {
	for (int cap = length; cap > 1; --cap) {
		for (int i = 1; i < cap; ++i) {
			int j = i - 1;
			if (compareTo(array[i], array[j]) < 0) {
				char tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int main() {
	
	// Initialise a test array
	const int ARRAY_LENGTH = 8;
	char array[ARRAY_LENGTH];

	// Generate random data
	srand(time(NULL));
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		array[i] = 'A' + rand() % 50;
	}

	// Sort the array in-place
	bubblesort(array, ARRAY_LENGTH);
	
	// Assert that the array is sorted
	for (int i = 1; i < ARRAY_LENGTH; ++i) {
		assert(lexoNormalise(array[i]) >= lexoNormalise(array[i - 1]));
	}
	
	return 0;

}
