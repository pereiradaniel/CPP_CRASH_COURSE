// 5-2.    Genereate an InMemoryAccountDatabase that implements AccountDatabase.

#include <cstdio>
class AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void setAmount(long from, long to, double amount) = 0;
};

// InMemoryAccountDatabase is a derived class of AccountDatabase!
class InMemoryAccountDatabase : AccountDatabase {
    public:
        void setAmount(long from, long to, double amount) override {
            printf("%ld -> %ld: %.2f\n", from, to, amount);
        }
};