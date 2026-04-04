#include <cstddef>
#include <new>

// The Bucket class is responsible for taking up space in memory.
struct Bucket {
    const static size_t data_size{ 4096 };
    std::byte data[data_size];
};

// The Heap class is responsible for managing the buckets and providing an interface for allocating and freeing memory.
struct Heap {
    // The allocate function is responsible for finding an available bucket and returning a pointer to its data. If no buckets are available, it throws a std::bad_alloc exception.
    void* allocate(size_t bytes) {
        if (bytes > Bucket::data_size) throw std::bad_alloc{};
        for (size_t i{}; i < n_heap_buckets; ++i) {
            if (!bucket_used[i]) {
                bucket_used[i] = true;
                return buckets[i].data;
            }
        }
        throw std::bad_alloc{};
    }

    // The free function is responsible for marking a bucket as available again when the memory it was using is no longer needed. It takes a pointer to the data that was allocated and searches for the corresponding bucket. Once it finds the bucket, it marks it as available by setting the corresponding entry in the bucket_used array to false.
    void free(void* p) {
        for (size_t i{}; i < n_heap_buckets; ++i) {
            if (buckets[i].data == p) {
                bucket_used[i] = false;
                return;
            }
        }
    }

    static const size_t n_heap_buckets{10}; // The number of buckets in the heap.
    Bucket buckets[n_heap_buckets]{};       // Houses all the buckets.
    bool bucket_used[n_heap_buckets]{};     // Keeps track of which buckets are currently in use.

};
