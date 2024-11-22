# Part 1 - The C++ Core Language

## Chapter 2 - _Types_

- A type declares how an object will be interpreted and used by the compiler.
- Every C++ object has a type.

### Fundamental Types

The most basic types of object:
1. integer
2. floating-point
3. character
4. boolean
5. byte
6. size_t
7. void

Fundamental types...
- Try to map a direct relationship from C++ to computer hardware.
- Simplify writing cross-platform code.

#### *Integer Types*

- Store whole numbers.

Four types based on size:

1. short int
2. int
3. long int
4. long long int

- Any can be _signed_ (positive value only), or _unsigned_ (can be a negative value).
- Integer types are signed and *int* by default: short, long and long long can be used instead of short int, etc.

Integer Type Size Variation across platform:
- 64-bit Windows and Linux/Mac have different sizes for a long integer (4 and 8).
- Compiler will usually warn of mismatch between format specifier and integer type.
- Ensure that format specifiers are correct in printf statements.

Enforce Guaranteed Integer Sizes:
- Use integer types in the <cstdint> library.
- int8_t, int_16t, int32_t, int64_t.

a *literal* is a hardcoded value in a program.

Four hardcoded *integer literal* representations:
1. *binary* - use prefix 0b
2. *octal* - uses the prefix 0
3. *decimal* - default
4. *hexadecimal* - 0x

> Integer literals can contain any number of single quotes for readability, these are ignored by the compiler.
> 1'000'000 = 1000000

An unsigned integer can be printed in its hexadecimal or octal representations:
- %x
- %o

##### Examples:

- [int.cpp](./int.cpp)
- [nondecimal.cpp](./nondecimal.cpp)

#### *F
loating-Point Types*

- Store approximations of real numbers (any number with a decimal and fractional part).
- It is not possible to represent an arbitrary real number in computer memory, only an approximation.
- Take up a finite amount of memory (*precision*).
- More precision is more accurate at approximating a real number.

##### Three Levels of Precision in C++

1. *float* - single precision
2. *double* - double precision
3. *long double* - extended precision

##### Floating-Point Literals

- Double precision by default.

##### Floating-Point Format Specifiers

```cpp
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
```
file: [floatformatspecifiers](./floatformatspecifiers.cpp)

#### *Character Types*

#### *Logical Operators*

#### *Format Specifiers*

#### *Arrays*

### *User-Defined Types*