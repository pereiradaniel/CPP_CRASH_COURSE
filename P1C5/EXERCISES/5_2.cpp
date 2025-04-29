// Listing 5-2: Adds a FileLogger to Listing 5-1.
// Uses an enum class to switch between various loggers.

#include <cstdio>
#include <stdexcept>

struct FileLogger {
  // 1 Notionally add the ability to log to a file by implementing a FileLogger:
  void log_transfer(long from, long to, double amount) {
    //
    printf("[file] %ld,%ld,%f\n", from, to, amount);
  }
};

struct ConsoleLogger {
  void log_transfer(long from, long to, double amount) {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

// 2 Create an enum class LoggerType so you can switch logging behaviour at runtime:
enum class LoggerType { Console, File };

struct Bank {
  // 3 Initialize thje type field to Console within the Bank constructor:
  Bank()
      : type{ LoggerType::Console } {}
  // 4 Add a set_logger function to perform desired logging behaviour:
  void set_logger(LoggerType new_type) {
    type = new_type;
  }

  void make_transfer(long from, long to, double amount) {
    //
    // 5 Ise the type within make_transfer to switch on the correct logger:
    switch(type) {
    case LoggerType::Console: {
      consoleLogger.log_transfer(from, to, amount);
      break;
    }
    case LoggerType::File: {
      fileLogger.log_transfer(from, to, amount);
      break;
    }
    default: {
      throw std::logic_error("Unknown Logger type encountered.");
    }
    }
  }

  private:
  LoggerType type;
  ConsoleLogger consoleLogger;
  FileLogger fileLogger;
};

int main() {
  Bank bank;
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
  // 6 Alter a Bank class' logging behaviour by uing the set_logger method, the object handles dispatching internally:
  bank.set_logger(LoggerType::File);
  bank.make_transfer(3000, 2000, 75.00);
}
