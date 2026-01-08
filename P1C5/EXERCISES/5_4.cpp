// 5-4.    Modify ConsoleLogger to accept a const char* at construction. When ConsoleLogger logs, prepend this string to the logging output. Notice that you can modify logging behaviour without having to modify Bank.

#include <cstdio>
#include <exception>

class Logger {
public:
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

class ConsoleLogger : public Logger {
public:
    ConsoleLogger(const char* str)
    : prefix{ str } {}
    
    ConsoleLogger(const ConsoleLogger& other) = default;
    ConsoleLogger& operator=(const ConsoleLogger& other) = default;

    virtual void log_transfer(long from, long to, double amount) override {
        printf("%s %ld -> %ld: %.2f\n", prefix, from, to, amount);
    }

private:
    const char* prefix;
};

class FileLogger : public Logger {
public:
    virtual void log_transfer(long from, long to, double amount) override {
        printf("File log: %ld -> %ld: %.2f\n", from, to, amount);
    }
};

class AccountDatabase {
public:
    virtual ~AccountDatabase() = default;
    virtual void setAmount(long from, long to, double amount) = 0;
};

class InMemoryAccountDatabase : public AccountDatabase {
public:
    void setAmount(long from, long to, double amount) override {
        printf("%ld -> %ld: %.2f\n", from, to, amount);
    }
};
class Bank {
public:
    Bank(InMemoryAccountDatabase &accountDB)
    : logger(nullptr),
    accountDB {accountDB} {}

    void set_logger(Logger *new_logger) {
        logger = new_logger;
    }

    void make_transfer(long from, long to, double amount) {
        accountDB.setAmount(from, to, amount);
        if (logger)
            logger->log_transfer(from, to, amount);
    }

private:
    Logger *logger;
    InMemoryAccountDatabase &accountDB;
};

int main() {
    try {
        ConsoleLogger console_logger("prefix: ");
        FileLogger file_logger;
        InMemoryAccountDatabase bankAccounts;
        Bank bank { bankAccounts};

        bank.set_logger(&console_logger);
        bank.make_transfer(100,200,300.55);

        printf("\n");

        bank.set_logger(&file_logger);
        bank.make_transfer(400,500,600.77);
    }
    catch(const std::exception& e) {
        printf("Exception: %s\n", e.what());
        return 1;
    }
    catch(...) {
        printf("Unknown exception!\n");
        return 2;
    }

    return 0;
}