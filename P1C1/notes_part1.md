# Part 1 - The C++ Core Language
(*Back to readme.md*)[~/readme.md]
## Chapter 1 - _Up and Running_

### The Structure of a Basic C++ Program:

```cpp
#include <cstdio>   // cstdio library (printf)

int main() {        // C++ programs have a single entry point called main()
    printf("Hello, world");
    return 0;       // Optional. Exit code defaults to 0.
}
```

### Libraries: Pulling in External Code

- Helpful code collections that can be imported into programs.

### The Compiler Tool Chain

*Compiler tool chain:* Collection of three elemetns that run one after the other to convert source code into a program.

1. Preprocessor
    - Performs basic source code manipulation.
    - Produces a single translation unit when finished processing a source file.
    - Each translation unit is passed to the compiler.
2. Compiler
    - Reads a translation unit.
    - Generates an object file.
    - Object file contains *object code*.
3. Linker
    - Generates programs from object files.
    - Finds libraries included within the source code.
    - #include <cstdio> - The linker includes everything needed for *printf()* from the previous example.

### Setting Up Your Development Environment

1. Text editor
2. Compiler tool chain
3. Debugger

#### IDE:
When all three are bundled together, this is called an *interactive development environment (IDE)*.

### The C++ Type System

- C++ is an object-oriented language.
- Objects are abstractions with state and behaviour.
- The collection of behaviours and states describing an object is called its *type*.
- C++ is a *strongly tpyed language:* Each object has a predefined data type.
- C++ has a built-in integer type (int).
    a. An *int* object stores whole numbers (state).
    b. An *int* object supports math operations (its behaviour).
- Named objects are called variables.

#### Declaring variables

Declare variables by providing their type, name, and a semicolon.

```cpp
int var;
```

#### Initializing a Variable's State

Object initialization establishes an object's initial state.

```cpp
int var = 100;
```

#### Conditional statements

Allow you to make decisions in your programs.

```cpp
int main() {
    int x = 0;
    42 != x // inequality
}
```

```cpp
if (boolean_expression) statement_1
else if (boolean_expression_2) statement_2
else statement3
```

#### Functions

Blocks of code that accept any number of input objects called *parameters* or *arguments*. and can return output objects to their callers.

---

// Rest of chapter was too basic... moving onto Chapter 2.