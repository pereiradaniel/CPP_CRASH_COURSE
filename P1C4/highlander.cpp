#include <cstdio>

struct Highlander {
    Highlander(const Highlander&) = delete;
    Highlander& operator=(const Highlander&) = delete;
};

int main() {
    // Will generate a compiler error!
    Highlander a;
    Highlander b{ a };
}

// /cpp_crash_course/P1C4$ g++ -g highlander.cpp -o highlander
// highlander.cpp: In function ‘int main()’:
// highlander.cpp:10:16: error: no matching function for call to ‘Highlander::Highlander()’
//    10 |     Highlander a;
//       |                ^
// highlander.cpp:4:5: note: candidate: ‘Highlander::Highlander(const Highlander&)’ (deleted)
//     4 |     Highlander(const Highlander&) = delete;
//       |     ^~~~~~~~~~
// highlander.cpp:4:5: note:   candidate expects 1 argument, 0 provided
// highlander.cpp:11:21: error: use of deleted function ‘Highlander::Highlander(const Highlander&)’
//    11 |     Highlander b{ a };
//       |                     ^
// highlander.cpp:4:5: note: declared here
//     4 |     Highlander(const Highlander&) = delete;
//       |     ^~~~~~~~~~