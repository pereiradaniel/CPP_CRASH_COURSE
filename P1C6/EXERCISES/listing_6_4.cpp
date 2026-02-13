// This program defines an increment_as_short function that takes a void pointer, casts it to a short pointer, increments the value it points to, and returns the incremented value. The main function initializes a short variable with the value 665, calls the increment_as_short function with its address, and prints the result.

// Some low-level applications might require you to interpret raw bytes as an integer type

#include <cstdio>

// target parameter is a void pointer.
short increment_as_short(void* target) {
  // Use static_cast to convert the void pointer to a short pointer, then dereference it to get the value, increment it, and return the result.
  auto as_short = static_cast<short*>(target);
  *as_short = *as_short + 1;
  return *as_short;
}

int main() {
  short beast{ 665 };
  auto mark_of_the_beast = increment_as_short(&beast);
  printf("%d is the mark_of_the_beast.", mark_of_the_beast);
}

// The implicit conversion of short* to void* is well defined. Attempting ill-defined conversions with static_cast, such as converting char* to a float* will result in a compile-time error.