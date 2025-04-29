// Listing 5-6: A program using inherited members.

#include <cstdio>

struct BaseClass {
    // Base class has a public method:
    int the_answer() const { return 42; }
    // Base class has a public field:
    const char* member = "gold";
private:
    // Base class has a private member:
    const char* holistic_detective = "Dirk Gently";
};

// A derived class is declared, which inherits from BaseClass:
struct DerivedClass : BaseClass {
    void announce_agency() {
        // This line doesn't compile:
        // Compiler error because holistic_detective is a private member:
        // printf("%s's Holistic Detective Agency\n", holistic_detective); {
    }
};

int main() {
    DerivedClass x;
    // x inherits from BaseClass, so .the_answer() and member are available as public members:
    printf("The answer is %d\n", x.the_answer());
    printf("%s member\n", x.member);
}
