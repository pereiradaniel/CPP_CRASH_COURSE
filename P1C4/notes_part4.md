# Part 1 - The C++ Core Language

[*Back to readme.md*](../readme.md)

## Chapter 4 - _The Object Life Cycle_

### An Object's Storage Duration

#### *Allocation, Deallocation, and Lifetime*

- Allocation: Reserving storage for objects.
- Deallocation: Releasing an object's storage when the object is no longer needed.
- Storage duration: Begins when object is allocated, ends when deallocated.
- Lifetime: A runtime property bound by the object's storage duration.

Object Life Stages
1. Storage duration begins when storage is allocated.
2. Object's constructor is called.
3. Object's lifetime begins.
4. Object can be used in program.
5. Object's lifetime ends.
6. Object's destructor is called.
7. Object's storage duration ends, storage is deallocated.

#### *Automatic Storage Duration*

- Automatic object: Allocated at the beginning of enclosing code block, deallocated at the end (scope).
- Automatic storage duration.

#### *Static Storage Duration*

- Static object: Declared using the _static_ or _extern_ keyword.
- Static objects with global scope have static storage duration.

File: [storage_duration.cpp](./storage_duration.cpp)