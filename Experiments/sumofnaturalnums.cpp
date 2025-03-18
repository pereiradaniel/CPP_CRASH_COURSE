// Calculates and prints to screen the sum of the
// firt five natural numbers.
#include <iostream>
int main()
{
    int count, sum;
    sum = 0;        // initialize sum with 0

    for (count = 1; count <=5; ++count)
        sum = sum+count;
    
    std::cout<<"Sum of 1st 5 numbers is: " <<sum << "\n";
    
    return 0;
}