#include <iostream>
#include <cstddef>
template <typename T>

class UniquePtr{
 private:
    T * ptr;

 public:
    explicit UniquePtr()
            :ptr(nullptr) {}
    explicit UniquePtr(T * ptr)
            :ptr(ptr) {}
    explicit UniquePtr(UniquePtr&& other)
            :ptr(other.ptr) {
        other.ptr = nullptr;
    }
    UniquePtr& operator = (std::nullptr_t) {
        ptr = nullptr;
        return *this;
    }
    UniquePtr(const UniquePtr&) noexcept = delete;
    void operator = (const UniquePtr&) noexcept = delete;
    UniquePtr& operator = (UniquePtr&& other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
        return *this;
    }
    ~UniquePtr() {
        delete ptr;
    }
    const T& operator * () const {
        return *ptr;
    }
    T& operator * () {
        return *ptr;
    }
    T* operator -> () const {
        return ptr;
    }
    T* release() {
        T * tmp = ptr;
        ptr = nullptr;
        return tmp;
    }
    void reset(T * other) {
        delete ptr;
        ptr = other;
    }
    void swap(UniquePtr &other) {
        T * tmp = ptr;
        ptr = other.ptr;
        other.ptr = tmp;
    }
    T * get() const {
        return ptr;
    }
    explicit operator bool() const {
        return ptr != nullptr;
    }
};

