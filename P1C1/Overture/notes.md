# An Overture To C Programmers

- Bjarne Stroustup developed C++ from thje C programming language.
- C++ is not completely compatible with C, but well-written C programs are often also valid C++ programs.
- Every example in *The C Programming Language" by Brian Kernighan and Dennis Ritchie is a legal C++ program.
- C allows programmers to write at a higher level of abstraction than assembly programming does. This produces clearer, less error-prone, and more maintainable code.
- *C adheres to the zero-overhead princple:* System programmers are not usually willing to pay overhead for programming convenience. "What you don't use you don't pay for."
- The strong type system is an example of a zero-overhead abstrations. It is only used at compile time to check for program correctness. After compiling, the types will disappeare and the resulting assembly code shows no trace of the type system.
- Being a descendant of C, C++ also takes zero-overhead abstraction and direct mappiong to hardware very seriously.
- Some features of C++ can incur even less overhead than corresponding C code. For example, the *constexpr* keyword. It instructs the compiler to evaluate the expression at compile time, if possible.

constexpr.cpp
```cpp
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
```

## Upgrading to Super C

- Modern C++ compilers accommodate most C programming habits.
- Super c IS *NOT* idiomatic C++.
- In some environments (embedded software, some operating sytem kernels, heterogeneous computing), the available tool chains have incomplete C++ support.
- Some C-supported constructs won't work in C++, see: [*C Constructs that Don't Work in C++*](https://lospi.net/c/c++/programming/developing/software/2019/04/28/c-constructs-that-dont-work-in-cpp.html) notes[#c-constructs-that-don't-work-in-c++]





---

# EXTRAS

## C Constructs that Don't Work in C++