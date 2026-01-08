// 5-1.    You didn't implement an accounting system in your Bank. Design an interface called AccountDatabase that can retrieve and set amounts in bank accounts (identified by a long id).

class AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void setAmount(long from, long to, double amount) = 0;
};