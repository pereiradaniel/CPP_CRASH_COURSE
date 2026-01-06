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

    // Move constructors look like copy constructors, but they take rvalue instead of lvalue references.
    // Executing the move constructor is less expensive than executing the copy constructor:
    SimpleString(SimpleString&& other) noexcept :
    max_size { other.max_size },
    buffer(other.buffer),
    length(other.length) {
        // other is an rvalue reference, so it can be cannibalized and then the fields zeroed.
        // This will put other in a moved-from state.
        other.length = 0;
        other.buffer = nullptr;
        other.max_size = 0;
    }

    // COPY ASSIGNMENT OPERATOR
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

int main() {}