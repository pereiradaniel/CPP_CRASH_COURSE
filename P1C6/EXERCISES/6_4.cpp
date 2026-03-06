// Listing 6-4

// Refactor mean in Listing 6-13 to accept an array rather than pointer and length arguments. Use Listing 6-33 as a guide.

#include <cstdio>
#include <cstddef>

template <typename T, size_t Length>
T mean(const T(&values)[Length]) {
	T result{};
	for (size_t i{}; i < Length; i++) {
		result += values[i];
	}
	return result / Length;
}

int main() {
  const double nums_d[]{ 1.0, 2.0, 3.0, 4.0 };
  // Usage makes it clear that template parameter T is double, so we can omit the explicit template argument.
  const auto result1 = mean<double, sizeof(nums_d) / sizeof(double)>(nums_d);
  printf("double: %.1f\n", result1);

  const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
  // Usage makes it clear that template parameter T is float, so we can omit the explicit template argument.
  const auto result2 = mean<float, sizeof(nums_f) / sizeof(float)>(nums_f);
  printf("float: %.1f\n", result2);

  const size_t nums_c[]{ 1, 2, 3, 4 };
  // Usage makes it clear that template parameter T is size_t, so we can omit the explicit template argument.
  const auto result3 = mean<size_t, sizeof(nums_c) / sizeof(size_t)>(nums_c);
  printf("size_t: %lu\n", result3);
}