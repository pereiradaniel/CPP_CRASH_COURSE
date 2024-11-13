#include <cstdio>

// isqrt function computes the square root of the argument n
// starting at 1 the cunction increments the local variable i until i*i is greater than or equal to n. If i*i==n it returns i, otherwise it returns i-1.
// isqrt has a literal value, so the compiler could theoretically compute the result for you. The result will only ever take on one value.
constexpr int isqrt(int n) {
    int i=1;
    while (i*i<n) ++i;
    return i-(i*i!=n);
}

int main() {
    constexpr int x = isqrt(1764);
    printf("%d", x);
}