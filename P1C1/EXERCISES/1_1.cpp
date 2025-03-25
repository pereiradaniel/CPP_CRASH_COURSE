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

int main() {
    int my_num = -10;
    printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));

    int my_num2 = -50;
    printf("The absolute value of %d is %d.\n", my_num2, absolute_value(my_num2));
}