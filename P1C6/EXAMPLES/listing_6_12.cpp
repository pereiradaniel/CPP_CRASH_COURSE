// Listing 6-12: A program showing the overloaded templates instantiated from Listing 6-11.

#include <cstddef>

double mean(const double* values, size_t length) {
  double result{};
  for(size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

float mean(const float* values, size_t length) {
  float result{};
  for(size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

size_t mean(const size_t* values, size_t length) {
  size_t result{};
  for(size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}