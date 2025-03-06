#include <cstdio>
 
struct Highlander {
    Highlander(const Highlander&) = delete;
    Highlander& operator=(const Highlander&) = delete;
};

int main() {
    // Will generate a compiler error!
    Highlander a;
    Highlander b{ a };
}