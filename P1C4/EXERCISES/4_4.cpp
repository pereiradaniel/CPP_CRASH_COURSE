// Exercise 4-4:
// Implement a move constructor and a move assignment operator for TimerClass.
// A moved-from TimerClass shouldn't print any output to the console when it gets destructed. 

#include <cstdio>
#include <chrono>

struct TimerClass {
    // Constructor:
    TimerClass(const char* name)
    :   timestamp{ std::chrono::system_clock::now() },
        name{ name }
    {}

    // Destructor: 
    ~TimerClass()
    {
        // Record the current time:
        auto currentTime = std::chrono::system_clock::now();

        // Subtract the time at construction from the curret time:
        std::chrono::duration<double> elapsed_time = currentTime - timestamp;
        
        // Print the value containing the age of the timer:
        printf("Age of the timer: '%s': %f\n", name, elapsed_time.count());
    }

    // Copy Constructor:
    TimerClass(const TimerClass &copy)
    :   timestamp{ copy.timestamp },
        name{ copy.name }
    {}

    // Copy Assignment:
    TimerClass& operator=(const TimerClass& copy)
    {
        if (this != &copy) {
            timestamp = copy.timestamp;
            name = copy.name;
        }
        return *this;
    }

    private:
    std::chrono::time_point<std::chrono::system_clock> timestamp;   // Records the time of construction.
    const char* name;
};

int main() {
}