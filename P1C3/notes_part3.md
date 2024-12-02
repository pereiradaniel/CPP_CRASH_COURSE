# Part 1 - The C++ Core Language

[*Back to readme.md*](../readme.md)

## Chapter 2 - _Reference Types_

### Pointers

- Fundamental mechanism used to refer to memory addresses.
- Encode both pieces of information required to interact with another object:
    1. The object's address.
    2. The objet's type.

#### *Addressing Variables*

- Obtain the address of a variable be prepending with &.

File: [get_address_of_int.cpp](./get_address_of_int.cpp)

#### *Dereferencing Pointers*

- * is a unary operator that accesses the object tot which a pointer refers.
- Inverse of the & operator.