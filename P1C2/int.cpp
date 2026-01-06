// Uses non-decimal hardcoded integer literal representations
// and outputs them to the screen using printf.
#include <cstdio>
int main() {
    // binary
    unsigned short a = 0b10101010;
    printf("%hu\n", a);
    // octal
    int b = 0123;
    printf("%d\n", b);
    // hexadecimal
    unsigned long long d = 0xFFFFFFF;
    printf("%llu\n",d);
}