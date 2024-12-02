// Passing arrays as arguments:
#include <cstdio>

struct F1Team {
    char name[256];
};

// Takes a pointer-F1Team argument:
// teams is a pointer to the first Team element.
// n_teams is the number of elements.
void print_names(F1Team* teams, size_t n_teams) {
    for (size_t i = 0; i < n_teams; ++i)
        printf("%s Team\n", teams[i].name);
}

int main() {
    F1Team best_teams[] = {"Ferrari", "McLaren", "Red Bull", "Mercedes"};
    print_names(best_teams, 4);
}