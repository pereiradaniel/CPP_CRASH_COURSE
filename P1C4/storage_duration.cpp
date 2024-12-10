#include <cstdio>

// Global static int that can be accessed from anywhere:
static int num_of_races;

// Class object whose state tracks the progress of a race, and whose functions modify the state as the race progresses:
struct RaceLapCounter {    
    // Static constant variable that is only accessible from RaceLapCounter:
    static const int default_total_laps = 70;

    // DEFAULT CONSTRUCTOR
    // Initializes member variables, especially total_laps using the static constant default, and logically setting the total laps remaining to the total_laps, since the race has not yet begun:
    RaceLapCounter() :
        yellow_flags {0},
        total_laps {default_total_laps},
        total_laps_remaining {total_laps}
    {
        common_initialization_procedure();  // Used in every constructor.
    }

    // ONE ARGUMENT CONSTRUCTOR
    // Initializes lap counter variable using a given argument of number of laps:
    RaceLapCounter(int num_of_laps_this_race) :
        yellow_flags {0},
        total_laps {num_of_laps_this_race},
        total_laps_remaining {total_laps}
    {
        common_initialization_procedure();
    }

    // THREE ARGUMENT CONSTRUCTOR
    // Initializes a race that is partially run-through, so it takes arguments for laps_remaining and num_yellow_flags:
    RaceLapCounter(int laps, int laps_remaining, int num_yellow_flags) :
        total_laps {laps},
        total_laps_remaining {laps_remaining},
        yellow_flags {num_yellow_flags}
    {
        common_initialization_procedure();
    }

    private:
        int yellow_flags = 0;                   // Counter for yellow flags.
        int total_laps = default_total_laps;    // Represents the total number of laps for a single race.
        int total_laps_remaining = total_laps;  // Counter for the number of laps remaining.

    public:
        // STATIC MEMBER FUNCTIONS:

        // Displays the total number of races that have been run so far.
        static void display_total_num_of_races() {
            // Makes use of the global static variable num_of_races:
            printf("Number of total races this season: %d\n", num_of_races);
        }

        // NON-STATIC MEMBER FUNCTIONS
        
        // Runs a block of code which should be common to all Constructors:
        void common_initialization_procedure() {
            ++num_of_races;
        }

        // Simulates the number of race laps provided:
        void race_lap(int num_laps_raced) {
            this->total_laps_remaining -= num_laps_raced;
        }

        // Displays the number of remaining laps:
        void display_remaining_laps() {
            printf("Number of laps remaining: %d\n", this->total_laps_remaining);
        }

        // OVERLOADED FUNCTION: add_yellow_flags()
        
        // Adds only one yellow flag at a time.
        void add_yellow_flags() {
            ++this->yellow_flags;
        }

        // Adds a number of yellow flags to the counter:
        void add_yellow_flags(int num_yellow_flags) {
            this->yellow_flags += num_yellow_flags;
        }

        // Displays a message with the number of yellow flags:
        void display_yellow_flags() const {
            printf("Number of yellow flags shown: %d\n", this->yellow_flags);
        }
};

int main() {
    RaceLapCounter monza;
    printf("Monza start: \n");
    printf("Race start: ");
        monza.display_remaining_laps();

    monza.race_lap(50);
    monza.add_yellow_flags(3);
 
    printf("Race middle: ");
        monza.display_remaining_laps();
        monza.display_yellow_flags();

    monza.race_lap(19);
 
    printf("Race end: ");
        monza.display_remaining_laps();
        monza.race_lap(1);
    
    printf("Race Complete: ");
        monza.display_remaining_laps();
    
    // Uses global scope to run a static function:
    RaceLapCounter::display_total_num_of_races();

    RaceLapCounter monaco(50);
    printf("Monaco start:\n");
        monaco.display_remaining_laps();
        monaco.display_yellow_flags();

    monaco.race_lap(30);
    monaco.add_yellow_flags();

    printf("Monaco middle: ");
        monaco.display_remaining_laps();
        monaco.display_yellow_flags();

    monaco.race_lap(20);

    printf("Race Complete: ");
        monaco.display_remaining_laps();
        monaco.display_yellow_flags();
    
    RaceLapCounter::display_total_num_of_races();
}

/////////////////////////////////////////////////////////////////////
// Coding example: storage_duration.cpp
// Description: Makes use of static functions and variables.
//              Demonstrates global scope and global scope operators.
//
/////////////////////////////////////////////////////////////////////
// Daniel Pereira 2024