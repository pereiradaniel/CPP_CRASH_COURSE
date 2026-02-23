// Listing 6-3

// encased_solo parameter is a const reference, any attempt to modify it would result in a compiler error. However, by using const_cast, we can remove the const qualifier and modify the value.

#include <cstdio>

void carbon_thaw(const int& encased_solo) {
    // encased_solo++; // error: increment of read-only reference 

    // Use const_cast to remove the const qualifier and modify the value:
    auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
    hibernation_sick_solo++;
}