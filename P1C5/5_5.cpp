// Listing 5-5: This program attempts to use a bse classin place of a derived class. (This listing won't compile.)

struct BaseClass {};
struct DerivedClass : BaseClass {};             // BaseClass does't deriv from DerivedClass.
void all_about_that(DerivedClass& derived) {}   // Function taks DerivedClass argument.

int main() {
    BaseClass base;
    all_about_that(base);                         // Invoking function yields compiler error.
}