//
// Created by MAHMOUD on 3/24/2023.
//

#ifndef PLAYGROUND_ARRAY_H
#define PLAYGROUND_ARRAY_H

#include <iostream>


template <typename T>
class DynamicArray {
public:
    /* Constructors */
    explicit DynamicArray(int size);
    DynamicArray();

    /* Destructor */
    ~DynamicArray();

    /* Constant methods */
    int indexOf(T element) const;
    void print() const;
    int getSize() const;
    T operator[](int i) const ;


    /* Non-Constant Methods */
    void insert(T element);
    void removeAt(int index);


private:

    int size = 1;
    T* elements;
    int lastElementIndex = -1;
    void expand();
};

/* Constructors */

template<typename T>
DynamicArray<T>::DynamicArray(int size) :size{size} {
    elements = new T[size];
}
template<typename T>
DynamicArray<T>::DynamicArray() {
    elements = new T[size] ;
}

/* Destructor */

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] elements;
    elements = nullptr;
}
/* Constant Methods */

template <typename T>
int DynamicArray<T>::indexOf(T element) const{
    for (int i = 0; i <= lastElementIndex; ++i) {
        if (elements[i] == element) return i;
    }
    return -1;
}

template<typename T>
void DynamicArray<T>::print() const{
    for (int i = 0; i <= lastElementIndex; ++i) {
        std::cout << elements[i]<<" ";
    }
    std::cout << "\n";
}

template<typename T>
int DynamicArray<T>::getSize() const {
    return (lastElementIndex+1);
}

/* Non-Constant Methods */

template <typename T>
void DynamicArray<T>::expand(){
    T* temp = new T[size*2];

    for (int i = 0; i < size; ++i) {
        temp[i] = elements[i];
    }
    size*=2;

    delete[] elements;
    elements = temp;
    temp = nullptr;
}

template<typename T>
void DynamicArray<T>::insert(T element) {
    if (lastElementIndex == size-1) expand();
    elements[lastElementIndex + 1] = element;
    lastElementIndex++;
}

template<typename T>
void DynamicArray<T>::removeAt(int index) {
    if (index < 0 || index >lastElementIndex) throw std::out_of_range("Index out of range");

    for (int i = index ; i < lastElementIndex; ++i) {
        elements[i] = elements[i+1];
    }
    lastElementIndex--;
}

/** Operators **/
template<typename T>
T DynamicArray<T>::operator[](int i) const{
    if( i > size ) {
        throw std::out_of_range("index");
    }

    return elements[i];
}

#endif //PLAYGROUND_ARRAY_H
