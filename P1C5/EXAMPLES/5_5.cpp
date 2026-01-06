// Listing 5-5: This program attempts to use a base class in place of a derived class. (This listing won't compile when line 9 is uncommented.)

struct BaseClass {};
struct DerivedClass : BaseClass {};             // BaseClass doesn't derive from DerivedClass.
void all_about_that(DerivedClass& derived) {}   // Function taks DerivedClass argument.

int main() {
    BaseClass base;
    // all_about_that(base);                    // Invoking function yields compiler error, because inheritance is the other way around.
}