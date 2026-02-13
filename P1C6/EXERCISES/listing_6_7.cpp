// Listing 6-7

// A program using narrow_cast to safely convert an int to a short. The first conversion succeeds because 496 can be represented as a short, while the second conversion throws a runtime error because 142857 cannot be represented as a short without loss of information.

#include <cstdio>
#include <stdexcept>

// From Listing 6-6.
template <typename To, typename From>
To narrow_cast(From value) {
  const auto converted = static_cast<To>(value);
  const auto backwards = static_cast<From>(converted);
  if(value != backwards)
    throw std::runtime_error{ "Narrowed!" };
  return converted;
}

int main() {
  int perfect{ 496 };
  // perfect is narrow_cast to a short called perfect_short. Since 496 can be represented as a short, the conversion succeeds and perfect_short is assigned the value 496.
  const auto perfect_short = narrow_cast<short>(perfect);
  printf("perfect_short: %d\n", perfect_short);
  try {
    int cyclic{ 142857 };
    // Attempt to narrow_cast cyclic to the short cyclic_short. Since 142857 cannot be represented as a short without loss of information, the narrow_cast function throws a runtime error, which is caught by the catch block, and an error message is printed.
    const auto cyclic_short = narrow_cast<short>(cyclic);
    printf("cyclic_short: %d\n", cyclic_short);
  } catch(const std::runtime_error& e) {
    printf("Exception: %s\n", e.what());
  }
}
