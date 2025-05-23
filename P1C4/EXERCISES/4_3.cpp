// Exercise 4-3:
// Implement a copy constructor and a copy assignment operator for TimerClass.
// The copies should share timestamp values.

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

        // Subtract the time at construction from the current time:
        std::chrono::duration<double> elapsed_time = currentTime - timestamp;
        
        // Print the value containing the age of the timer:
        printf("Age of the timer: '%s': %f\n", name, elapsed_time.count());
    }

    // Copy Constructor:
    TimerClass(const TimerClass &copy)
    :   timestamp{ copy.timestamp },
        name{ copy.name }
    {
        printf("Copy Constructor\n");
    }

    // Copy Assignment:
    TimerClass& operator=(const TimerClass &copy)
    {
        printf("Copy Assignment\n");
        if (this != &copy) {
            printf("Copying...\n");
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
    TimerClass timer1 { "Timer 1" };
    TimerClass timer2 { "Timer 2" };

    timer2 = timer1;

    TimerClass timer3{ "Timer 3" };
}