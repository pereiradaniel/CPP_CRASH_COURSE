#include <cstdio>

struct RatThing {
    static int rat_things_power;
    static void power_up_rat_thing(int nuclear_isotopes) {
        // each thread represents its own rat thing.
        // each copy of rat_things_power is initialized to 200:
        static thread_local int rat_things_power = 200;
        const auto waste_heat = rat_things_power * 20;
        if (waste_heat > 10000) {
            printf("Overheating!\n");
        }
        printf("Rat-thing power: %d\n", rat_things_power);
    }
};

int main() {
    RatThing::power_up_rat_thing(100);
    RatThing::power_up_rat_thing(500);
}