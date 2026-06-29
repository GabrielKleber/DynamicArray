#pragma once
#include <iostream>

enum class ArrayError
{
    OK,
    OUT_OF_BOUNDS,
    EMPTY_ARRAY,
    ALLOCATION_ERROR
};

template<typename T>
struct Result
{
    ArrayError error;
    T value;

    Result(ArrayError e)
        : error(e)
    {}

    Result(ArrayError e, T v)
        : error(e), value(v)
    {}
};

template<typename T>
class Array
{
private:
    T* data;
    int m_size;
    int m_capacity;

public:
    Array();
    ~Array();

    Result<T> push(T value);
    Result<T> pop();

    Result<T> insert(T value, int index);
    Result<T> remove(int index);

    Result<T> get(int index) const;
    Result<T> replace(int index, T value);

    Result<T> clear();
    Result<T> shrinkToFit();

    int size() const;
    int capacity() const;
    bool isEmpty() const;

    T* begin() const;
    T* end()const;

    void print() const;
};

template<typename T>
Array<T>::Array() {
    data = nullptr;
    m_size = 0;
    m_capacity = 0;
}

template<typename T>
Array<T>::~Array() {
    delete[] data;
}

template<typename T>
Result<T> Array<T>::push(T value) {

    if(m_size == m_capacity) {
        int newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newData = new T[newCapacity];

        for(int i = 0; i < m_size; i++) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        m_capacity = newCapacity;
    }

    data[m_size] = value;
    m_size++;

    return {ArrayError::OK};
}

template<typename T>
Result<T> Array<T>::pop() {
    T value = data[m_size -1];
    int newCapacity = m_capacity;
    T* newData;

    if(m_size == 0) {
        return {ArrayError::EMPTY_ARRAY};
    }

    if(m_capacity > 1 && m_size - 1 <= m_capacity / 2) {
        newCapacity = (m_capacity/2);
    } else {
        newCapacity = (m_capacity);
    }

    newData = new T[newCapacity];

    for(int i = 0; i < (m_size-1); i++) {
        newData[i] = data[i];
    }

    delete[] data;

    data = newData;
    m_capacity = newCapacity;

    m_size--;

    return {ArrayError::OK, value};
}

template<typename T>
Result<T> Array<T>::insert(T value, int index) {
    int newCapacity = m_capacity;
    T* newData;

    if(index < 0 || index > m_size) {
        return {ArrayError::OUT_OF_BOUNDS};
    }

    if(m_size == m_capacity) {
        newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
    }

    newData = new T[newCapacity];

    for(int i = 0; i < index; i++) {
        newData[i] = data[i];
    }

    newData[index] = value;

    for(int i = index; i < m_size; i++) {
        newData[i+1] = data[i];
    }

    if(m_size == index) {
        newData[index] = value;
    }

    delete[] data;

    data = newData;
    m_capacity = newCapacity;

    m_size++;

    return {ArrayError::OK};
}

template<typename T>
Result<T> Array<T>::remove(int index) {
    T value = data[index]
    int newCapacity = m_capacity;
    T* newData;

    if(m_size == 0) {
        return {ArrayError::EMPTY_ARRAY};
    }
    if(index < 0 || index >= m_size) {
        return {ArrayError::OUT_OF_BOUNDS};
    }

    if(m_capacity > 1 && m_size - 1 <= m_capacity / 2) {
        newCapacity = (m_capacity/2);
    }

    newData = new T[newCapacity];

    for(int i = 0; i < index; i++) {
        newData[i] = data[i];
    }

    for(int i = index+1; i < m_size; i++) {
        newData[i-1] = data[i];
    }

    delete[] data;

    data = newData;
    m_capacity = newCapacity;

    m_size--;

    return {ArrayError::OK, value};
}

template<typename T>
Result<T> Array<T>::get(int index) const {

    if(index < 0 || index >= m_size) {
        return {ArrayError::OUT_OF_BOUNDS};
    }

    return {ArrayError::OK, data[index]};
}

template<typename T>
Result<T> Array<T>::replace(int index, T value) {
    if(index < 0 || index >= m_size) {
        return {ArrayError::OUT_OF_BOUNDS};
    }

    T oldValue = data[index];

    data[index] = value;

    return {ArrayError::OK, oldValue};
}

template<typename T>
Result<T> Array<T>::clear() {
    m_size = 0;

    return {ArrayError::OK};
}

template<typename T>
Result<T> Array<T>::shrinkToFit() {
    T* newData = new T[m_size];

    for(int i = 0; i < m_size; i++) {
        newData[i] = data[i];
    }

    delete[] data;

    data = newData;
    m_capacity = m_size;

    return {ArrayError::OK};
}

template<typename T>
int Array<T>::size() const {
    return m_size;
}

template<typename T>
int Array<T>::capacity() const {
    return m_capacity;
}

template<typename T>
bool Array<T>::isEmpty() const {
    return m_size == 0;
}

template<typename T>
T* Array<T>::begin() const {
    return data;
}

template<typename T>
T* Array<T>::end() const {
    return data + m_size;
}

template<typename T>
void Array<T>::print() const {
    for(auto p = begin(); p != end(); p++) {
        std::cout << *p;

        if(p+1 != end()) {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
}
