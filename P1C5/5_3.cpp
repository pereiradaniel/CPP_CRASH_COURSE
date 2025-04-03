// Listing 5-3
#include <cstdio>

struct Logger {
    // Virtual destructor:
    virtual ~Logger() = default;

    // Pure virtual method:
    virtual void log_transfer(long from, long to, double amount) = 0;
};

// Base class inheritance:
struct ConsoleLogger : Logger {
    // Override keyword:
    void log_transfer(long from, long to, double amount) override {
        printf("%ld -> %ld\n", from, to, amount);
    }
};