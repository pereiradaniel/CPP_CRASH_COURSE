// Listing 5-8: A refactor of 5-7 using a pure virtual method.

#include <cstdio>

struct BaseClass {
  virtual const char* final_message() const = 0;
};

struct DerivedClass : BaseClass {
  const char* final_message() const override {
    return "We apologise for the inconvenience.";
  }
};

int main() {
  // BaseClass base; // Bang!
  DerivedClass derived;
  BaseClass& ref = derived;
  printf("DerivedClass: %s\n", derived.final_message());
  printf("BaseClass&:   %s\n", ref.final_message());
}
