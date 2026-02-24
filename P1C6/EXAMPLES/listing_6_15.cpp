#include <cstdio>
#include <utility>

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
struct Tracer {
  Tracer(const char* name)
      : name{ name } {
    // Print a message to indicate that the Tracer object has been constructed, including its name for clarity. This helps us track the lifecycle of the Tracer objects as they are created and destroyed, especially in the context of move semantics where ownership of resources is transferred:
    printf("%s constructed.\n", name);
  }
  ~Tracer() {
    printf("%s destructed.\n", name);
  }

  private:
  const char* const name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr) {
  // Use the get() method of ptr_a to obtain the raw pointer to the Tracer object and print its address. This allows us to verify that the ownership of the Tracer object has been successfully transferred to the consumer function through move semantics, and that the unique pointer is managing the resource correctly:
  printf("(cons) consumer_ptr: 0x%p\n", consumer_ptr.get());
}

int main() {
  auto ptr_a = SimpleUniquePointer<Tracer>(new Tracer{ "ptr_a" });
  printf("(main) ptr_a: 0x%p\n", ptr_a.get());
  // Use std::move to transfer ownership of the Tracer object from ptr_a to the consumer function. This allows us to demonstrate move semantics in action, where the unique pointer's resource is moved rather than copied, ensuring that there is only one owner of the resource at any given time (notice that this address matches the one printed in the consumer function, confirming that ownership has been transferred):
  consumer(std::move(ptr_a));
  
  // Now that consumer_ptr owns the Trace, use the get() method of consumer_ptr to retrieve the address of Tracer object and print it. This confirms that the ownership of the Tracer object has been successfully transferred to the consumer function through move semantics, and that ptr_a no longer owns the resource (notice that this address is null, confirming that ptr_a has relinquished ownership):
  printf("(main) ptr_a: 0x%p\n", ptr_a.get());

  // When consumer returns, the destructor of consumer_ptr will be called, which will in turn call the destructor of the Tracer object it owns. As a result, ptr_a will be left with a null pointer, and the Tracer object will be properly destroyed without any memory leaks or double deletion issues, demonstrating the correct use of move semantics and unique ownership in C++.
}
