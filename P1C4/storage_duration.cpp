/* Demonstrates global scope of static variables and object lifetime of automatic variables.

    # Static Storage Duration

        total_laps, total_laps_remaining

    These are static global variables. Their lifetime begins and ends with the program. They can be accessed from everywhere in the program, as their scope is global.

    # Automatic Storage Duration

        total_laps_raced

    This variable has an automatic storage duration. It begins and ends with the function call, so its value is not persistent between function calls.  

*/

#include <cstdio>
// Static variables declared at global scope:
static const int    total_laps           = 70;          // Constant reference for number of laps for the race.
static int          total_laps_remaining = total_laps;  // Counter that tracks race progress.

// Updates the race based on how many laps were just raced:
void race_lap(int num_laps_raced) {
    // Updates total_laps_remaining by subtracting the number of laps raced by the current function call:
    total_laps_remaining -= num_laps_raced;

    // Initializes a variable and assigns to it the total laps raced so far:
    const auto total_laps_raced = total_laps - total_laps_remaining; 
    
    // Prints warning to the screen when only one lap remains:
    if(total_laps - total_laps_raced == 1)
        printf("*** One lap remains! ***\n");
}

// Displays number of remaining laps:
void display_remaining_laps() {
    printf("%d laps remain.\n", total_laps_remaining);
}

int main() {
    printf("Race start: ");
    display_remaining_laps();
    race_lap(50);
 
    printf("Race middle: ");
    display_remaining_laps();
    race_lap(19);
 
    printf("Race end: ");
    display_remaining_laps();
}