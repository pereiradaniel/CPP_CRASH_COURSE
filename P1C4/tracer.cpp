// tracer.cpp
// Description:
//  Demonstrates an example for each of the storage durations.
//  A message will be printed every time a TRACER object is constructed or destructed.
// This will allow you to investigate object life cycles, as you will clearly be able to see when an object's life cycle is beginning or ending.

#include <cstdio>

struct Tracer {
    Tracer(const char* name) :
        name {name} {
            // Prints a message whenever a TRACER object is created:
            printf("%s constructed.\n", name);
        }
    ~Tracer() {
        // Prints a message whenever a TRACER object is destroyed: 
        printf("%s destructed.\n", name);
    }
    
    private:
        const char* const name;
};

// Tracer with a STATIC DURATION:
static Tracer static_duration_tracer_t1{"Static Variable"};

// Tracer with a THREAD-LOCAL DURATION:
thread_local Tracer thread_local_duration_t2{"Thread-local variable"};

int main() {
    const auto t2_ptr = &thread_local_duration_t2;
    
    printf("A\n");
    
    // Tracer with AUTOMATIC DURATION: 
    Tracer automatic_duration_t3("Automatic variable");
    // As an automatic variable, scope of t3 is bounded by the enclosing function main().
    
    printf("B\n");
    
    // Tracer with DYNAMIC DURATION:
    const auto* dynamic_duration_t4 = new Tracer("Dynamic variable.");
    // This will leak memory because it is not deallocated properly!
    // Because there is no command to delete t4.
    
    printf("C\n");
}

// MEMORY LEAK:

// daniel@ideapad:~/github/CPP_CRASH_COURSE/P1C4$ valgrind ./tracer 
// ==46519== Memcheck, a memory error detector
// ==46519== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==46519== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==46519== Command: ./tracer
// ==46519== 
// Static Variable constructed.
// Thread-local variable constructed.
// A
// Automatic variable constructed.
// B
// Dynamic variable. constructed.
// C
// Automatic variable destructed.
// Thread-local variable destructed.
// Static Variable destructed.
// ==46519== 
// ==46519== HEAP SUMMARY:
// ==46519==     in use at exit: 8 bytes in 1 blocks
// ==46519==   total heap usage: 4 allocs, 3 frees, 74,792 bytes allocated
// ==46519== 
// ==46519== LEAK SUMMARY:
// ==46519==    definitely lost: 8 bytes in 1 blocks
// ==46519==    indirectly lost: 0 bytes in 0 blocks
// ==46519==      possibly lost: 0 bytes in 0 blocks
// ==46519==    still reachable: 0 bytes in 0 blocks
// ==46519==         suppressed: 0 bytes in 0 blocks
// ==46519== Rerun with --leak-check=full to see details of leaked memory
// ==46519== 
// ==46519== For lists of detected and suppressed errors, rerun with: -s
// ==46519== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)