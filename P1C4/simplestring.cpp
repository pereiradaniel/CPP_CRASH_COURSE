// Demonstrates usage of the pattern known as:
//  RAII (resource acquisition is initialization) or
//  Constructor Acquires Destructor Releases (CADRe)
#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString {
    // Constructor takes a single argument that is the maximum length of the string including a null terminator.
    SimpleString(size_t max_size)
    : max_size{max_size},
    length{} {
        if (max_size == 0) {
            throw std::runtime_error{"Max size must be at least 1."};
        }

        // Allocate memory for buffer using max_size:
        buffer = new char[max_size];    // Resulting pointer stored to buffer
        
        // Initializes buffer length to 0 and store a null byte:
        buffer[0] = 0;
    }

    ~SimpleString() {
        // Deallocates buffer:
        delete[] buffer;
    }

    void print(const char* tag) const {
        printf("%s: %s", tag, buffer);
    }

bool append_line(const char* x) {
    const auto x_len = strlen(x);

    if (x_len + length + 2 > max_size) return false;

    std::strncpy(buffer+length,x,max_size-length);
    length += x_len;
    buffer[length++]='\n';
    buffer[length] = 0;
    return true;
}

    private:
        size_t max_size;
        char* buffer;
        size_t length;
};

int main() {
    
}