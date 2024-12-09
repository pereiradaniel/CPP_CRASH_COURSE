// Daniel Pereira 2024

// Illustrates an array decaying into a pointer
#include <cstdio>

struct F1Team {
    char name[256];
};

// Takes a pointer-F1Team argument:
void print_names(F1Team* team_ptr) {
    // name decays to a pointer to satisfy printf
    printf("%s Team\n", team_ptr->name);
}

int main() {
    F1Team best_teams[] = {"Ferrari", "McLaren", "Red Bull", "Mercedes"};
    
    // best_teams decays to a pointer when print_names() is called:
    print_names(best_teams);
}