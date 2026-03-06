// Listing 6-5

// Using the example from Chapter 5, make Bank a template class that accepts a template parameter use this type parameter as the type of an account rather than long. Verify that your code still works using a Bank<long>class.

#include <cstdio>

// Logger interface and implementations remain unchanged, as they still work with long account numbers.
struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

// ConsoleLogger and FileLogger remain unchanged, as they still work with long account numbers.
struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct FileLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }
};

// Bank is now a template class that accepts a type parameter T for account numbers.
struct Bank {
    Bank() {}
    // The constructor and set_logger method remain unchanged, as they still work with Logger pointers.
    Bank(Logger* logger): logger{logger} {}
    // set_logger remains unchanged, as it still works with Logger pointers.
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }

    // make_transfer is now a template method that accepts parameters of type T for account numbers.
    template <typename T>
    void make_transfer(const T &from, const T &to, const double amount) {
        if (logger) logger->log_transfer(from, to, amount);
    }

    private:
    Logger* logger;
};

int main() {
    ConsoleLogger console_logger;
    FileLogger file_logger;
    Bank bank;
    bank.set_logger(&console_logger);
    bank.make_transfer(1000, 2000, 49.95);
    bank.set_logger(&file_logger);
    bank.make_transfer(2000, 4000, 20.00);
}
