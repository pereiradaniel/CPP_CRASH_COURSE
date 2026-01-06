#include <cstdio>
#include <stdexcept>

struct CyberdyneSeries800 {
    CyberdyneSeries800() {
        printf("I'm a friend of Sarah Connor.");
    }
    ~CyberdyneSeries800() {
        throw std::runtime_error{"I'll be back."};
    }
};

int main() {
    try {
        CyberdyneSeries800 t800;
        throw std::runtime_error{"Come with me if you want to live."};
    } catch(const std::exception& e) {
        printf("Caught exception: %s\n", e.what());
    }
}

// std::terminate will be called!

// Output when run with Valgrind:

// daniel@ideapad:~/github/CPP_CRASH_COURSE/P1C4$ valgrind ./throw 
// ==9388== Memcheck, a memory error detector
// ==9388== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
// ==9388== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
// ==9388== Command: ./throw
// ==9388== 
// terminate called after throwing an instance of 'std::runtime_error'
//   what():  I'll be back.
// ==9388== 
// ==9388== Process terminating with default action of signal 6 (SIGABRT)
// ==9388==    at 0x4BB7B2C: __pthread_kill_implementation (pthread_kill.c:44)
// ==9388==    by 0x4BB7B2C: __pthread_kill_internal (pthread_kill.c:78)
// ==9388==    by 0x4BB7B2C: pthread_kill@@GLIBC_2.34 (pthread_kill.c:89)
// ==9388==    by 0x4B5E27D: raise (raise.c:26)
// ==9388==    by 0x4B418FE: abort (abort.c:79)
// ==9388==    by 0x4912FF4: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==9388==    by 0x49280D9: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==9388==    by 0x49128E5: __cxa_call_terminate (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==9388==    by 0x49278B9: __gxx_personality_v0 (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==9388==    by 0x4B0DB05: ??? (in /usr/lib/x86_64-linux-gnu/libgcc_s.so.1)
// ==9388==    by 0x4B0E1F0: _Unwind_RaiseException (in /usr/lib/x86_64-linux-gnu/libgcc_s.so.1)
// ==9388==    by 0x4928383: __cxa_throw (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.33)
// ==9388==    by 0x109423: CyberdyneSeries800::~CyberdyneSeries800() (in /home/daniel/github/CPP_CRASH_COURSE/P1C4/throw)
// ==9388==    by 0x1092F0: main (in /home/daniel/github/CPP_CRASH_COURSE/P1C4/throw)
// ==9388== 
// ==9388== HEAP SUMMARY:
// ==9388==     in use at exit: 75,136 bytes in 6 blocks
// ==9388==   total heap usage: 7 allocs, 1 frees, 75,168 bytes allocated
// ==9388== 
// ==9388== LEAK SUMMARY:
// ==9388==    definitely lost: 0 bytes in 0 blocks
// ==9388==    indirectly lost: 0 bytes in 0 blocks
// ==9388==      possibly lost: 202 bytes in 2 blocks
// ==9388==    still reachable: 74,934 bytes in 4 blocks
// ==9388==                       of which reachable via heuristic:
// ==9388==                         stdstring          : 96 bytes in 2 blocks
// ==9388==         suppressed: 0 bytes in 0 blocks
// ==9388== Rerun with --leak-check=full to see details of leaked memory
// ==9388== 
// ==9388== For lists of detected and suppressed errors, rerun with: -s
// ==9388== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
// Aborted (core dumped)
