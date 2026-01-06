#include <stdexcept>
#include <cstdio>

struct Test_Object {
    void test_function(int x) {
        if (x == 2) {
            throw std::runtime_error{"EXCEPTION"};
        }
    printf("Passed: %d\n", x);
    }
};

int main() {
    // Test_Object called test_object constructed:
    Test_Object test_object;

    // Establish a try-catch block:
    try {
        // test_object's test_function invoked using several different parameters:
        test_object.test_function(1); // Function is invoked, and returns.
        test_object.test_function(2); // Normal program execution is stopped.
        test_object.test_function(3); // Never invoked due to error caught in 2.
    }
    catch(const std::runtime_error& e) {
        // Any std::runtime_error exceptions are handled by printing the message to the console:
        printf("Exception caught with message: %s\n", e.what());
    }
}