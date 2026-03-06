// Listing 6-6

// Implement an Account class and instantiate a Bank<Account>. Implement functions in Account to keep track of balances.

#include <cstdio>
struct Account {
    public:
    int m_account_number;

    Account(int account_number, double m_balance) : m_account_number{account_number}, m_balance{m_balance} {}
    explicit Account(const double amount) : m_balance{amount} {}

    void deposit (const double amount) {
        m_balance += amount;
    }

    void withdraw (const double amount) {
        m_balance -= amount;
    }

    void print_balance() const {
        printf("Balance: %f\n", m_balance);
    }

    private:
    double m_balance;
};

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
    template <typename account1, typename account2>
    void make_transfer(account1 &from, account2 &to, const double amount) {

        // Log the transfer:
        if (logger) logger->log_transfer(from.m_account_number, to.m_account_number, amount);

        // Perform the transfer:
        from.withdraw(amount);
        to.deposit(amount);
    }

    private:
    Logger* logger;
};

int main() {
    ConsoleLogger console_logger;
    FileLogger file_logger;
    Bank bank{};
    
    // Set up two accounts to be used in the example:
    Account account1(100, 100.0);
    Account account2(200, 0.0);

    // Print starting balances to the console:
    account1.print_balance();
    account2.print_balance();

    // Use the console logger
    bank.set_logger(&console_logger);
    
    // Use template to make a transfer:
    bank.make_transfer(account1, account2, 75.00);
    
    // Print balances to the console to show that transfer worked:
    account1.print_balance();
    account2.print_balance();
}
