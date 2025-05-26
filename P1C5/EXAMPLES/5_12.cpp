// Listing 5-12: Refactoring Listing 5-2 using constructor injection, interfaces, and object composition to replace the clinky enum class approach.
#include <cstdio>

struct Logger {
  // Logger is a pure virtual class (interface) with a default virtual destructor:
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};

// ConsoleLogger are Logger implementations because they derive from the Logger interface:
struct ConsoleLogger : Logger {
  // log_transfer implemented and the override keyword placed:
  void log_transfer(long from, long to, double amount) override {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct FileLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[file] %ld,%ld,%f\n", from, to, amount);
  }
};

struct Bank {
  void set_logger(Logger* new_logger) {
    logger = new_logger;
  }
  void make_transfer(long from, long to, double amount) {
    if(logger)
      logger->log_transfer(from, to, amount);
  }

  private:
  Logger* logger{};
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
