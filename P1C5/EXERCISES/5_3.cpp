// 5-3.    Add an AccountDatabase reference member to Bank. Use constructor injection to add an InMemoryAccountDatabase to the Bank.

#include <cstdio>
class AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void setAmount(long from, long to, double amount) = 0;
};

class InMemoryAccountDatabase : AccountDatabase {
    public:
        void setAmount(long from, long to, double amount) override {
            printf("%ld -> %ld: %.2f\n", from, to, amount);
        }
};

class Bank {
public:
    Bank(InMemoryAccountDatabase &accountDB)
    : accountDB {accountDB} {}
private:
    InMemoryAccountDatabase &accountDB;
};