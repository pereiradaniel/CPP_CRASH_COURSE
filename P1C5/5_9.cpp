// Listing 5-9: An example illustrating the dangers of non-virtual destructors in base classes.

#include <cstdio>

struct BaseClass {};

// DerivedClass is derived from BaseClass:
struct DerivedClass : BaseClass {
    // DerivedClass has a constructor:
    DerivedClass() {
        printf("DerivedClass() invoked.\n");
    }
    // DerivedClass has a destructor:
    ~DerivedClass() {
        printf("~DerivedClass() invoked.\n");
    }
};

int main() {
  printf("Constructing DerivedClass x.\n");
  
  // Allocate and initialize a DerivedClass with new and set the result to a BaseClass pointer:
  BaseClass* x{ new DerivedClass{} };
  printf("Deleting x as a BaseClass*.\n");
  
  // When pointer is deleted, the BaseClass destructor gets invoked, but DerivedClass destructor doesn't!
  delete x;
}
