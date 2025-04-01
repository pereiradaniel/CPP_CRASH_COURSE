// Listing 5-1

// Bank and ConsoleLogger have separate concerns:
// Bank deals with logic.
// ConsoleLogger deals with logging.

#include <cstdio>

struct ConsoleLogger {
  // 1 Implelement ConsoleLogger with a log_transfer method, which accepts the details of a transaction:
    void log_transfer(long from, long to, double amount) {
        // 2 Prints transaction details:
        printf("%ld -> %ld: %f\n", from, to, amount);
  }
};

struct Bank {
    // 3 
    void make_transfer(long from, long to, double amount) {
    // 4 Notionally processes the transaction:
    // snip

    // 5 Logs the transaction:
    logger.log_transfer(from, to, amount);
  }
  ConsoleLogger logger;
};

int main() {
  Bank bank;
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
}
