// SimpleString Final Product

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

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
        delete[] buffer;
    }

    SimpleString(const SimpleString& other) {}

    SimpleString(SimpleString&& other) noexcept :
        max_size(other.max_size),
        buffer(other.buffer),
        length(other.length) {

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