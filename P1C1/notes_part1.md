# Part 1 - The C++ Core Language

[*Back to readme.md*](../readme.md)

## Chapter 1 - _Up and Running_

### The Structure of a Basic C++ Program

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
    - Produces a single *translation unit* when finished processing a source file.
    - Each translation unit is passed to the *compiler*.

    Example: The preprocessor includes the cstdio library upon the directive

    ```cpp
        #include <cstdio>.
    ```

2. Compiler
    - Reads a *translation unit* and generates an *object file*.
    - Object file contains *object code*.
    - Each *translation unit* corresponds to a single *object file*.

3. Linker
    - Generates *programs* from *object files*.
    - Finds *libraries* included within the *source code*.
    - The *linker* includes everything needed for *printf()* from the *include* directive for *cstdio*.

### Setting Up Your Development Environment

1. Text editor
2. Compiler tool chain
3. Debugger

#### IDE

When all three are bundled together, this is called an *interactive development environment (IDE)*.

### The C++ Type System

- C++ is an object-oriented language.
- Objects are abstractions with *state* and *behaviour*.
- The collection of *behaviours* and *states* describing an object is called its *type*.
- C++ is a *strongly tpyed language*: Each object has a predefined data type.
- C++ has a built-in integer type (int).
    a. An *int* object stores whole numbers (state).
    b. An *int* object supports math operations (its behaviour).
- Named objects are called *variables*.

#### Declaring variables

Declare variables by providing three things:
    1.  type
    2.  name
    3.  semicolon

```cpp
int var;
```

#### Initializing a Variable's State

Object initialization establishes an object's initial state.

```cpp
int var = 100;
```

Variables can be assigned the results of math equations.

```cpp
int product =  4 * 5;
```

#### Conditional statements

- Allow you to make decisions in your programs.
- Decisions rest on *Boolean expressions*, evaluating to either *true* or *false*.
- Use of *comparison operators* can be used to build *Boolean expressions*.

```cpp
int main() {
    int x = 0;  // initialize int x to 0.
    42 != x     // inequality comparison operator
}
```

An *if* statement contains:

- A *Boolean expression*.
- One or more *nested statements*.

```cpp
if (boolean_expression) statement
```

Description: If the Boolean expression is true, the statements will execute, otherwise none will execute.

```cpp
if (boolean_expression_1) statement_1
else if (boolean_expression_2) statement_2
else statement3
```

Description: boolean_expression_1 is evaluated, if true then statement_1 is executed, and the *if* statement stops executing. If boolean_expression_1 evaluates to false, then boolean_expression_2 is evaluated. In this example, all three statements are mutually exclusive, and cover all possible outcomes of the *if* statement. Only one of the three can be evaluated. If statement_1 or statement_2 both evaluate to false, then statement_3 will run, ensuring that at least one of the three statements has to run.

Any number of *else if* clauses can be used, or it can be omitted entirely. *Else if* clauses are evaluated *in order*, and stops as soon as one of them evaluates to *true*. The *else* clause always executes if no *else if* clause evaluates to *true*. *Else* is also optional.

```cpp
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
```

#### Functions

Blocks of code that accept any number of input objects called *parameters* or *arguments*. and can return output objects to their callers.

---

// Rest of chapter was too basic... moving onto Chapter 2.