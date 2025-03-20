// SimpleString Final Product

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
    // SINGLE ARGUMENT CONSTRUCTOR
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

    // DESTRUCTOR
    ~SimpleString() {
        delete[] buffer;
    }

    // COPY CONSTRUCTOR
    // Use member initializers for max_size, buffer, and length:
    // Use array new to initialize buffer:
    // Single statement in copy constructor's body copies the contents pointed to by other.buffer:
    SimpleString(const SimpleString& other)
    :   max_size{ other.max_size},
        buffer{ new char[other.max_size]},
        length{ other.length } {
            std::strncpy(buffer, other.buffer, max_size);
    }

    // MOVE ASSIGNMENT OPERATOR
    SimpleString& operator=(SimpleString&& other) noexcept {
        // Self-reference check:
        if (this == &other) return *this;
        
        // Clear buffer before assigning fields from 'this' to fields of 'other':
        delete[] buffer;
        buffer = other.buffer;
        length = other.length;
        max_size = other.max_size;
        
        // Zero the fields of 'other':
        other.buffer = nullptr;
        other.length = 0;
        other.max_size = 0;
        
        // Return pointer to this:
        return *this;
    }

    SimpleString& operator=(const SimpleString& other) {}

    SimpleString& operator=(SimpleString&& other) noexcept {}

    void print(const char* tag) const {}

    bool append_line(const char* x) {}

    private:
        size_t max_size;
        char* buffer;
        size_t length;
};