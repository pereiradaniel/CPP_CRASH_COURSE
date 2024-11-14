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
- Some C-supported constructs won't work in C++, see: [*C Constructs that Don't Work in C++*](https://lospi.net/c/c++/programming/developing/software/2019/04/28/c-constructs-that-dont-work-in-cpp.html) [notes](#c-constructs-that-don't-work-in-c++)





---

# EXTRAS

## C Constructs that Don't Work in C++

- C++ began life as a fork of C before C was even standardized, C++ compilers can often directly compile C programs.

Three concpets that diverge from C++:
1. Weak pointer typing.
2. *enum* values.
3. Function prototypes without arguemnts.

## Pointer Typing

- C++ regards poitners with stronger typing than C. You can't implicitly convert from _void*_.

A common idiom when using *malloc* is to lean on implicit conversion:

*Example:*

```c
int *value = malloc(sizeof(int) * 100);
```

This code dynamically allocates enough space for 100 *int* objects. *malloc* returns a *void* pointer, which is implicitly cast to an *int* pointer and assigned-to value.

In C++, this is not valid. You can provide an explicit cast, but you must be careful:

```cpp
int *value = (int*)malloc(sizeof(int) * 100);
```

The memory pointed-to by the return value of *malloc* is uninitialized.

You should only do two things with such memory:
1. Deallocate it.
2. Use it as storage for initializing new objects with an in-place *new*.

## Constraint Violations

In older C code, you might find (technically incorrect) constructions like the following:

```c
const int x = 100;
int* x_ptr = &x;
```

This is a constraint violation because you've implicitly shucked off the *const* protections on *x*. Some compilers will let this pass with a warning. C++ will instead produce an error.

In both C and C++, the remedy is to make the cast explicit. In C++ you can either use an explicit C-style cast or use a *const_cast*.

```cpp
int* x_ptr_1 = (int*)&x;                // (1)
int* x_ptr_2 = const_cast<int*>(&x);    // (2)
const int* x_ptr_3 = &x;                // (3)
```

- Apprach 1 is dangerous because it is throwing away the constness of x without being explicitly clear.
- The *const_cast* doesn't get away from the dangerous practice of removing *const* from variables, it clearly documents a dangerous reinterpretation is being used.
- 3 is the preferred approach, which is taking a pointer to a *const int*. This is the safest option, since it preserves the *const* nature of x.

## enum Values

In C, an enum value must always be backed by an *int*, whereas in C++ they can be any C++ *integer types*. C++ has stronger typing requirements than C when handling *enum* values.

*Valid in C:*
```c
enum FooEnum {
    A=0, B, C
};

void enum_cast() {
    int x = A; // (1)
    enum FooEnum foo = 2; // (2)
}
```

Implicit conversions are possible to and from *int* values in C.
- You can convert from a *FooEnum* to an *int (1)*.
- You can also convert from an *int* to a *FooEnum (2)*.
- In C++, the first assignment *(1)* is supported while the second *(2)* is not.
- You can fix rthis by employing either a C-style cast or a *static_cast*:

```cpp
enum FooEnum foo == static_cas<(FooEnum>(2);
```

In this case, a *static_cast* is still a sub-optimal approach from a C++ perspective. It would be better to assign from *FooEnum::c* directly (rather than use ist *int* equivalent, 2).