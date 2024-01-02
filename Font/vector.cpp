#include "vector.h"

template <typename T>
Vector<T>::Vector() : data(nullptr), currentSize(0), capacity(0) {}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> initList) : Vector() {
    for (const T& value : initList) {
        push_back(value);
    }
}

template <typename T>
void Vector<T>::push_back(const T& value) {
    if (currentSize == capacity) {
        resize();
    }
    data[currentSize++] = value;
}

template <typename T>
size_t Vector<T>::size() const {
    return currentSize;
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template <typename T>
void Vector<T>::resize() {
    size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newData = new T[newCapacity];
    for (size_t i = 0; i < currentSize; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template <typename T>
T* Vector<T>::begin() {
    return data;
}

template <typename T>
void Vector<T>::erase(size_t index) {
    if (index >= currentSize) {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = index; i < currentSize - 1; ++i) {
        data[i] = data[i + 1];
    }

    --currentSize;
}

template <typename T>
bool Vector<T>::empty() const {
    return currentSize == 0;
}


template <typename T>
void Vector<T>::emplace_back(T&& value) {
    if (currentSize == capacity) {
        resize();
    }
    data[currentSize++] = std::move(value);
}

template <typename T>
const T& Vector<T>::back() const {
    if (currentSize == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[currentSize - 1];
}

template class Vector<Color>;