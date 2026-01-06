#include <cstdio>
int main(int argc, char* argv[])
{
    // Declare x and initialize to 0:
    int x =0;
    
    // The first boolean expression should evaluate to false:
    if (x > 0)
        printf("Positive!");
    // Because the first boolean expression does not evaluate to true,
    // the second boolean expression is evaluated, also to false:
    else if (x < 0)
        printf("Negative!");
    // Finally, since all previous boolean expressions failed to evalute
    // to true, the "else" clause will run it's statement:
    else
        printf("Zero");
    
    // End program:
    return 0;
}