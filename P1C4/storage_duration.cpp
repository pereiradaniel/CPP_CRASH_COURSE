/* Demonstrates global scope of static variables and object lifetime of automatic variables.

    Global Scope Variables:
        - total_laps and total_laps_remaining are global scope variables.
        - No scope operator is required to access them.

    Static Method Members:
        - race_lap and disaply_remaining_laps are static methods of RaceLapCounter.
        - In the main() function a global scope operator is required to access them.
        
*/

#include <cstdio>
// Global Scope Variables:
    const int total_laps           = 70;           // Constant reference for number of laps for the race.
    int       total_laps_remaining = total_laps;   // Counter that tracks race progress.

// Updates the race based on how many laps were just raced:
struct RaceLapCounter {
    // Static Methods:
    static void race_lap(int num_laps_raced) {
        // Updates total_laps_remaining by subtracting the number of laps raced by the current function call:
        total_laps_remaining -= num_laps_raced;

        // Initializes a variable and assigns to it the total laps raced so far:
        const auto total_laps_raced = total_laps - total_laps_remaining; 
        
        // Prints warning to the screen when only one lap remains:
        if(total_laps - total_laps_raced == 1)
            printf("*** One lap remains! ***\n");
    }

    // Displays number of remaining laps:
    static void display_remaining_laps() {
        printf("%d %s.\n", total_laps_remaining, total_laps_remaining > 1 ? "laps remain" : "lap remains");
    }
};

int main() {
    printf("Race start: ");
    RaceLapCounter::display_remaining_laps();
    RaceLapCounter::race_lap(50);
 
    printf("Race middle: ");
    RaceLapCounter::display_remaining_laps();
    RaceLapCounter::race_lap(19);
 
    printf("Race end: ");
    RaceLapCounter::display_remaining_laps();
}