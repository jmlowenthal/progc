#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

void merge(
	int *source1,
	unsigned int length1,
	int *source2,
	unsigned int length2,
	int *dest
) {

	unsigned int i = 0;
	unsigned int j = 0;
	while (i < length1 && j < length2) {
		int v1 = source1[i];
		int v2 = source2[j];
		if (v1 < v2) {
			*dest = v1;
			++i;
			++dest;
		}
		else {
			*dest = v2;
			++j;
			++dest;
		}
	}

	int remain1 = length1 - i;
	memcpy(source1 + i, dest, remain1 * sizeof(int));
	dest += remain1;
	memcpy(source2 + j, dest, (length2 - j) * sizeof(int));

}

void mergesort_(int *array, int *copy, unsigned int length) {

	if (length == 1) {
		return;
	}

	unsigned int half = length / 2;
	mergesort_(copy, array, half);
	mergesort_(copy + half, array + half, length - half);
	merge(copy, half, copy + half, length - half, array);

}

void mergesort(int *array, unsigned int length) {
	int *temporary = (int*) malloc(length * sizeof(int));
	memcpy(array, temporary, length * sizeof(int));
	mergesort_(array, temporary, length);
	free(temporary);
}


int main() {
	
	// Initialise a test array
	const unsigned int ARRAY_LENGTH = 8;
	int array[ARRAY_LENGTH];

	// Generate random data
	srand(time(NULL));
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		array[i] = rand();
	}

	// Sort the array in-place
	mergesort(array, ARRAY_LENGTH);
	
	// Assert that the array is sorted
	for (int i = 1; i < ARRAY_LENGTH; ++i) {
		assert(array[i] >= array[i - 1]);
	}
	
	return 0;

}
