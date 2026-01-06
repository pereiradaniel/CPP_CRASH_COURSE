// Exercise 3-3:
// Add an Element* previous to Listing 3-9 to make a doubly linked list.
// Add an insert_before method to Element.
// Traverse the list from front to back, then from back to front, using two separate for loops.
// Print the operating_number inside each loop.
#include <cstdio>

struct Element {
    // Each element will have a pointer to the next and previous elements in the linked list:
    Element* next{};        // Pointer to the next element:
    Element* previous{};    // Pointer to the previous element:
    
    void insert_after(Element* new_element) {
        // Set the next pointer of the new element to the next pointer of this element:
        new_element->next = this->next;
        // Set the next pointer of this element to the new_element:
        this->next = new_element;
        // Sets the previous pointer of the new element to this element:
        new_element->previous = this;
    }

    void insert_before(Element* new_element) {
        // Set the next pointer of the new element to this element:
        new_element->next = this;
        // Set the previous pointer of the new element to the previous pointer of this element:
        new_element->previous = this->previous;
        // Set the previous pointer of this element to the new element:
        this->previous = new_element;
    }

    // Each element contains a prefix array:
    char prefix[2];
    // Each element has an operating number:
    short operating_number;
};

int main() {
    Element trooper1, trooper2, trooper3;

    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;

    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;

    trooper2.insert_before(&trooper1);
    trooper2.insert_after(&trooper3);

    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;

    printf("Traverse list from front to back:\n");
    for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("\tstormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number);
    }

    printf("\n");

    printf("Traverse list from back to front:\n");
    for (Element* cursor = &trooper3; cursor; cursor = cursor->previous) {
        printf("\tstormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number);
    }
}