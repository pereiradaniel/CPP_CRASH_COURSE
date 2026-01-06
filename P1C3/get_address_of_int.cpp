#include <cstdio>
int main() {
    int variable{};
    printf("Value of variable: %d\n", variable);
    int *variable_address = &variable;
    printf("Address of variable: %p\n", variable_address);
}