// Check system's integer type sizes:
#include <cstddef>
#include <cstdio>
int main() {
    size_t size_c = sizeof(char);
    printf("char: %zu\n", size_c);
    
    size_t size_s = sizeof(short);
    printf("short: %zu\n", size_s);
    
    size_t size_i = sizeof(int);
    printf("int: %zu\n", size_i);

    size_t size_l = sizeof(long);
    printf("long: %zu\n", size_l);

    size_t size_ll = sizeof(long long);
    printf("long long: %zu\n", size_ll);
    return 0;
}

// Compiled on Windows:
///////////////////////

// Microsoft (R) C/C++ Optimizing Compiler Version 19.35.32215 for x86
// Copyright (C) Microsoft Corporation.  All rights reserved.

// checkinttypesizes.cpp
// Microsoft (R) Incremental Linker Version 14.35.32215.0
// Copyright (C) Microsoft Corporation.  All rights reserved.

// /out:checkinttypesizes.exe
// checkinttypesizes.obj

// C:\Users\perei\source\repos\cpp_crash_course\P1C2>checkinttypesizes.exe
// char: 1
// short: 2
// int: 4
// long: 4
// long long: 8

// Compiled on Linux:
/////////////////////

// pereira@DESKTOP-HFSS3GK:/mnt/c/Users/perei/source/repos/cpp_crash_course/P1C2$ g++ -g checkinttypesizes.cpp -o checkinttypesizes
// pereira@DESKTOP-HFSS3GK:/mnt/c/Users/perei/source/repos/cpp_crash_course/P1C2$ ./checkinttypesizes
// char: 1
// short: 2
// int: 4
// long: 8
// long long: 8