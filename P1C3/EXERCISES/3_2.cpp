// Exercise 3-2: Add a read_from and a write_to function to Listing 3-6. These functions should read or write to upper or lower as appropriate. Perform bounds checking to prevent buffer overflows.

#include <cstdio>

// Function checks bounds and returns true if within bounds, otherwise false:
bool check_bounds(const char* array, const int &index) noexcept {
    bool result;
    if (index <= (sizeof(array) / sizeof(char)) && index >= 0)
        result = true;
    else result = false;
    return result;
}

// Prints out of bounds message when overflow is detected by functions:
void out_of_bounds() noexcept {
    printf("Out of bounds!\n");
}

// Reads char from array at given index:
void read_from(const char* array, const int &index) noexcept {
    if (check_bounds(array, index))
        printf("Char at index %d is %c.\n", index, array[index]);
    else out_of_bounds();
}

// Writes char to array at given index:
void write_to(char* array, const int &index, const char &character) noexcept {
    if (check_bounds(array, index))
        array[index] = character;
    else out_of_bounds();
}

int main() {
    // Listing 3-6 begins:
    char lower[] = "abc?e";
    char upper[] = "ABC?E";
    char* upper_ptr = upper; // Equivalent: &upper[0]

    lower[3] = 'd'; // lower now contains a b c d e \0
    upper_ptr[3] = 'D'; // upper now contains A B C D E \0

    char letter_d = lower[3]; // letter_d equals 'd'
    char letter_D = upper_ptr[3]; // letter_D equals 'D'

    printf("lower: %s\nupper: %s\n", lower, upper);
    // End of Listing 3-6

    // Demonstrate functions added to Listing 3-6:
    read_from(lower, 3);        // Should pass.
    read_from(lower, 10);       // Should cause "Out of bounds!" error.
    
    write_to(upper, 2, 'X');    // Should pass.
    printf("%s\n", upper);      // Display array after being modified.
    write_to(upper, 10, 'Z');   // Should cause "Out of bounds!" error.
}
