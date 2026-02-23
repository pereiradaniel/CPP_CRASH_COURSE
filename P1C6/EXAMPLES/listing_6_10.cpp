// Listing 6-10: Refactoring Listing 6-8 into a template function.
#include <cstddef>

// Template prefix with a single template parameter T.
template<typename T>
// Update mean to use T instead of double.
T mean(const T* values, size_t length) {
    T result{};
    for(size_t i = 0; i < length; ++i) {
        result += values[i];
    }
    return result / length;
}