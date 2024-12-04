// Traverses a linked list of type Championship to display the World Driver's and Constructor's Championship along with the year:
#include <cstdio>
#include <cstring>

// Struct for F1 World Championship data for a year:
struct Championship {
    private:
        short championship_year;    // year of championship
        char champion[50];          // name of world driver's champion
        char constructors[50];      // name of constructor's champion

    public:
    // Each element has a pointer to the next element in the linked list:
    Championship* next{}; // initializes to nullptr

    // Insert a new element using insert_after()
    void insert_after(Championship* new_element) {
        // Sets the next member of the new_element to this.next:
        new_element->next = this->next; // uses 'this' pointer to disambiguate
        // Sets this.next to the new_element:
        this->next = new_element;
    }

    // SETTERS
    void set_champion(const char champions_name[]) {
        std::strcpy(champion, champions_name);  
    }
    
    void set_year(const short year) {
        championship_year = year; 
    }

    void set_constructors_champion(const char constructors_champion[]) {
        std::strcpy(constructors, constructors_champion);
    }

    // GETTERS
    short get_year() {
        return championship_year;
    }

    char* get_champion() {
        return champion;
    }

    char* get_constructors_champion() {
        return constructors;
    }

    // Displays Element data:
    void display() {
        printf("Year: %d\n", championship_year);
        printf("Constructor's champions: %s\n", constructors);
        printf("Driver's Champion: %s\n", champion);
    }
};

int main() {
    Championship championship1996, championship1997, championship1998;
    
    championship1996.set_champion("Damon Hill");
    championship1996.set_constructors_champion("Williams-Renault");
    championship1996.set_year(1996);
    championship1996.insert_after(&championship1997);

    championship1997.set_champion("Jacques Villeneuve");
    championship1997.set_constructors_champion("Williams-Renault");
    championship1997.set_year(1997);
    championship1997.insert_after(&championship1998);

    championship1998.set_champion("Mika Hakkinen");
    championship1998.set_constructors_champion("McLaren-Mercedes");
    championship1998.set_year(1998);

    for (Championship *cursor = &championship1996; cursor; cursor = cursor->next) {
        cursor->display();
    }

    return 0;
}