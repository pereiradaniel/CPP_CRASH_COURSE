# Part 1 - The C++ Core Language

[*Back to readme.md*](../readme.md)

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

##### Comparison Operators

- Functions that perform computations on *operands*.
- Operands are objects.

```cpp
// Uses comparison operators to produce Booleans:
#include <cstdio>
int main() {
    printf(" 7 ==  7: %d\n",  7== 7);
    printf(" 7 !=  7: %d\n",  7!= 7);
    printf("10 >  20: %d\n", 10> 20);
    printf("10 >= 20: %d\n", 10>=20);
    printf("10 <  20: %d\n", 10< 20);
    printf("20 <= 20: %d\n", 20<=20);
    return 0;
}
```
file: [comparisonoperators.cpp](./comparisonoperators.cpp)

#### *Logical Operators*

- Evaluate Boolean logic on _bool_ types.

*unary operator:* Single operand.
*binary operator:* Two operands.
*ternary operator:* Three operands.

```cpp
// Uses logical operators:
#include<cstdio>
int main() {
    bool t = true;
    bool f = false;
    printf("!true: %d\n", !t);
    printf("true && false: %d\n", t && f);
    printf("true && !false: %d\n", t && !f);
    printf("true || false: %d\n", t || f);
    printf("false || false: %d\n", f || f);
    return 0;
}
```
file: [logicaloperators.cpp](./logicaloperators.cpp)

#### *std:byte Type*

- *raw memory:* Collection of bits without a type.
- Use _std::byte_ to use this memory.
- _std::byte_ is available from <cstddef>
- Permits bitwise logical operations.

#### *size_t Type*

- Use from <cstddef> to encode the size of objects.
- *size_t* objects guarantee that their maximum values are sufficient to represent the maximum size in bytes of all objects.

##### sizeof

- unary operator
- takes a type operand and returns the size of that type in bytes: sizeof(float)

##### Format Specifiers

size_t:
- %zu for decimal representation.
- %zx for hexadecimal representation.

*Note:* Windows and Linux/Mac have different sizes for long!

```cpp
// Check system's integer type sizes:
#include <cstddef>
#include <cstdio>
int main() {
    size_t size_c = sizeof(char);
    printf("char: %zu\n", size_c);
    
    size_t size_s = sizeof(short);
    printf("short: %zu\n", size_s);
    
    size_t size_i = sizeof(int);
    printf("int: %zu\n", size_i);

    size_t size_l = sizeof(long);
    printf("long: %zu\n", size_l);

    size_t size_ll = sizeof(longlong);
    printf("long long: %zu\n", size_ll);
    return 0;
}

// Compiled on Windows:
///////////////////////

// Microsoft (R) C/C++ Optimizing Compiler Version 19.35.32215 for x86
// Copyright (C) Micosoft Corporation.  All rights reserved.
//
// checkinttypesizes.cpp
// Microsoft (R) Incremental Linker Version 14.35.32215.0
// Copyright (C) Microsoft Corporation.  All rights reserved.

// /out:checkinttypesizes.exe
// checkinttypesizes.obj

// C:\Users\perei\source\repos\cpp_crash_course\P1C2>checkinttypesizes.exe
// char: 1
// short: 2
// int: 4
// long: 4
// long long: 8

// Compiled on Linux:
/////////////////////

// pereira@DESKTOP-HFSS3GK:/mnt/c/Users/perei/source/repos/cpp_crash_course/P1C2$ g++ -g checkinttypesizes.cpp -o checkinttypesizes
// pereira@DESKTOP-HFSS3GK:/mnt/c/Users/perei/source/repos/cpp_crash_course/P1C2$ ./checkinttypesizes
// char: 1
// short: 2
// int: 4
// long: 8
// long long: 8
```
file: [checkinttypesizes.cpp](./checkinttypesizes.cpp)

#### *void*

- empty set of values
- cannot hold a void
- C++ disallows void objects
- *void* is used in special situations (functions that do not return a value)

### Arrays

- Sequences of identically typed variables.

*Declaration syntax:*

```cpp
int my_array[100];
```

#### *Array Initialization*

Shortcut:

```cpp
// Length of array can be omitted:
int array[] = {1, 2, 3, 4};
```

#### *Accessing Array Elements*

Use square brackets to enclosed the desierd index:

```cpp
// Reads and writes array elements:
#include <cstdio>
int main() {
    int arr[] = {1, 2, 3, 4};
    printf("Third element of arr[]: %d\n", arr[2]);
    arr[2] = 100; // Writes to the third element of array arr[]
    printf("Third element of arr[] has been updated: %d\n", arr[2]);
    return 0;
}
```
file: [readandwritearrayelements.cpp](./readandwritearrayelements.cpp)

#### *For Loops*

- Repeats the execution of a statement for a specified number of times.

```
for(init statement; conditional; iteration statement)
{
    ...
}
```

```cpp
// Uses for loop to find the maximum value of an array:
#include <cstddef>
#include <cstdio>
int main() {
    unsigned long maximum = 0;
    unsigned long values[] = {10,50,20,40,0};

    for(size_t i=0; i < 5; ++i)
    {
        if (values[i] > maximum) maximum = values[i];
    }

    printf("The maximum value is %lu", maximum);
}
```

file: [maxarray.cpp](./maxarray.cpp)

##### Range-Based for Loop

```
for(element-type; element-name; array-name)
{
    ...
}
```

```cpp
// maxarray.cpp refactored with range-based for loop
#include <cstdio>
int main() {
    unsigned long maximum = 0;
    unsigned long values[] = {10,50,20,40,0};
    
    for(unsigned long value : values)
        if(value > maximum) maximum = value;

    printf("The maximum value is %lu", maximum);
}
```

file: [rangebasedmaxarray.cpp](./rangebasedmaxarray.cpp)

##### Number of Elements in an Array

- *sizeof* obtains the total size in bytes of the array.

```cpp
short array[] = {5,10,15};
size_t n_elements = sizeof(array) / sizeof(short);
```

#### *C-Style Strings*

- c-style string or null-terminated string has a zero-byte appended.
- Strings are contiguous blocks of chararcters.
- Strings can be stored in arrays of character types.

##### String Literals

- Strings are declared by enclosing text in quotes.
- The format strings of printf statements are string literals.

##### Format Specifier

- For narrow strings (char*): %s

```cpp
#include <stdio>
int main() {
    char house[] = "a house of gold";
    printf("A book holds %s\n", house);

}
```
file: [c_string.c](./c_string.c)

```c
#include <stdio.h>
int main(int argv, char* argc[]) {
    char house[] = "a house of gold";
    printf("A book holds %s\n", house);
    return 0;
}
```
file: [c_string.cpp](./c_string.cpp)

#### *User-Defined Types*

- Types the user can define.

Three main categories of user-defined types:

1. Enumerations
- Simplest.
- Restricted to a set of possible values.
- Good for modeling categorical concepts.

2. Classes
- Flexibility to pair data and functions.
- Data-classes only hold data.

3. Union
- All members share the same memory location.
- Dangerous and easy to misuse.

##### Enumeration Types

- Declared using *enum class*.

```cpp
enum class F1Team {
    Alpine,
    AstonMartin,
    Ferrari,
    Haas,
    KickSauber,
    McLaren,
    Mercedes,
    VCaRB,
    RedBullRacing,
    Williams
}
```

Initialize an enumeration variable to a value:

```cpp
F1Team ferrari = F1Team::Ferrari;
```

##### Switch Statements

```cpp
// Uses an enum class with a switch statement:
#include <cstdio>
enum class F1Team {
        Alpine,
        AstonMartin,
        Ferrari,
        Haas,
        KickSauber,
        McLaren,
        Mercedes,
        VCaRB,
        RedBullRacing,
        Williams
    };

int main() {
    F1Team myTeam = F1Team::Ferrari;

    switch (myTeam) {
        case F1Team::Alpine:
            printf("Alpine");
            break;
        case F1Team::AstonMartin:
            printf("Aston Martin");
            break;
        case F1Team::Ferrari:
            printf("Ferrari");
            break;
        case F1Team::Haas:
            printf("Haas");
            break;
        case F1Team::KickSauber:
            printf("Kick Sauber");
            break;
        case F1Team::McLaren:
            printf("McLaren");
            break;
        case F1Team::Mercedes:
            printf("Mercedes");
            break;
        case F1Team::VCaRB:
            printf("Visa Cash App Red Bull");
            break;
        case F1Team::RedBullRacing:
            printf("Red Bull Racing");
            break;
        case F1Team::Williams:
            printf("Williams");
            break;
    }
}
```
File:[enum_class.cpp](./enum_class.cpp)

#### *Plain-Old-Data Classes*

```cpp
struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
};
```

```cpp
#include <cstdio>

struct Book {
    char name[256];
    int year;
    int pages;
    bool harcover;
};

int main() {
    Book lotr;
    lotr.pages = 2000;
    printf("The Lord Of The Rings has %d pages.", lotr.pages);
}
```
File: [data_struct.cpp](./data_struct.cpp)

```c
#include <stdio.h>

struct Book {
    char name[256];
    int year;
    int pages;
    // bool harcover;
    int hardcover; // 0 false, 1 true
};

int main(int argc, char* argv[]) {
    struct Book lotr;
    lotr.pages = 2000;
    printf("The Lord Of The Rings has %d pages.", lotr.pages);
    return 0;
}
```
File: [data_struct.c](./data_struct.c)

#### *Unions*

- Can be thought of as adifferent views or interpretations of a block of memory.
- Useful iun some low-level situations.

```cpp
union Variant {
    char string[10];
    int integer;
    double floating_point;
}
```

```c
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
 
int main(void)
{
    union S
    {
        uint32_t u32;
        uint16_t u16[2];
        uint8_t  u8;
    } s = {0x12345678}; // s.u32 is now the active member
    printf("Union S has size %zu and holds %x\n", sizeof s, s.u32);
    s.u16[0] = 0x0011;  // s.u16 is now the active member
    // reading from s.u32 or from s.u8 reinterprets the object representation
    //  printf("s.u8 is now %x\n", s.u8); // unspecified, typically 11 or 00
    //  printf("s.u32 is now %x\n", s.u32); // unspecified, typically 12340011 or 00115678
 
    // pointers to all members of a union compare equal to themselves and the union
    assert((uint8_t*)&s == &s.u8);
 
    // this union has 3 bytes of trailing padding
    union pad
    {
       char  c[5];   // occupies 5 bytes
       float f;      // occupies 4 bytes, imposes alignment 4
    } p = {.f = 1.23}; // the size is 8 to satisfy float's alignment
    printf("size of union of char[5] and float is %zu\n", sizeof p);
}
```
Source: [devdocs.io/c/language/union](https://devdocs.io/c/language/union)

### Fully Featured C++ Classes

- Encapsulation is achieved by adding methods and access controls to class definitions.

#### *Methods*

- Member functions.

```cpp
#include <cstdio>

struct F1Points {
    int total_points;
    
    int first = 25;
    int second = 18;
    int third = 15;
    int fourth = 12;
    int fifth = 10;
    int sixth = 8;
    int seventh = 6;
    int eighth = 4;
    int ninth = 2;
    int tenth = 1;

    void feature_race_points(int position) {
        if (position == 1)
            total_points += first;
        if (position == 2)
            total_points += second;
        if (position == 3)
            total_points += third;
        if (position == 4)
            total_points += fourth;
        if (position == 5)
            total_points += fifth;
        if (position == 6)
            total_points += sixth;
        if (position == 7)
            total_points += seventh;
        if (position == 8)
            total_points += eigth;
        if (position == 9)
            total_points += ninth;
        if (position == 10)
            total_points += tenth;
        }
    }

int main() {
    F1Points verstappen;
    
    // Add 1st place finish points to list:
    for (int i = 0; int i <= 3; ++i)
        verstappen.feature_race_points(1);
}

```

#### *Access Controls*

- Restrict class-member access.

See -> File [f1points.cpp](./f1points.cpp) for private and public member functions.

#### *Constructors*

