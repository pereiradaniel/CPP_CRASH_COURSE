// Overloading a function that accepts either an lvalue or an rvalue paramter:

#include <cstdio>
void ref_type(int &x) {
    printf("lvalue reference %d\n", x);
}

void ref_type(int &&x) {
    printf("rvalue reference %d\n", x);
}

int main() {
    auto x = 1;

    // x is an lvalue because it has a name:
    ref_type(x);

    // 2 is an rvalue because it is an integer literal without a name:
    ref_type(2);

    // The result of adding x and 2 is not bound to a name, so it's an rvalue:
    ref_type(x+2);
}