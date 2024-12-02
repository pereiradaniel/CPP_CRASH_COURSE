// Demonstrates use of reference instead of pointer:
#include <cstdio>
struct F1Team {
    // Declares and initializes total_points to 0:
    int total_points{};

    // Sets total_points to points:
    void set_points(int points){
        total_points = points;
    }

    // Returns total_points:
    int get_total_points(){
        return total_points;
    }
};

// Uses reference to team to add points:
void add_points(F1Team& team){
    team.set_points(team.get_total_points() + 1);
};

int main() {
    F1Team ferrari;
    printf("Points: %d\n", ferrari.get_total_points());
    
    // ferrari is passed by reference
    add_points(ferrari);
    
    printf("Points: %d\n", ferrari.get_total_points());
}
