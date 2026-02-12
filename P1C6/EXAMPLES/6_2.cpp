// Listing 6-2: A template function with three template parameters.
// Template Class Definitions

#include <cstdio>

template<typename X, typename Y, typename Z>
// Template function that takes three template parameters: X, Y, and Z.
// It takes a reference to a Y and a pointer to a const Z, and returns an X.
X my_template_function(Y& arg1, const Z* arg2) {
    // Example implementation: just prints the arguments and returns a default value of type X
    std::printf("arg1: %f, arg2: %c\n", static_cast<double>(arg1), *arg2);
    return X{};
}

int main() {
    double arg1 = 1.0;
    const char arg2 = 'a';
    auto result = my_template_function<int, double, char>(arg1, &arg2);
}