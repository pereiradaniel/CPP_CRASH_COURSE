//  Listing 5-10: A refactor of Listing 5-9 with a virtual destructor.

#include <cstdio>

struct BaseClass {
    // Adding the virtual destructor causes the DerivedClass destructor to get invoked when you delete the BaseClass pointer:
    virtual ~BaseClass() = default;
};

struct DerivedClass : BaseClass {
  DerivedClass() {
    printf("DerivedClass() invoked.\n");
  }
  ~DerivedClass() {
    // Derived Class destructor prints this message when invoked:
    printf("~DerivedClass() invoked.\n");
  }
};

int main() {
    printf("Constructing DerivedClass x.\n");
    BaseClass* x{ new DerivedClass{} };
    printf("Deleting x as a BaseClass*.\n");
    // Delete the BaseClass pointer.
    delete x;
}
