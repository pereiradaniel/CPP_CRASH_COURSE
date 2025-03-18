#include <cstdio>

struct Book {
    char name[256];
    int year;
    int pages;
    bool harcover;
};

int main() {
    Book lotr;
    lotr.pages = 2000;
    printf("The Lord Of The Rings has %d pages.", lotr.pages);
}