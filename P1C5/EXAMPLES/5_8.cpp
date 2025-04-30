// Listing 5-8: A refactor of 5-7 using a pure virtual method.

#include <cstdio>

struct BaseClass {
    // =0 suffix specifies a pure virtual method:
    virtual const char* final_message() const = 0;
};

// DerivedClass still derives from BaseClass:
struct DerivedClass : BaseClass {
    // Provide the requisite final_message:
    const char* final_message() const override {
    return "We apologise for the inconvenience.";
  }
};

int main() {
    // Attempting to instantiate a BaseClass results in compiler error:
    // BaseClass base; // Bang!
    DerivedClass derived;
    BaseClass& ref = derived;
  
    // Both DerivedClass and BaseClass reference behave as before in Listing 5-7:
    printf("DerivedClass: %s\n", derived.final_message());
    printf("BaseClass&:   %s\n", ref.final_message());
}
