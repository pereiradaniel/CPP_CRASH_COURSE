// Listing 6-1

// The mode of a series of values is the value that appears most commonly. Implement a mode function using the following signature:

// int mode (const int* values, size_t length)

// If you encounter an error condition, such as input having multiple modes and no values, return zero.

#include <cstdio>
#include <iostream>
using namespace std;

int mode(const int* values, size_t length) {
	if (length == 0) return 0;

	int mode_frequency{};           // Value of the mode (most frequently occurring value).
	int check_frequency{};          // Count of occurrences of the current value being checked.
	int mode_index{};                // Index of the current mode value in the array.

	// Outer loop to iterate through each value in the array:
	for (size_t i = 0; i < length; i++) {
		int cursor = values[i];     // Current value being checked for frequency.

		check_frequency++;                   // Increment amount for the current value.

        // Inner loop to count occurrences of the current value:
        for (size_t j = i + 1; j < length; j++) {
			if (cursor == values[j]) {
				check_frequency++;
			}
		}

        // Check if the current value has a higher count than the max count found so far:
		if (check_frequency > mode_frequency) {
			mode_frequency = check_frequency;
			mode_index = i;
			check_frequency = 0;
		}

        // If the current value has a count less than the max count, reset amount and continue:
		else if (check_frequency < mode_frequency) {
			check_frequency = 0;
			continue;
		}
        // If the current value has a count equal to the max count, it means there are multiple modes:
		else if (check_frequency == mode_frequency) return 0;
	}

    // Return the value of the mode found in the array:
	return values[mode_index];
}

int main() {
	int test_array1[] = { 1,1,1,2,2,2,2,4,5,1,4,4,6,6,6,6,1,1,1,6,6,6,6,5,6,6,5,5,5,5};

    int test_array2[] = {111,222,3333,4,5,6,7,8,9,10};

    size_t length = sizeof(test_array1) / sizeof(int);

	printf("Array : ");
	for (size_t i = 0; i < length; i++) {
		printf("%d ", test_array1[i]);
	}

	printf("\nMode is : %d", mode(test_array1, length));

    printf("Array : ");
	for (size_t i = 0; i < length; i++) {
		printf("%d ", test_array2[i]);
	}

	printf("\nMode is : %d", mode(test_array2, length));

}