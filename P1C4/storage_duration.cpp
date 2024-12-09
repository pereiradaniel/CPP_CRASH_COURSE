// Daniel Pereira 2024
#include <cstdio>

static int num_of_races;

struct RaceLapCounter {    
    static const int default_total_laps = 70;

    RaceLapCounter() :
        yellow_flags {0},
        total_laps {default_total_laps},
        total_laps_remaining {total_laps}
    {
        common_initialization_procedure();
    }

    RaceLapCounter(int laps) :
        total_laps {laps},
        total_laps_remaining {total_laps},
        yellow_flags {0}
    {
        common_initialization_procedure();
    }

    RaceLapCounter(int laps, int laps_remaining, int num_yellow_flags) :
        total_laps {laps},
        total_laps_remaining {laps_remaining},
        yellow_flags { num_yellow_flags}
    {
        common_initialization_procedure();
    }

    private:
        int yellow_flags = 0;
        int total_laps = default_total_laps;
        int total_laps_remaining = total_laps;

    public:
        static void common_initialization_procedure() {
            ++num_of_races;
        }

        void race_lap(int num_laps_raced) {
            this->total_laps_remaining -= num_laps_raced;
        }

        void display_remaining_laps() {
            printf("Number of laps remaining: %d\n", this->total_laps_remaining);
        }

        void add_yellow_flags(int num_yellow_flags) {
            this->yellow_flags += num_yellow_flags;
        }

        void display_yellow_flags() const {
            printf("Number of yellow flags shown: %d\n", this->yellow_flags);
        }

        static void display_total_num_of_races() {
            printf("Number of total races this season: %d\n", num_of_races);
        }
};

int main() {
    RaceLapCounter monza;
    printf("Monza start: \n");
    printf("Race start: ");
        monza.display_remaining_laps();

    monza.race_lap(50);
    monza.add_yellow_flags(3);
 
    printf("Race middle: ");
        monza.display_remaining_laps();
        monza.display_yellow_flags();

    monza.race_lap(19);
 
    printf("Race end: ");
        monza.display_remaining_laps();
        monza.race_lap(1);
    
    printf("Race Complete: ");
        monza.display_remaining_laps();
    
    RaceLapCounter::display_total_num_of_races();

    RaceLapCounter monaco(50);
    printf("Monaco start:\n");
        monaco.display_remaining_laps();
        monaco.display_yellow_flags();

    monaco.race_lap(30);
    monaco.add_yellow_flags(4);

    printf("Monaco middle: ");
        monaco.display_remaining_laps();
        monaco.display_yellow_flags();

    monaco.race_lap(20);

    printf("Race Complete: ");
        monaco.display_remaining_laps();
        monaco.display_yellow_flags();

    RaceLapCounter::display_total_num_of_races();
}