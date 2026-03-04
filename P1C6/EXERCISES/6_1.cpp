// Listing 6-1

// The mode of a series of values is the value that appears most commonly. Implement a mode function using the following signature:

// int mode (const int* values, size_t length)

// If you encounter an error condition, such as input having multiple modes and no values, return zero.

#include <cstdio>
#include <iostream>
using namespace std;

// Mode function prototype
int mode(const int* values, size_t length);

int mode(const int* values, size_t length) {
    if (length == 0) {
        return 0; // No values, return zero
    }

    int maxCount = 0;               // Maximum count of occurrences.
    int modeValue = 0;              // Value that appears most frequently.
    bool multipleModes = false;     // Flag to indicate if there are multiple modes.

    for (size_t i = 0; i < length; ++i) {
        int count = 1; // Count the current value

        for (size_t j = i + 1; j < length; ++j) {
            if (values[i] == values[j]) {
                ++count; // Increment count if we find a match
            }
        }

        if (count > maxCount) {
            maxCount = count;
            modeValue = values[i];
            multipleModes = false; // Reset multiple modes flag
        } else if (count == maxCount && count > 1) {
            multipleModes = true; // Found another mode with the same count
        }
    }

    if (multipleModes) {
        return 0; // Multiple modes found, return zero
    }

    return modeValue; // Return the mode value
}