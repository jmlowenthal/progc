#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

void bubblesort(int array[], unsigned int length) {
	for (int cap = length; cap > 1; --cap) {
		for (int i = 1; i < cap; ++i) {
			int j = i - 1;
			if (array[i] < array[j]) {
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}

int main() {
	
	// Initialise a test array
	const int ARRAY_LENGTH = 128;
	int array[ARRAY_LENGTH];

	// Generate random data
	srand(time(NULL));
	for (int i = 0; i < ARRAY_LENGTH; ++i) {
		array[i] = rand();
	}

	// Sort the array in-place
	bubblesort(array, ARRAY_LENGTH);
	
	// Assert that the array is sorted
	for (int i = 1; i < ARRAY_LENGTH; ++i) {
		assert(array[i] >= array[i - 1]);
	}
	
	return 0;

}
