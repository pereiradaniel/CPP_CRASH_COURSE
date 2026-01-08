// 5-1.    You didn't implement an accounting system in your Bank. Design an interface called AccountDatabase that can retrieve and set amounts in bank accounts (identified by a long id).

class AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void setAmount(long from, long to, double amount) = 0;
};

// Notes:
// 1. An interface in C++ is typically defined as a class with pure virtual functions.
// 2. The destructor is declared as virtual to ensure proper cleanup of derived classes.
// 3. The = 0 syntax indicates that the function is pure virtual, meaning that derived classes must provide an implementation for it.
// 4. The = default syntax for the destructor indicates that the default implementation is used.