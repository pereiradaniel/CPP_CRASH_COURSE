// Listing 6-18: A program using type traits.

#include <cstdint>
#include <cstdio>
#include <type_traits>

// A helper function to convert a boolean value to a string for printing:
constexpr const char* as_str(bool x) {
  // Return a string literal "True" if x is true, and "False" if x is false. This allows us to print the results of type trait checks in a more human-readable format:
  return x ? "True" : "False";
}

int main() {
  // Use the is_integral type trait to check if various types are integral types, and print the results:
  printf("%s\n", as_str(std::is_integral<int>::value));
  printf("%s\n", as_str(std::is_integral<const int>::value));
  printf("%s\n", as_str(std::is_integral<char>::value));
  printf("%s\n", as_str(std::is_integral<uint64_t>::value));
  printf("%s\n", as_str(std::is_integral<int&>::value));
  printf("%s\n", as_str(std::is_integral<int*>::value));
  printf("%s\n", as_str(std::is_integral<float>::value));
}
