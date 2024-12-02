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

File: [deref_op_rw.cpp](./deref_op_rw.cpp)

#### *The Member-of-Pointer Operator*

- Performs two simultaneous operations:
    1. Dereferences a pointer.
    2. Accesses a member of the pointed-to object.

File: [f1points.cpp](../P1C2/f1points.cpp)

#### *Pointers and Arrays*

- Pointers encode object location.
- Arrays encode the location and length of contiguous objects.

*Decay*
- An array can decay into a pointer.
- Decayed arrays lose their length information and converts the arrays first element to a pointer.

File: (ptr_decay.cpp)[./ptr_decay.cpp]