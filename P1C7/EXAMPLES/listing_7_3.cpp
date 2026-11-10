#include <cstdio>
#include <limits>
#include <stdexcept>

struct CheckedInteger {
  CheckedInteger(unsigned int value)
      : value{ value } {}

  CheckedInteger operator+(unsigned int other) const {
    CheckedInteger result{ value + other };
    if(result.value < value)
      throw std::overflow_error{ "Overflow!" };
    return result;
  }

  const unsigned int value;
};

int main() {
  CheckedInteger a{ 100 };          // Construct a CheckedInteger with value 100
  auto b = a + 200;                 // Add 200 to a, which should be safe and not cause overflow
  printf("a + 200 = %u", b.value);
  try {
    // Attempt to add the maximum unsigned int value to a, which should cause overflow
    auto c = a + std::numeric_limits<unsigned int>::max();
  } catch(const std::overflow_error& e) {
    printf("(a + max) Exception: %s\n", e.what());
  }
}
