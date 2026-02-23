// Listing 6-13: A refactor of Listing 6-11 without explicit template parameters.

#include <cstddef>
#include <cstdio>

template <typename T>
T mean(const T* values, size_t length) {
  T result{};
  for(size_t i{}; i < length; i++) {
    result += values[i];
  }
  return result / length;
}

int main() {
  const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
  // Usage makes it clear that template parameter T is double, so we can omit the explicit template argument.
  const auto result1 = mean(nums_d, 4);
  printf("double: %f\n", result1);

  const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
  // Usage makes it clear that template parameter T is float, so we can omit the explicit template argument.
  const auto result2 = mean(nums_f, 4);
  printf("float: %f\n", result2);

  const size_t nums_c[]{ 1, 2, 3, 4 };
  // Usage makes it clear that template parameter T is size_t, so we can omit the explicit template argument.
  const auto result3 = mean(nums_c, 4);
  printf("size_t: %lu\n", result3);
}
