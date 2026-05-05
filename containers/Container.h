#pragma once
#include <iostream>
template<typename T>
class Container {
 private:
    T* pdata;
    int size;
    int max_size;

 public:
    void push(T element);
    void pop(int index);
    void resize(int new_size);

    const T& operator[](int index) const { return pdata[index]; }

    T& operator[](int index) { return pdata[index]; }
    Container& operator=(const Container& other);  // присваивание (глубокое копирование)
    Container& operator=(Container&& other);       // перемещающее присваивание (move)

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Container<U>& c);

    int getSize() const { return size; }

    Container(T element);
    Container();
    Container(const Container&);
    Container(Container&&);
    ~Container();
};

template<typename T>
Container<T>::Container() {
    this->max_size = 8;
    this->size = 0;
    this->pdata = new T[max_size];
}

template<typename T>
Container<T>::Container(T element) {
    max_size = 8;
    size = 1;
    pdata = new T[max_size];
    pdata[0] = element;
}

template<typename T>
Container<T>::Container(const Container& other) {
    this->max_size = other.max_size;
    this->size = other.size;
    pdata = new T[max_size];
    for (int i = 0; i < size; i++)
        pdata[i] = other.pdata[i];
}

template<typename T>
Container<T>::Container(Container&& other) {
    pdata = other.pdata;
    size = other.size;
    max_size = other.max_size;

    other.pdata = nullptr;
    other.size = 0;
    other.max_size = 0;
}

template<typename T>
Container<T>::~Container() {
    delete[] pdata;
    pdata = nullptr;
}

template<typename T>
Container<T>& Container<T>::operator=(const Container& other) {
    if (this != &other) {
        delete[] pdata;
        max_size = other.max_size;
        size = other.size;
        pdata = new T[max_size];
        for (int i{0}; i < size; i++) {
            pdata[i] = other.pdata[i];
        }
    }
    return *this;
}

template<typename T>
Container<T>& Container<T>::operator=(Container&& other) {
    if (this != &other) {
        delete[] pdata;

        pdata = other.pdata;
        size = other.size;
        max_size = other.max_size;

        other.pdata = nullptr;
        other.max_size = 0;
        other.size = 0;
    }
    return *this;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Container<U>& c) {
    for (int i{0}; i < c.size; ++i) {
        out << c.pdata[i] << " ";
    }
    return out;
}

template<typename T>
void Container<T>::resize(int new_size) {
    if (new_size < 8) {
        new_size = 8;
    }
    T* new_data = new T[new_size];

    for (int i = 0; i < size; i++)
        new_data[i] = pdata[i];

    delete[] pdata;
    pdata = new_data;
    max_size = new_size;
}

template<typename T>
void Container<T>::push(T element) {
    if (size >= max_size) {
        resize(max_size * 2);
    }
    pdata[size++] = element;
}

template<typename T>
void Container<T>::pop(int index) {
    if (index < 0 || index >= size)
        return;

    for (int i = index; i < size - 1; ++i)
        pdata[i] = pdata[i + 1];

    size--;

    if (size < max_size / 4)
        resize(max_size / 2);
}
