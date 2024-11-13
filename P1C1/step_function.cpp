#include <cstdio>
#include <iostream>

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
    int value1 = step_function(100);  // value1 =  1
    int value2 = step_function(0);    // value2 =  0
    int value3 = step_function(-100); // value3 = -1
    std::cout << value1 << " " << value2 << " " << value3 << std::endl;
}