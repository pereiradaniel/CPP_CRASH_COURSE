// Uses an enum class with a switch statement:
#include <cstdio>
// Declares an enum class:
enum class F1Team {
        Alpine,
        AstonMartin,
        Ferrari,
        Haas,
        KickSauber,
        McLaren,
        Mercedes,
        VCaRB,
        RedBullRacing,
        Williams
    };

int main() {
    // Declare a var, myTeam and assign value:
    F1Team myTeam = F1Team::Ferrari;
    // Uses switch statement to output name of selected team:
    switch (myTeam) {
        case F1Team::Alpine:
            printf("Alpine");
            break;
        case F1Team::AstonMartin:
            printf("Aston Martin");
            break;
        case F1Team::Ferrari:
            printf("Ferrari");
            break;
        case F1Team::Haas:
            printf("Haas");
            break;
        case F1Team::KickSauber:
            printf("Kick Sauber");
            break;
        case F1Team::McLaren:
            printf("McLaren");
            break;
        case F1Team::Mercedes:
            printf("Mercedes");
            break;
        case F1Team::VCaRB:
            printf("Visa Cash App Red Bull");
            break;
        case F1Team::RedBullRacing:
            printf("Red Bull Racing");
            break;
        case F1Team::Williams:
            printf("Williams");
            break;
    }
}