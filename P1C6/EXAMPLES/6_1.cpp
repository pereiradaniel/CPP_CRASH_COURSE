// Listing 6-1: A template class with three template parameters.
// Template Class Definitions

#include <cstdio>

template<typename X, typename Y, typename Z>
struct MyTemplateClass {
    X foo(Y&);
    private:
    Z* member;
};

int main() {
    
}