// This program demonstrates how to use a pointer to access a memory-mapped timer. It casts the address 0x1000 to a pointer to an unsigned long and prints the value at that address.

#include <cstdio>

int main() {
  // reinterpret_cast takes a type parameter that corresponds to the desired pointer type. In this case, we want to treat the address 0x1000 as a pointer to an unsigned long.
  auto timer = reinterpret_cast<const unsigned long*>(0x1000);
  printf("Timer is %lu.", *timer);
}
