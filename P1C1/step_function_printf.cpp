// printf function is a derivative of the writef function from BCPL.
// Implement step_function.cpp using printf
#include <cstdio>

int step_function(int x)
{
    int result = 0;
 
    if (x<0)
        result = -1; 
    else if (x>0)
        result = 1;

    return result;
}

int main()
{
    int num1 = 100;
    int num2 = 0;
    int num3 = -100;
    int value1 = step_function(num1);  // value1 =  1
    int value2 = step_function(num2);    // value2 =  0
    int value3 = step_function(num3); // value3 = -1
    printf("num1: %d, value1: %d\nnum2: %d, value2: %d\nnum3: %d, value3: %d\n", num1, value1, num2, value2, num3, value3);
}