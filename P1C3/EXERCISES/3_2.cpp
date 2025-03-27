// Exercise 3-2: Add a read_from and a write_to function to Listing 3-6. These functions should read or write to upper or lower as appropriate. Perform bounds checking to prevent buffer overflows.

#include <cstdio>

void read_from(const char* array, const int &index) noexcept {
    if (index <= (sizeof(array) / sizeof(char)) && index >= 0)
        printf("\nChar at index %d is %c.", index, array[index]);
    else printf("\nOut of bounds!\n");
}

void write_to(char* array, const int &index, const char &character) noexcept {
    if (index <= (sizeof(array) / sizeof(char)) && index >= 0)
        array[index] = character;
    else printf("\nOut of bounds!\n");
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

    printf("lower: %s\nupper: %s", lower, upper);
    // End of Listing 3-6

    // Demonstrate functions added to Listing 3-6:
    read_from(lower, 3);
    
    write_to(upper, 2, 'X');
    printf("\n%s\n", upper);
}
