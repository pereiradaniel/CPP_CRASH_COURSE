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

- Store human language data.

Six character types:
1. char
2. char16_t
    - Used for 2-byte character sets. ex: UTF-16
3. char32_t
    - Used for 4-byte character sets. ex: UTF-32
4. signed char
    - Same as char but guaranteed signed.
5. unsigned char
    - Same as char but guaranteed unsigned.
6. wchar_t
    - Large enough to contain largest character of the implementation's locale.

*narrow characters* - char, signed char, unsigned char.
*wide characters* - char16_t. char32_t, wchar_t.

##### Character Literals

- Single, constant character.
- Single quotation marks.
- All char types other than just char must also have a prefix:
    - L for wchar_t
    - u for char16_t
    - U for char32_t

##### Escape Sequences

\n - newline
\t - horiz tab
\v - vert tab
\b - backspace
\r - carriage return
\f - form feed
\a - alert
\\ - backslash
? or \? - question mark
\' - single quote
\" - double quote
\0 - the null character

##### Unicode Escape Characters

Universal character names can be used:

```
\u0041
```

\u followed by four-digit code.

##### Format Specifierse

printf format specifier for char: %c, wchar_t: %lc

```cpp
// Initializes two character literals and
// uses them in a printf() call:
#include <cstdio>
int main() {
    char    x = 'M';
    wchar_t y = L'Z'; // Note: Format specifier L.
    printf("Windows binaries start with %c%lc.\n",x,y);  
    return 0;
}
```
file: [charformatspecifier.cpp](./charformatspecifier.cpp)

#### *Boolean Types*

- Have two states: _true_ and _false_.
- *bool* and *integer* types can convert.
    - _true_ converts to 1, and _false_ converts to 0.
    - any non-zero integer converts to _true_, and 0 converts to _false_.

##### Boolean Literals

Two:
1. true
2. false

##### Format Specifiers

- No format specifier for bool.
- Can use %d int specifier to output 0 for false or 1 for true.
*Reason:* _printf()_ promotes any integral value smaller than an _int_ to an _int_.

```cpp
// Illustrates declaration of a Boolean and
// how to inspect its value:
#include <cstdio>
int main() {
    bool b1 = true;
    bool b2 = false;
    printf("%d%d\n",b1,b2);
    return 0;
}
```
file: [boolformatspecifier.cpp](./boolformatspecifier.cpp)