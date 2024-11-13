// Create a function called absolute_value that returns the absolute value of its single argument.
// The absolute value of an integer x is x if it is greater than or equal to 0, otherwise it is
// x = x * (-1)

#include <cstdio>

int absolute_value(int x)
{
    int result = 0;
    if (x >= 0)
    {
        result = x;
    }
    else if (x < 0)
    {
        result = x*(-1);
    }
    return result;
}

// Write another function called sum that takes two int arguments and returns their sum.
int sum(int x, int y)
{
    return x+y;
}

int main()
{
    int my_num  = -10;
    int my_num2 = 15;

    printf("The asbolute value of %d is %d.\n", my_num, absolute_value(my_num));
    printf("The asbolute value of %d is %d.\n", my_num2, absolute_value(my_num2));
    
    printf("The sum of value %d and %d is %d.\n", my_num, my_num2, sum(my_num, my_num2));
    
    int a[] = {-2,5,-8,3,0};
    int length = sizeof(a) / sizeof(a[0]);

    for (int i=0; i < length; ++i)
        printf("The absolute value of %d is %d.\n", a[i], absolute_value(a[i]));

    return 0;
}
