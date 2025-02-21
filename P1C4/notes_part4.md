# Part 1 - The C++ Core Language

[*Back to readme.md*](../readme.md)

## Chapter 4 - The Object Life Cycle

### An Object's Storage Duration

An object is a region of storage that has a type and a value.

When you declare a variable, an object is created.

A variable is an object with a name.

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

- Static object: Declared using the *static* or *extern* keyword.
- Static objects with global scope have static storage duration.

File: [storage_duration.cpp](./storage_duration.cpp)

### Local Static Variables

- Special kind of static variable.
- Declared at function scope.
- Lifetime:
  - Begins on first invocation of the enclosing function.
  - Ends when the program exits.
- Encapsulation.

### Static Members

- Members of a class not associated with a aprticular instance of the class.
- Static members must be initialized at global, not class scope.

File: [storage_duration.cpp](./storage_duration.cpp)

#### *Thread-Local Storage Duration*

- Each program has one or more threads that can perform independent operations.

*Thread of execution:* The sequence of instructions executed by a thread.

File: [rat.cpp](./rat.cpp)

#### *Dynamic Storage Duration*

- Objects with dynamic storage duration are allocated and deallocated on request.
- aka: allocated objects.
-Primarily allocated by the *new* keyword, returns a pointer to the newly created object.
- Deallocated using the *delete* keyword followed by a pointer to the object.
- Delete expressions always return *void*.

### Dynamic Arrays

- Arrays with dynamic storage duration.

```cpp

// Dynamic Array:

new MyType[n_elements] {init_list}
 
  // Returns a pointer to the first element of the new array.
  // MyTpe:      Type of array elements.
  // n_elements: Length of array.
  // init_list:  Used to initialize the array.

// Allocate:

  int* my_int_array_ptr = new int[100];
  
// Deallocate:

  delete[] my_int_array_ptr; // Returns void.

```

### Memory Leaks

- Caused by failure to properly deallocate memory.

### Tracing the Object Life Cycle

Demonstrates object life cycle with memory leak issue from dynamic object allocation and failure to deallocate:

File: [tracer](./tracer.cpp)
