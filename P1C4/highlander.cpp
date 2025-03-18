#include <cstdio>

struct Highlander {
    Highlander(const Highlander&) = delete;
    Highlander& operator=(const Highlander&) = delete;
};

int main() {
    // The following two lines will generate a compiler error! Uncomment and try to compile to view the errors.
    // Highlander a;
    // Highlander b{ a };
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


// c:\cpp_crash_course\P1C4>cl highlander.cpp
// Microsoft (R) C/C++ Optimizing Compiler Version 19.35.32215 for x86
// Copyright (C) Microsoft Corporation.  All rights reserved.

// highlander.cpp
// highlander.cpp(10): error C2512: 'Highlander': no appropriate default constructor available
// highlander.cpp(3): note: see declaration of 'Highlander'