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
    ref_type(x);
    ref_type(2);
    ref_type(x+2);
}