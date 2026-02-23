// Listing 6-8: A function for computing the mean of an array.

#include <cstddef>

double mean(const double* values, size_t length) {
    // Initialize a result variable to zero.
    double result{};
    for(size_t i = 0; i < length; ++i) {
        // Add each value in the array to the result variable.
        result += values[i];
    }
    // Divide result by length and return the mean.
    return result / length;
}