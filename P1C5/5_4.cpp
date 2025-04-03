// Listing 5-4: A program using a derived class in place of a base class.

struct BaseClass {};
struct DerivedClass : BaseClass{};          // DerivedClass derives from BaseClass.
void are_belong_to_us(BaseClass& base) {}   // Takes reference to BaseClass argumnt 'base'.

int main() {
    DerivedClass derived;
    are_belong_to_us(derived);              // Can be invoked with an instance of Derived class. 
}