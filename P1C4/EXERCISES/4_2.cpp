// Exercise 4-2:
// In the destructor of TimerClass, record the current time and subtract the time at construction.
// This time is rougly the age of the timer.
// Print this value.
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

    private:
    std::chrono::time_point<std::chrono::system_clock> timestamp;   // Records the time of construction.
    const char* name;
};

int main() {
}