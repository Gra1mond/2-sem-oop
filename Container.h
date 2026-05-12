#pragma once
#include<iostream>
#include <cstring>
template<typename T>
class Container {
 protected:
    T* pdata;
    int size;
    int max_size;

 public:
    void push(const T& element);
    void pop();
    void clear();
    void resize(int new_size);
    void delete_at(size_t index);

    T* begin(){return pdata;}
    T* end(){return pdata + size;};

    const T* begin()const{return pdata;}
    const T* end()const{return pdata+size;}

    bool operator<(const Container& other)const;
    const T& operator[](int index)const;
    T& operator[](int index);
    Container& operator=(const Container& other);  // присваивание (глубокое копирование)
    bool operator==(const Container& other)const;
    Container& operator=(Container&& other);           // перемещающее присваивание (move)

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Container<U>& c);
    template<typename U>
    friend std::istream& operator>>(std::istream& in, Container<U>& c);

    Container();
    Container(const Container&);
    Container(Container&&);
    ~Container();

    int getSize() const { return size; }
};

template<typename T>
Container<T>::Container(){
    this->max_size=0;
    this->size=0;
    this->pdata = new T[max_size];
}

// template<typename T>
// Container<T>::Container(T element){
//     this->max_size = 8;
//     this->size = 0;
//     this->pdata = new T[max_size];
//     this->pdata[0]=element;
// }

template<typename T>
Container<T>::Container(const Container& other){
    this->max_size = other.max_size;
    this->size = other.size;
    this->pdata = new T[max_size];
    for(int i=0;i<size;++i){
        this->pdata[i]=other.pdata[i];
    } 
}

template<typename T>
Container<T>::Container(Container&& other){
    this->max_size = other.max_size;
    this->size= other.size;
    this->pdata = other.pdata;

    other.max_size=0;
    other.size = 0;
    other.pdata = nullptr;

}

template<typename T>
Container<T>& Container<T>::operator=(const Container& other){
    if(this!=&other){
        delete[] pdata;

        size = other.size;
        max_size = other.max_size;
        pdata = new T[max_size];
        for(int i =0;i<size;++i){
            pdata[i]=other.pdata[i];
        }
    }
    return *this;
}

template<typename T>
Container<T>& Container<T>::operator=(Container&& other){
    if(this!=&other){
        delete[] pdata;

        pdata = other.pdata;
        max_size = other.max_size;
        size = other.size;  

        other.pdata = nullptr;
        other.max_size = 0;
        other.size = 0;
    }
    return *this;
}

template<typename T>
Container<T>::~Container(){
    delete[] pdata;
    pdata = nullptr;
}


template<typename T>
bool Container<T>::operator==(const Container& other)const{
    if(this->size!=other.size){
        return false;
    }
    for(int i{0};i<size;++i){
        if(this->pdata[i]!=other.pdata[i]){
            return false;
        }
    }
    return true;
}


template<typename T>
void Container<T>::resize(int new_size) {
    if (new_size < 1){
        new_size = 1;  
    }
    
    T* new_data = new T[new_size];
    for (int i = 0; i < size; i++)
        new_data[i] = pdata[i];
    delete[] pdata;
    pdata = new_data;
    max_size = new_size;
}


template<typename T>
void Container<T>::push(const T& value) {
    if (size >= max_size){
        resize(max_size == 0 ? 8 : max_size * 2);
    }
    pdata[size++] = value;
}

template<typename T>
void Container<T>::pop(){
    if (size == 0) return;
    size--;
    if(size < max_size/4){
    resize(max_size/2);
    }   
}


template<typename T>
void Container<T>::delete_at(size_t index){
    for (int i = index; i < size - 1; ++i) {
        pdata[i] = pdata[i + 1];
    }
    size--;
    if (size < max_size / 4) {
        resize(max_size / 2);
    }
}

template<typename T>
void Container<T>::clear() {
    delete[] pdata;
    pdata = nullptr;
    size = 0;
    max_size = 0;
}

template<typename T>
T& Container<T>::operator[](int index){
    if(index<0 || index >=size){
        throw std::out_of_range("Index out of range");
    }
    return pdata[index];
}

template<typename T>
const T& Container<T>::operator[](int index)const{
    if(index<0 || index >=size){
        throw std::out_of_range("Index out of range");
    }
    return pdata[index];
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Container<U>& c) {
    for (int i{0}; i < c.size; ++i) {
        out << c.pdata[i] << " ";
    }
    return out;
}


template<typename U>
std::istream& operator>>(std::istream& in, Container<U>& c){
    int n;
    std::cout<<"Введите количество элементов\n";
    in>>n;
    for(int i{0};i<n;++i){
        U val;
        in>>val;
        c.push(val);
    }
    return in;
}


template<typename T>
bool Container<T>::operator<(const Container& other)const{
    int min_size = size < other.size ? size : other.size;
    for (int i = 0; i < min_size; ++i) {
        if (pdata[i] < other.pdata[i]) return true;
        if (pdata[i] > other.pdata[i]) return false;
    }
    return size < other.size;  
}
