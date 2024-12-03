// Illustrates that references cannot be reseated:
#include <cstdio>
int main() {
    int original = 100;
    // Declares a reference to original called original_ref:
    int& original_ref = original;

    printf("Original: %d\n", original);
    printf("Reference: %d\n", original_ref);

    // Initializes an int called new_value and assigns original to it:
    int new_value = 200;
    // Assigns the value of new_value to the object it points to:
    original_ref = new_value;
    
    printf("Original: %d\n", original);
    printf("New Value: %d\n", new_value);
    printf("Reference: %d\n", original_ref);
}