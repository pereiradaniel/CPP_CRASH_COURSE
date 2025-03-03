// A program illustrating that passing by value generates a copy:

#include <cstdio>

int add_one_to(int x) {
    // add_one_to() takes its argument "x" by value. Then it modifies the value of x.
    // This modification is isolated from the calling function!
    ++x;
    return x;
}

int main() {
    auto original = 1;
    
    // 'original' will be unaffected by the function call, because add_one_to receives a copy of original.
    auto result = add_one_to(original);
    
    printf("Original: %d; Result:%d", original, result); 
}