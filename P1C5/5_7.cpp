#include <cstdio>

struct BaseClass {
  // Base class contains a virtual member:
  virtual const char* final_message() const {
    return "We apologise for the incontinence.";
  }
};

// In DerivedClass, inherited member is overridden:
struct DerivedClass : BaseClass {
  // 3
  const char* final_message() const override {
    return "We apologise for the inconvenience.";
  }
};

int main() {
  BaseClass base;
  DerivedClass derived;
  BaseClass& ref = derived;
  // Implementation of BaseClass is used only when a BaseClass instance is at hand:
  printf("BaseClass:    %s\n", base.final_message());
  // Implementation of DerivedClass is used only when a DerivedClass instance is at hand:
  printf("DerivedClass: %s\n", derived.final_message());
  // Even if interacting with it through a BaseClass reference:
  printf("BaseClass&:   %s\n", ref.final_message());
}
