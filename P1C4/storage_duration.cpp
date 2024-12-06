// Demonstrates global scope of static variables and object lifetime of automatic variables.
#include <cstdio>

// Static variables declared at global scope:
static const int total_laps = 70;
static int total_laps_remaining = total_laps;

void race_lap(int num_laps_raced) {
    // Updates total_laps_remaining by subtracting the number of laps raced by the current function call:
    total_laps_remaining -= num_laps_raced;

    // Initializes a variable and assigns to it the total laps raced so far:
    const auto total_laps_raced = total_laps - total_laps_remaining; 
    
    // Prints warning to the screen when only one lap remains:
    if(total_laps - total_laps_raced == 1)
        printf("One lap remains!\n");
}

void display_laps() {
    printf("%d laps remain.\n", total_laps_remaining);
}

int main() {
    printf("Race start: ");
    display_laps();
    race_lap(50);
    printf("Race middle: ");
    display_laps();
    race_lap(19);
    printf("Race end: ");
    display_laps();
}