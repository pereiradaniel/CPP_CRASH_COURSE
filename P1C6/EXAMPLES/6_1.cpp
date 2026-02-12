// Listing 6-1: A template class with three template parameters.
// Template Class Definitions

#include <cstdio>

// MyTemplateClass takes three template parameters: X, Y, and Z.
// It has a member function foo that takes a reference to a Y and returns an X.
// It also has a private member variable that is a pointer to Z.
template<typename X, typename Y, typename Z>
struct MyTemplateClass {
    X foo(Y&);
    private:
    Z* member;
};

int main() {
    // To instantiate a template class, use the following syntax:
    MyTemplateClass<int, double, char> my_concrete_class{};
}

// Notes:
// The template keyword begins the template prefix, which specifies that the following declaration is a template.
// The angle brackets <> enclose the template parameters, which are placeholders for types that will be specified when the template is instantiated.
// The template parameters can be used in the class definition as if they were actual types. For example, in the foo function, Y is used as the type of the parameter, and X is used as the return type.
// The member variable member is a pointer to Z, which means that when the template is instantiated, it will be a pointer to the type specified for Z.