#include <cstdio>

// Exercise 2-1: Create an enum class Operation that has values Add, Subtract, Multiply, and Divide.
enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

// Exercise 2-2: Create a struct Calculator. It should have a single constructor that takes an Operation.
struct Calculator {
    Calculator(Operation operation) {
        this->operation = operation;
    }

    // Exercise 2-3: Create a method on Calculator called int calculate(int a, int b). Upon invocation, this method should perform addition, subtraction, multiplication, or division based on its constructor arguement and return the result.
    int calculate(const int a, const int b) noexcept {
        switch (operation) {
            case Operation::Add: {
                return a+b;
            }
            case Operation::Subtract: {
                return a-b;
            }
            case Operation::Multiply: {
                return a*b;
            }
            case Operation::Divide: {
                return a/b;
            }
            default:
            printf("Invalid Operation!");
        }
    }

    private:
    Operation operation;
};

int main() {
    // 2-4: Experiment with different means of initializing Calculator instances:
    Calculator calculatorAdd(Operation::Add);
    printf("Sum of 1 and 2: %d\n", calculatorAdd.calculate(1,2));

    Calculator calculatorSubtract(Operation::Subtract);
    printf("Subtract 5 from 10: %d\n", calculatorSubtract.calculate(10,5));

    Calculator calculatorMultiply(Operation::Multiply);
    printf("Product of 2 and 6: %d\n", calculatorMultiply.calculate(2,6));

    Calculator calculatorDivide(Operation::Divide);
    printf("Quotient of dividing 100 by 5: %d\n", calculatorDivide.calculate(100, 5));
}