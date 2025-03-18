// Reads and writes array elements:
#include <cstdio>
int main() {
    int arr[] = {1, 2, 3, 4};
    printf("Third element of arr[]: %d\n", arr[2]);
    arr[2] = 100; // Writes to the third element of array arr[]
    printf("Third element of arr[] has been updated: %d\n", arr[2]);
    return 0;
}