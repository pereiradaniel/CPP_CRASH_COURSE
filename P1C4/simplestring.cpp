// Demonstrates usage of the pattern known as:
//  RAII (resource acquisition is initialization) or
//  Constructor Acquires Destructor Releases (CADRe)

#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString {
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
}

// OUTPUT:

// ==21114== Memcheck, a memory error detector
// ==21114== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==21114== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==21114== Command: ./simplestring
// ==21114== 
// A: First line.
// Second line.
// B: First line.
// Second line.
// Third line.
// Fourth line.
// String was not big enough to append another message!
// Constructed: x
// x is alive
// Constructed: a
// Constructed: b
// About to destroy: b
// About to destroy: a
// Exception: Not enough memory!
// About to destroy: x
// ==21114== 
// ==21114== HEAP SUMMARY:
// ==21114==     in use at exit: 0 bytes in 0 blocks
// ==21114==   total heap usage: 9 allocs, 9 frees, 75,039 bytes allocated
// ==21114== 
// ==21114== All heap blocks were freed -- no leaks are possible
// ==21114== 
// ==21114== For lists of detected and suppressed errors, rerun with: -s
// ==21114== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)