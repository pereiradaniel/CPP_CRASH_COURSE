// Listing 6-3

// Modify mode to accept an Integer concept. Verify that mode fails to instantiate with floating types like double.

#include <iostream>
#include <concepts>
using namespace std;

template <typename T>
concept Integral = is_integral<T>::value;

template <Integral T>
T mode(const T* values, size_t length) {
    if (length <= 0)
        return 0;

    int  maxCount = 0;          // Maximum count of occurrences.
    T    modeValue = 0;         // Value that appears most frequently.
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
};

int main() {
	int test_array1[] = {1,1,1,2,2,2,3,4,4,4,4,5,6,7};

    int test_array2[] = {1,2,3,4,5,5,6,6,7,7,7,8,9};

    float test_array3[] = {1.0f,2.0f,3.0f,3.0f};

    // Int array 1:
    size_t array_length = sizeof(test_array1) / sizeof(int);
	printf("\nArray : ");
	for (size_t i = 0; i < array_length; i++) {
		printf("%d ", test_array1[i]);
	}
	printf("\nMode is : %d", mode(test_array1, array_length));

	// Int array 2:
	size_t array_length2 = sizeof(test_array2) / sizeof(int);
    printf("\nArray : ");
	for (size_t i = 0; i < array_length2; i++) {
		printf("%d ", test_array2[i]);
	}
	printf("\nMode is : %d", mode(test_array2, array_length2));

	// Float array:
	size_t array_length3 = sizeof(test_array3) / sizeof(float);
	printf("\nArray : ");
	for (size_t i = 0; i < array_length3; i++) {
		printf("%f ", test_array3[i]);
	}

	// Using mode in this line causes a compiler error that indicates this template instantiation could not be completed because the template requires Integral type.
	printf("\nMode is : %f", mode(test_array3, array_length3));

	printf("\n");
}