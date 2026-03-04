// Listing 6-1

// The mode of a series of values is the value that appears most commonly. Implement a mode function using the following signature:

// int mode (const int* values, size_t length)

// If you encounter an error condition, such as input having multiple modes and no values, return zero.

#include <cstdio>
#include <iostream>
using namespace std;

// Mode function prototype
int mode(const int* values, size_t length);

// Mode function body
int mode(const int* values, size_t length) {
    // Return 0 if length of array is 0:
    if (length <= 0)
        return 0;

    int  maxCount = 0;          // Maximum count of occurrences.
    int  modeValue = 0;         // Value that appears most frequently.
    bool multipleModes = false; // Flag to indicate if there are multiple modes.

    // Loop through values array:
    for (size_t i = 0; i < length; ++i) {
        int counter = 1; // Count the current value once

        for (size_t j = i + 1; j < length; ++j)
            if (values[i] == values[j])
                ++counter; // Increment counter

        // Handle result if current value occurs more frequently than the mode:
        if (counter > maxCount) {
            maxCount = counter;
            modeValue = values[i];
            multipleModes = false; // Reset multiple modes flag
        }
        // Handle result if current value occurs as frequently as the mode:
        else if (counter == maxCount && counter > 1) {
            multipleModes = true;  // Found another mode with the same count
        }
    }

    // Return 0 if multiple modes were found:
    if (multipleModes)
        return 0;

    // Return mode value if single mode was found:
    return modeValue;
}

int main() {
	int test_array1[] = { 1,1,1,2,2,2,3,4,4,4,4,5,6,7};

    int test_array2[] = { 1,2,3,4,5,5,6,6,7,7,7,8,9};

    size_t array_length = sizeof(test_array1) / sizeof(int);

	printf("\nArray : ");
	for (size_t i = 0; i < array_length; i++) {
		printf("%d ", test_array1[i]);
	}

	printf("\nMode is : %d", mode(test_array1, array_length));

	size_t array_length2 = sizeof(test_array2) / sizeof(int);

    printf("\nArray : ");
	for (size_t i = 0; i < array_length2; i++) {
		printf("%d ", test_array2[i]);
	}

	printf("\nMode is : %d", mode(test_array2, array_length2));

	printf("\n");
}