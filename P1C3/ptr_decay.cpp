// Illustrates an array decaying into a pointer
#include <cstdio>

struct F1Team {
    char name[256];
};

void print_names(F1Team* team_ptr) {
    printf("%s Team\n", team_ptr->name);
}

int main() {
    F1Team best_teams[] = {"Ferrari", "McLaren", "Red Bull", "Mercedes"};
    print_names(best_teams);
}