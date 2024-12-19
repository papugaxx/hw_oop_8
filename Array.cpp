#include "Array.h"
#include <iostream>

template <typename T>
Array<T>::Array() {
    arr = nullptr;
    size = 0;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
void Array<T>::resize(int newSize) {
  
    T* newArr = new T[newSize];
    int elementsToCopy;

    if (newSize < size) {
        elementsToCopy = newSize;
    }
    else {
        elementsToCopy = size;
    }

    for (int i = 0; i < elementsToCopy; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr; 
    arr = newArr; 
    size = newSize;
}

template <typename T>
int Array<T>::GetSize() const {
    return size;
}

template <typename T>
void Array<T>::SetSize(int newSize) {
    resize(newSize);
}

template <typename T>
int Array<T>::GetUpperBound() const {
    return arr[size - 1];
}

template <typename T>
bool Array<T>::IsEmpty() const {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void Array<T>::FreeExtra() {
    resize(size);
}

template <typename T>
void Array<T>::RemoveAll() {
    delete[] arr;
    arr = nullptr;
    size = 0;
}

template <typename T>
T Array<T>::GetAt(int index) const {

    return arr[index];
}

template <typename T>
void Array<T>::SetAt(int index, const T& value) {

    arr[index] = value;
}

template <typename T>
T& Array<T>::operator[](int index) {
  
    return arr[index];
}

template <typename T>
void Array<T>::Add(const T& value) {
    resize(size + 1);
    arr[size - 1] = value; 
}

template <typename T>
void Array<T>::Append(const Array<T>& other) {
    int newSize = size + other.size;
    T* newArr = new T[newSize];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    for (int i = 0; i < other.size; i++) {
        newArr[size + i] = other.arr[i];
    }
    delete[] arr;
    arr = newArr;
    size = newSize;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    delete[] arr;
    size = other.size;
    arr = new T[size];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
    Array<T> result = other;
    return result;
}

template <typename T>
void Array<T>::InsertAt(int index, const T& value) {

    resize(size + 1);
    for (int i = size - 1; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
}

template <typename T>
void Array<T>::RemoveAt(int index) {
 
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    resize(size - 1);
}

template class Array<int>;
