// Listing 6-7

// Make Account an interface. Implement a CheckingAccount and SavingsAccount. Create a program with several checking and savings accounts. Use a Bank<Account> to make several transactions between the accounts.

#include <cstdio>
struct Account {
    virtual void deposit (const double amount) = 0;
    virtual void withdraw (const double amount) = 0;

    public:
    int m_account_number;
    double m_balance;

    private:

};

struct ChequingAccount : public Account {
    ChequingAccount(const int m_account_number, const double m_balance){
        this->m_account_number = m_account_number;
        this->m_balance = m_balance;
    };
    void deposit (const double amount)  {
        m_balance += amount;
    }
    void withdraw (const double amount) {
        m_balance -= amount;
    }
    void print_balance() const {
        printf("Balance: %f\n", m_balance);
    }
};

struct SavingsAccount : Account {
    SavingsAccount(const int m_account_number, const double m_balance) {
        this->m_account_number = m_account_number;
        this->m_balance = m_balance;
    }
    void deposit (const double amount) {
        m_balance += amount;
    }
    void withdraw (const double amount) {
        m_balance -= amount;
    }
    void print_balance() const {
        printf("Balance: %f\n", m_balance);
    }
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
template <typename T>
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

    // Set up accounts to be used in the example:
    ChequingAccount chequingA(100, 100.0);
    ChequingAccount chequingB(200, 100.0);

    SavingsAccount savingsA(300, 100.0);
    SavingsAccount savingsB(400, 100.0);

    // // Print starting balances to the console:
    chequingA.print_balance();
    chequingB.print_balance();

    savingsA.print_balance();
    savingsB.print_balance();

    Bank<Account> bank{};
    // Use the console logger
    bank.set_logger(&console_logger);
    printf("Transfers:\n");

    bank.make_transfer(chequingA, chequingB, 75.00);
    bank.make_transfer(savingsA, savingsB, 75.00);
    
    // Print balances to the console to show that transfer worked:
    chequingA.print_balance();
    chequingB.print_balance();
    savingsA.print_balance();
    savingsB.print_balance();
}
