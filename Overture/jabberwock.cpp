#include <cstdio>

namespace Creature {
    struct Jabberwock{
        void* tylgey_wood;
        int is_galumphing;
    };
}

namespace Func {
    void Jabberwock() {
        printf("Burble!");
    }
}

using namespace Creature;

int main() {
    Jabberwock x;
    Func::Jabberwock(); // not part of the Creature namespace
}