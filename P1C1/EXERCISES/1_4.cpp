// Create a function called absolute_value that returns the absolute value of its single argument. The absolute value of an integer x is the following: x (itself) if x is greater than or equal to 0; otherwise, it is x times -1. You can use the program in listing 1-9 as a template:

#include <cstdio>

int absolute_value(const int x) noexcept {
    // Create variable for result:
    int result = 0;
    
    if (x >= 0)
        result = x;
    else if (x < 0)
        result = x*(-1);
    
    // Return the result:
    return result;
}

// Exercise 1-4: Write another function called sum that takes two in argumenmts and returns their sum. How can you modify the template in Listing 1-9 to test your new function?

int sum(const int x, const int y) noexcept {
    return x+y;
}

int main() {
    int my_num = -10;
    printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));

    // Exercise 1-2: Try running your program with differente values. Did you see what you expect?
    int my_num2 = -50;
    printf("The absolute value of %d is %d.\n", my_num2, absolute_value(my_num2));

    int my_num3 = 75;
    printf("The absolute value of %d is %d.\n", my_num3, absolute_value(my_num3));

    // Exercise 1-4:
    printf("The sum of value %d and %d is %d.\n", my_num, my_num2, sum(my_num, my_num2));
}