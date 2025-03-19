// SimpleString Final Product

#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString {
    SimpleString(size_t max_size) {}

    ~SimpleString() {}

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