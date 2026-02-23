// Listing 6-14: A simple unique pointer implementation.

#include <cstddef>

// Announce the template class with a template prefix which establishes T as the wrapped object's type:
template <typename T>
struct SimpleUniquePointer {
    // Specify a default constructor using the default keyword:
    SimpleUniquePointer() = default;
    
    // Default constructor will set the private member T* to nullptr, using the default initialization rules.

    // Non-default constructor that takes a T* and sets the private member pointer to it:
    SimpleUniquePointer(T* pointer)
    : pointer{pointer} {
    }
    
    // Destructor:
    ~SimpleUniquePointer() {
        // Because the pointer is possibly null, we check it before deleting it:
        if (pointer)
        delete pointer;
    }

    // Delete the copy constructor and copy assignment operator to prevent copying of the unique pointer. This is to prevent multiple unique pointers from owning the same resource, which would lead to double deletion issues (also known as double free errors).

    // Copy Constructor:
    SimpleUniquePointer(const SimpleUniquePointer&) = delete;
    
    // Copy Assignment Operator:
    SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;

    // Move Constructor:
    SimpleUniquePointer(SimpleUniquePointer&& other) noexcept
    : pointer{other.pointer} {
        // After moving the pointer from other to this, we set other's pointer to nullptr to indicate that it no longer owns the resource:
        other.pointer = nullptr;

        // Once the move constructor returns, the moved-from object is destroyed, and its destructor will not delete the resource because its pointer is now nullptr.
    }

    // Move Assignment Operator:
    SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept {
        // Check explicitly for prior ownership of a resource by this unique pointer. If it does own a resource (i.e., if pointer is not null), we delete it to free the resource before taking ownership of the new resource from other. Otherwise, if we just take ownership of the new resource without deleting the old one, we would have a memory leak.
        if(pointer) delete pointer;

        // After the check, we take ownership of the resource from other by moving the pointer as in the copy constructor, and then we set other's pointer to nullptr to indicate that it no longer owns the resource:
        pointer = other.pointer;
        other.pointer = nullptr;
        
        // Finally, we return *this to allow for chaining of move assignment operations:
        return *this;
    }

    // A member function to access the raw pointer:
    T* get() {
        // Obtain direct access to the raw pointer by returning it. This allows users of SimpleUniquePointer to access the underlying resource if needed, while still maintaining ownership semantics through the unique pointer:
        return pointer;
    }

    private:
    T* pointer{};
};