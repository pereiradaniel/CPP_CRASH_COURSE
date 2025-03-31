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
        
        // Print output only if timer has not been moved:
        if (moved_from == false)
            printf("Elapsed time of timer: '%s': %f\n", name, elapsed_time.count());
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

    // Move Constructor:
    TimerClass(TimerClass&& move) noexcept
    :   timestamp{ move.timestamp },
        name{ move.name }
    {
        // Zero the fields on the moved from object:
        move.zeroFields();
    }

    // Move Assignment:
    TimerClass& operator=(TimerClass&& move) noexcept
    {
        if (this != &move) {
            timestamp = move.timestamp;
            name = move.name;
         
            // Zero the fields on the moved from object:
            move.zeroFields();
        }
            return *this;
    }

    // Function that zeroes the fields of a TimerClass object:
    void zeroFields() noexcept
    {
        // Zero the name field by setting to nullptr:
        this->name = nullptr;

        // Flip the moved_from boolean:
        this->moved_from = true;
    }

    private:
    std::chrono::time_point<std::chrono::system_clock> timestamp;   // Records the time of construction.
    const char* name;
    bool moved_from = false;                                        // Indicates if object has been moved from.
};

int main() {
    TimerClass timer1 { "Timer 1" };
    TimerClass timer2 { "Timer 2" };

    timer2 = timer1;

    TimerClass timer3{ "Timer 3" };
}