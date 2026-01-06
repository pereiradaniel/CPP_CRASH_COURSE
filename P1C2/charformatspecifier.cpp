// Initializes two character literals and
// uses them in a printf() call:
#include <cstdio>
int main() {
    char    x = 'M';
    wchar_t y = L'Z'; // Note: Format specifier L.
    printf("Windows binaries start with %c%lc.\n",x,y);  
    return 0;
}