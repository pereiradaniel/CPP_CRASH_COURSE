// Listing 3-11
#include <cstdio>

int main() {
    int original = 100;
    int& original_ref = original;
    
    printf("Original: %d\n", original);         // Print the value of original.
    printf("Reference: %d\n", original_ref);    // Print value referred to by original, they are the same.

    int new_value = 200;                        // Initialize another int.
    // Assign original_ref to new_value, it assigns the value of new_value to the object it points to.
    original_ref = new_value;

    printf("Original: %d\n", original);         // 200
    printf("New Value: %d\n", new_value);       // 200
    printf("Reference: %d\n", original_ref);    // 200
}