// Exercise 4-1:
// Create a struct TimerClass.
// In its constructor, record the current time in a field called timestamp.
// (Compare with the POSIX function gettimeofday).

#include <chrono>
struct TimerClass {
    // Constructor:
    TimerClass(const char* name)
    :   timestamp{ std::chrono::system_clock::now() },
        name{ name }
    {}
    
    private:
    std::chrono::time_point<std::chrono::system_clock> timestamp;   // Records the time of construction.
    const char* name;
};

int main() {
}