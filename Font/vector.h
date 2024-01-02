#pragma once
#include "C:/raylib/raylib/src/raylib.h"
#include <cstddef>
#include <stdexcept>

template <typename T>
class Vector {
public:
    Vector();
    Vector(std::initializer_list<T> initList);

    void push_back(const T& value);
    size_t size() const;
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    bool empty() const; // Added empty function
    void erase(size_t index); // Added erase function
    T* begin(); // Added begin function
    void emplace_back(T&& value);  // Added emplace_back
    const T& back() const;   


private:
    T* data;
    size_t currentSize;
    size_t capacity;

    void resize();
};
