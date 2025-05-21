// Listing 5-7: A program using virtual members.

#include <cstdio>

struct BaseClass {
  // 1 Base class contains a virtual member:
  // virtual: Declares that a derived class's implementation should be used if one is supplied.
  virtual const char* final_message() const {
    return "We apologise for the incontinence.";
  }
};

// 2 DerivedClass inherits from BaseClass:
struct DerivedClass : BaseClass {
  // 3 In DerivedClass, inherited member is overridden with "override" keyword:
  const char* final_message() const override {
    return "We apologise for the inconvenience.";
  }
};

int main() {
  BaseClass base;
  DerivedClass derived;
  BaseClass& ref = derived;

  // 4 Implementation of BaseClass is used only when a BaseClass instance is at hand:
  printf("BaseClass:    %s\n", base.final_message());

  // 5 Implementation of DerivedClass is used only when a DerivedClass instance is at hand:
  printf("DerivedClass: %s\n", derived.final_message());

  // 6 Even if interacting with it through a BaseClass reference:
  printf("BaseClass&:   %s\n", ref.final_message());
}
