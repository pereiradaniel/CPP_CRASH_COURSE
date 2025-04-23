// Listing 5-11: Logger, ConsoleLogger, and FileLogger.
#include <cstdio>

struct Logger {
    // Logger is a pure virtual class (interface) with a default virtual destructor:
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

// ConsoleLogger are Logger implementations because they derive from the interface:
struct ConsoleLogger : Logger {
    // log_transfer implemented and the override keyword placed:
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

// FileLogger are Logger implementations because they derive from the interface:
struct FileLogger : Logger {
    // log_transfer implemented and the override keyword placed:
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }
};

struct Bank {
  Bank(Logger& logger)
      : logger{ logger } {}
  void make_transfer(long from, long to, double amount) {
    // log_transfer implemented and the override keyword placed:
    logger.log_transfer(from, to, amount);
  }

  private:
  Logger& logger;
};

int main() {
  ConsoleLogger logger;
  Bank bank{ logger };
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
}
