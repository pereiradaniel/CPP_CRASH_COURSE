// Exercise 4-5:
// Elaborate the TimerClass constructor to accept an additional const char* name parameter. When TimerClass is destructed and prints to stdout, include the name of the timer in the output.

#include <cstdio>
#include <chrono>
#include <utility>  // std::move

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
    {
        printf("Copy Constructor\n");
    }

    // Copy Assignment:
    TimerClass& operator=(const TimerClass& copy)
    {
        printf("Copy Assignment\n");
        if (this != &copy) {
            printf("Copying...\n");
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
        printf("Move Constructor\n");

        // Zero the fields on the moved from object:
        move.zeroFields();
    }

    // Move Assignment:
    TimerClass& operator=(TimerClass&& move) noexcept
    {
        printf("Move Assignment\n");
        if (this != &move) {
            printf("Moving...\n");
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

    // Copy assignment:
    timer2 = timer1;

    TimerClass timer3{ "Timer 3" };
    TimerClass timer4{ "Timer 4" };
    
    // Move assignment:
    timer3 = std::move(timer4);
}