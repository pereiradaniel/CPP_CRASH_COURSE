// Demonstrates usage of the pattern known as:
//  RAII (resource acquisition is initialization) or
//  Constructor Acquires Destructor Releases (CADRe)
//  Copy Semantics / Copy Assignment

#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString {
    // Copy Constructor
    // Use member initializers for max_size, buffer, and length:
    // Use array new to initialize buffer:
    // Single statement in copy constructor's body copies the contents pointed to by other.buffer:
    SimpleString(const SimpleString& other)
    :   max_size{ other.max_size},
        buffer{ new char[other.max_size]},
        length{ other.length } {
            std::strncpy(buffer, other.buffer, max_size);
        }

    // Copy Assignment
    SimpleString& operator=(const SimpleString& other) {
        
        // Check to see if other refers to this:
        if (this == &other) return *this;
        
        // Start by allocating a new_buffer with the appropriate size:
        const auto new_buffer = new char[other.max_size];
        
        // Clean up the buffer:
        delete[] buffer;

        // The rest of the Copy Assignment Operator is similar to the Copy Constructor, in copying the private members from other: 
        buffer = new_buffer;
        length = other.length;
        max_size = other.max_size;

        // Copy the contents from other.buffer into the this buffer:
        std::strncpy(buffer, other.buffer, max_size);
        
        // The copy assignment operator returns a refernce to the result, which is always *this.
        return *this;
    }

    // Constructor takes a single argument that is the maximum length of the string including a null terminator:
    SimpleString(size_t max_size)
    : max_size{max_size},
    length{} {
        if (max_size == 0) {
            throw std::runtime_error{"Max size must be at least 1."};
        }

        // Allocate memory for buffer using max_size:
        buffer = new char[max_size];    // Resulting pointer is stored to buffer!
        
        // Initializes buffer length to 0 and store a null byte:
        buffer[0] = 0;  // buffer is initially an empty string!
    }

    ~SimpleString() {
        // Deallocates buffer:
        delete[] buffer;
    }

    // Prints the string. const used because there is no need to modify the state of the SimpleString:
    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

    // This method takes a null-terminated string x and adds its contents plus a newline char to buffer:
    bool append_line(const char* x) {

        // Determine the length of x using strlen() from <cstring>:
        const auto x_len = strlen(x);

        // Determine whether appending x (a newline char) and a null byte to the current string would result in a string with length greater than max_size, return false if it does:
        if (x_len + length + 2 > max_size) return false;

        // If there is enough room to append x, copy its bytes into the correct location in nbuffer:
        std::strncpy(buffer+length,x,max_size-length);
        length += x_len;

        // After adding the number of bytes x_len coped into buffer to length, finish by adding a newline char \n and a null byte to the end of the buffer.
        buffer[length++]='\n';
        buffer[length] = 0;

        // Return true to indicate successfully appended x as a line to the end of buffer:
        return true;
    }

    private:
        size_t max_size;
        char* buffer;
        size_t length;
};

// Define a class with a SimpleString member:
struct SimpleStringOwner {
    SimpleStringOwner(const char* x)
    :string{10} {
        if (!string.append_line(x)) {
            throw std::runtime_error{"Not enough memory!"};
        }
        string.print("Constructed");
    }
    ~SimpleStringOwner() {
        string.print("About to destroy");
    }

    private:
        SimpleString string;
};

void fn_c() {
    SimpleStringOwner c{"cccccccccc"};
}

void fn_b() {
    SimpleStringOwner b{"b"};
    fn_c();
}

int main() {
    printf("Create a SimpleString and append until max_length exceeded:\n");

    // Create a SimpleString called string with a max_length of 60:
    SimpleString string{60};
    
    // Use the append_line method to add some data to string:
    string.append_line("First line.");
    string.append_line("Second line.");

    // Print the contents of string along with a tag, A:
    string.print("A");

    // Append more text:
    string.append_line("Third line.");
    string.append_line("Fourth line.");
    
    // Print the contents again with another tag, B:
    string.print("B");

    // Purposely try to go over the max_size limit of string by appending more data:
    if(!string.append_line("Fifth line.")) {
        printf("String was not big enough to append another message!\n");
    }


    printf("\n\nSimpleStringOwner and call stack unwinding:\n");

    // Demonstrate a SimpleStringOwner:
    SimpleStringOwner x{"x"};
    printf("x is alive\n");

    // Demonstrate call stack unwinding:
    try {
        // The first SimpleStringOwner a is constructed without incident:
        SimpleStringOwner a{"a"};
        
        // Because this next call is still within the try block, exceptionns will still be handled:
        fn_b(); // Contains call to fn_c() that will throw an exception.

        // Once an exception occurs in a try block, no further statements will execute, and so d never initializes:
        SimpleStringOwner d{"d"};
    } catch(const std::exception& e) {
        printf("Exception: %s\n", e.what());
    }


    // printf("\n\nCopy Semantics with Copy Constructor:\n");

    // // Demo 3:
    // // Copy Constructor:
    // SimpleString a { 50 };
    // a.append_line("We apologize for the");
    
    // // a_copy is constructed from a:
    // SimpleString a_copy{ a };

    // // Append different messages to the end of the different copies of SimpleString.buffer:
    // a.append_line("inconvenience.");
    // a_copy.append_line("incontinence.");
    
    // // Print the SimpleStrings buffers to show that they point to different areas of memory and are independent: 
    // a.print("a");
    // a_copy.print("a_copy");


    printf("\n\nCopy Semantics with Copy Assignment:\n");

    // Begin by declaring two SimpleString classes with different mssagess:
    
    // First SimpleString:
    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    
    // Second SimpleString:
    SimpleString b{ 50 };
    b.append_line("Last message");

    // Print the strings to verify that they contain the appropriate message:
    a.print("a");
    b.print("b");

    // Copy assign b to a. They will contain copies of the same message even though they reside in two separate memory locations.:
    b=a;

    // Print the strings to verify that they contain copies of the same message:
    a.print("a");
    b.print("b");

    printf("\n\n");
    
}

// OUTPUT:

// ==1285== Memcheck, a memory error detector
// ==1285== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
// ==1285== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
// ==1285== Command: ./simplestring_copy_assignment
// ==1285==
// Create a SimpleString and append until max_length exceeded:
// A: First line.
// Second line.
// B: First line.
// Second line.
// Third line.
// Fourth line.
// String was not big enough to append another message!


// SimpleStringOwner and call stack unwinding:
// Constructed: x
// x is alive
// Constructed: a
// Constructed: b
// About to destroy: b
// About to destroy: a
// Exception: Not enough memory!


// Copy Semantics with Copy Assignment:
// a: We apologize for the
// b: Last message
// a: We apologize for the
// b: We apologize for the


// About to destroy: x
// ==1285== 
// ==1285== HEAP SUMMARY:
// ==1285==     in use at exit: 0 bytes in 0 blocks
// ==1285==   total heap usage: 12 allocs, 12 frees, 74,165 bytes allocated
// ==1285==
// ==1285== All heap blocks were freed -- no leaks are possible
// ==1285==
// ==1285== For lists of detected and suppressed errors, rerun with: -s
// ==1285== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)