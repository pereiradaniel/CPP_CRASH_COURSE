#include<cstdio>

int main() {
    // declare and initialize a float
    float x = 0.521F;
    // declare and initialize a double
    double y = 1.525;
    
    // displays a float with decimal digits
    printf("%f\n", x);
    // displays the same number in scientific notation
    printf("%e\n", x);

    // displays a double with decimal digits
    printf("%lf\n", y);
    // displays a double in scientific notation
    printf("%le\n", y);
}