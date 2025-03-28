#include <cstdio>
#include <utility>

void ref_type(int &x) {
    printf("lvalue reference %d\n", x);
}

void ref_type(int &&x) {
    printf("rvalue reference %d\n", x);
}

int main() {
    auto x = 1;

    // std::move changes the lvalue x into an rvalue:
    ref_type(std::move(x));

    ref_type(2);

    ref_type(x+2);
}