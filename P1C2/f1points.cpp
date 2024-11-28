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
    int fastest_lap = 1;
} points;

// Struct for a driver's total points over a season:
struct F1DriverPoints {
    private:    // private members
        float total_points;   // Driver's total points;

    public:     // public members

        // Constructors
        // With no arguments, total_points defaults to 0.
        F1DriverPoints() {
            total_points = 0;
        }
        
        // Constructor that takes an existing and known amount of points to initialize a driver.
        F1DriverPoints(float points) {
            total_points += points;
        }
        
        // Constructor that takes an array of points per season and an int to represent number of seasons.
        F1DriverPoints(float points[], int size) {
            float sum = 0;
    
            for (int i = 0; i <= size; ++i )
                sum += points[i];
    
            total_points = sum;
        }

        // Calculates the number of points awarded for fastest laps:
        // Takes parameter multiplier to represent number of times fastest lap has been awarded.
        void fastest_lap (int multiplier) {
            for (int i = 1; i <= multiplier; ++i)
                total_points += points.fastest_lap;
        };

        // Adds points to driver's score for Feature Races.
        // Calculates using number of times the specified finish position has been achieved:
        //      fr_add_points_to_driver(4, 1, verstappen);
        //      // Adds 4 x 1st place points to F1DriverPoints verstappen.
        void fr_add_points_to_driver(int multiplier, int position, struct F1DriverPoints &driver) {
            for (int i = 1; i <= multiplier; ++i)
                driver.feature_race_points(position);
        }

        // Adds points to driver's score for Sprint Races. Same as fr_add_points_to_driver().
        void sr_add_points_to_driver(int multiplier, int position, struct F1DriverPoints &driver) {
            for (int i = 1; i <= multiplier; ++i)
                driver.sprint_race_points(position);
        }

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

        // Getter for total_points.
        float get_total_points() {
            return total_points;
        }
};

int main() {
    // Create F1DriverPoints driver for Max Verstappen:
    F1DriverPoints verstappen;
    
    // CALCULATE MAX VERSTAPPEN'S 2024 FORMULA 1 POINTS:
    
    // FEATURE RACE POINTS TALLY
    // Add 1st place finish points:
    verstappen.fr_add_points_to_driver(8, 1, verstappen);
        
    // Add 2nd place finish points:
    verstappen.fr_add_points_to_driver(4, 2, verstappen);
    
    // Add 3rd place finish points:
    verstappen.fr_add_points_to_driver(1, 3, verstappen);
    
    // Add 4th place finish points:
    verstappen.fr_add_points_to_driver(1, 4, verstappen);
    
    // Add 5th place finish points:
    verstappen.fr_add_points_to_driver(4, 5, verstappen);

    // Add 6th place finish points:
    verstappen.fr_add_points_to_driver(3, 6, verstappen);

    // SPRINT RACE POINTS TALLY
    // Add 1st place finish points:
    verstappen.sr_add_points_to_driver(4, 1, verstappen);
    
    // Add 4th place finish points:
    verstappen.sr_add_points_to_driver(1, 4, verstappen);

    // Add points for number of fastest laps:
    verstappen.fastest_lap(3);

    // Max Verstappen's points for 2024 season as of 27/Nov/2024 = 403
    printf("Max Verstappen total points: %.2f\n", verstappen.get_total_points());

    
    // CALCULATE MAX VERSTAPPEN'S POINTS FROM 2015-2023

    // verstappen_career_points 2015-2023:
    // 2023 = 575
    // 2022 = 454
    // 2021 = 395.5
    // 2020 = 214
    // 2019 = 278
    // 2018 = 249
    // 2017 = 168
    // 2016 = 204
    // 2015 = 49
    // 948
    // 1 351

    // Creates an array of points scores for the first nine season of Max Verstappen's career:
    float verstappen_career_points[9] = {49,204,168,249,278,214,395.5,454,575};
    
    // Initialize a points score for Verstappen's 2015-2023 career by using the array and the two-argument constructor:
    F1DriverPoints verstappen_career(verstappen_career_points, 9);

    // Displays Verstappen's total points from 2015-2023 using the get_total_points() getter:
    printf("Max Verstappen's total F1 career points from 2015-2023: %.2f\n", verstappen_career.get_total_points());
    
    // Displays Verstappen's total career points from 2015-2024 by summing the results of two getter function calls:
    printf("Max Verstappen's total F1 career points from 2015-2024: %.2f\n", (verstappen_career.get_total_points() + verstappen.get_total_points()));

    return 0;
}