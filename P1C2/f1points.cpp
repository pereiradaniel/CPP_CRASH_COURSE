#include <cstdio>

// Data structure containing points scoring system:
const struct Points {
    // Feature Race points system:
    int first = 25;
    int second = 18;
    int third = 15;
    int fourth = 12;
    int fifth = 10;
    int sixth = 8;
    int seventh = 6;
    int eighth = 4;
    int ninth = 2;
    int tenth = 1;

    // Sprint Race points system:
    int first_sprint = 8;
    int second_sprint = 7;
    int third_sprint = 6;
    int fourth_sprint = 5;
    int fifth_sprint = 4;
    int sixth_sprint = 3;
    int seventh_sprint = 2;
    int eighth_sprint = 1;

    // Fastest Lap points system:
    int fastest_lap =1;
} points;

// Struct for a driver's total points over a season:
struct F1DriverPoints {
    int total_points;   // Driver's total points
    
    // Calculates the number of points awarded for fastest laps:
    void fastest_lap (int multiplier) {
        for (int i = 1; i <= multiplier; ++i)
            total_points += points.fastest_lap;
    };

    // Calculates how many points earned for finishing position in a Sprint Race:
    void sprint_race_points(int position) {
        if (position == 1)
            total_points += points.first_sprint;
        if (position == 2)
            total_points += points.second_sprint;
        if (position == 3)
            total_points += points.third_sprint;
        if (position == 4)
            total_points += points.fourth_sprint;
        if (position == 5)
            total_points += points.fifth_sprint;
        if (position == 6)
            total_points += points.sixth_sprint;
        if (position == 7)
            total_points += points.seventh_sprint;
        if (position == 8)
            total_points += points.eighth_sprint; 
    }

    // Calculates how many points earned for finishing position in a Feature Race:
    void feature_race_points(int position) {
        if (position == 1)
            total_points += points.first;
        if (position == 2)
            total_points += points.second;
        if (position == 3)
            total_points += points.third;
        if (position == 4)
            total_points += points.fourth;
        if (position == 5)
            total_points += points.fifth;
        if (position == 6)
            total_points += points.sixth;
        if (position == 7)
            total_points += points.seventh;
        if (position == 8)
            total_points += points.eighth;
        if (position == 9)
            total_points += points.ninth;
        if (position == 10)
            total_points += points.tenth;
    }
};

void fr_add_points_to_driver(int multiplier, int position, struct F1DriverPoints &driver) {
    for (int i = 1; i <= multiplier; ++i)
        driver.feature_race_points(position);
}

void sr_add_points_to_driver(int multiplier, int position, struct F1DriverPoints &driver) {
    for (int i = 1; i <= multiplier; ++i)
        driver.sprint_race_points(position);
}

int main() {
    F1DriverPoints verstappen;
    verstappen.total_points = 0;
    
    // FEATURE RACE POINTS TALLY
    // Add 1st place finish points:
    fr_add_points_to_driver(8, 1, verstappen);
        
    // Add 2nd place finish points:
    fr_add_points_to_driver(4, 2, verstappen);
    
    // Add 3rd place finish points:
    fr_add_points_to_driver(1, 3, verstappen);
    
    // Add 4th place finish points:
    fr_add_points_to_driver(1, 4, verstappen);
    
    // Add 5th place finish points:
    fr_add_points_to_driver(4, 5, verstappen);

    // Add 6th place finish points:
    fr_add_points_to_driver(3, 6, verstappen);

    // SPRINT RACE POINTS TALLY
    // Add 1st place finish points:
    
    sr_add_points_to_driver(4, 1, verstappen);
    // Add 4th place finish points:
    sr_add_points_to_driver(1, 4, verstappen);

    // Add points for number of fastest laps:
    verstappen.fastest_lap(3);

    printf("Max Verstappen total points: %d\n", verstappen.total_points);
}

// Max Verstappen's points for 2024 season as of 27/Nov/2024 = 403