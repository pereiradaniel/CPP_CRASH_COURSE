// Listing 6-9: An overload of Listing 6-8 accepting a long array.

#include <cstddef>

long mean (const long* values, size_t length) {
    // Initialize a result variable to zero.
    long result{};
    for(size_t i = 0; i < length; ++i) {
        // Add each value in the array to the result variable.
        result += values[i];
    }
    // Divide result by length and return the mean.
    return result / length;
}