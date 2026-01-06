#include <stdio.h>

struct Book {
    char name[256];
    int year;
    int pages;
    // bool harcover;
    int hardcover; // 0 false, 1 true
};

int main(int argc, char* argv[]) {
    struct Book lotr;
    lotr.pages = 2000;
    printf("The Lord Of The Rings has %d pages.", lotr.pages);
    return 0;
}