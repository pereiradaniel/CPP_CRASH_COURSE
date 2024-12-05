// Traverses a linked list of type Championship to display the World Driver's and Constructor's Championship along with the year:
#include <cstdio>
#include <string>

// Struct for F1 World Championship data for a year:
struct Championship {
    // Constructor that takes data and address of list to insert this after:
    Championship
    (short year, std::string champ_name, std::string constructors_name, Championship* championship)
    : championship_year{year}, champion{champ_name}, constructors{constructors_name} {
        this->insert_after(championship);
    }
    
    // Constructor that takes data but no insertion into list:
    Championship
    (short year, std::string champ_name, std::string constructors_name)
    : championship_year{year}, champion{champ_name}, constructors{constructors_name} {
    }

    Championship() {};

    private:
        short championship_year;    // year of championship
        // Use std::string instead of c-style strings so that initializer member list does not generate error converting from const char*:
        std::string champion;       // name of world driver's champion
        std::string constructors;   // name of constructor's champion

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
    // Use const arguments to protect data:
    void set_champion(const char champions_name[]) {
        champion = champions_name;
    }
    
    void set_year(const short year) {
        championship_year = year; 
    }

    void set_constructors_champion(const char constructors_champion[]) {
        constructors = constructors_champion;
    }

    // GETTERS
    // Use const to protect Class members:
    short get_year() const {
        return championship_year;
    }

    std::string get_champion() const {
        return champion;
    }

    std::string get_constructors_champion() const {
        return constructors;
    }

    // Displays Element data:
    void display() const {
        printf("Year: %d\n", championship_year);
        printf("Constructor's champions: %s\n", constructors.c_str());
        printf("Driver's Champion: %s\n", champion.c_str());
    }
};

int main() {
    Championship championship1996, championship1997, championship1998;
    
    Championship championship1995 = {1995, "Michael Schumacher", "Bennetton-Renault", &championship1996};

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

    for (auto *cursor = &championship1995; cursor; cursor = cursor->next)
        cursor->display();

    return 0;
}