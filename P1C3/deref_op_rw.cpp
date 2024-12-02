// Uses the dereference operator to read and write.

#include <cstdio>
int main() {
    // initializes variable to 0:
    int variable{};
    
    // initializes pointer variable_address to the address of variable:
    int* variable_address = &variable;

    // prints the int pointed to by variable address:
    printf("Value at variable_address: %d\n", *variable_address);
    // prints the value of variable_address:
    printf("Variable address: %p\n", variable_address);

    // writes a value into the memory pointed to by variable_address:
    *variable_address = 12345;

    // prints the int pointed to by variable address:
    printf("Value at variable_address: %d\n", *variable_address);
    // prints the value of variable_address:
    printf("Variable address: %p\n", variable_address);
}