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

- '*' is a unary operator that accesses the object tot which a pointer refers.
- Inverse of the '&' operator.

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

File: [ptr_decay.cpp](./ptr_decay.cpp)

##### Handling Decay

- Pass arrays as two arguments:
    1. A pointer to the frist array element.
    2. Array's length.

File: [ptr_decay2.cpp](./ptr_decay2.cpp)

##### Pointer Arithmetic

*First Option*
Obtain with [] brackets and then use the address-of operator:

```cpp
College* third_college_ptr == &oxford[2];
```

*Second Option*
Pointer arithmetic:

```cpp
College* third_college+ptr = oxford + 2;
```

#### *nullptr and Boolean Expressions*

- nullptr doesn't point to anything.
- Pointers implicitly convert to true if value is other than nullptr, whereas nullptr converts to false.

##### References
- Safer, more convenient versions of pointers.
- Declared with the & operator.

File: [reference.cpp](./reference.cpp)
