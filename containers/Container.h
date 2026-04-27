/*
1. Написать Container<T>
   └── поля, конструкторы, деструктор
   └── push, pop, find, resize
   └── operator[], операторы присваивания

2. Написать Set<T> : public Container<T>
   └── push с проверкой уникальности + сортировка
   └── pop с проверкой существования
   └── is_element, q_find (бинарный поиск)
   └── +=, -=, *=, +, -, *, ==
   └── friend operator

3. Специализировать методы для char*
   └── сравнение через strcmp
   └── копирование строк через strcpy/new
*/
#pragma once

#include <cstring>
template <typename T>
class Container{
protected:
    T* pdata;
    int size;
    int max_size;

    void raw_push(T element);
public:
    virtual void push(T element);
    void pop(int index);
    int find(T element);
    void resize(int new_size);

    T& operator[](int index){return pdata[index];}
    Container& operator=(const Container& other);//присваивание (глубокое копирование)
    Container& operator=(Container&& other);//перемещающее присваивание (move)

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Container<U>& c);

    Container(T element);
    Container();
    Container(const Container&);
    Container(Container&&);
    virtual ~Container();  
};

template<typename T>
void Container<T>::raw_push(T element) {
    if (this->size >= this->max_size) {
        resize(this->max_size * 2);
    }

    this->pdata[this->size++] = element;
}

template<typename T>
Container<T>::Container(){
    this->max_size=8;
    this->size=0;
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
Container<T>::Container(const Container& other){
    this->max_size = other.max_size;
    this->size = other.size;
    pdata    = new T[max_size];        
    for (int i = 0; i < size; i++)
        pdata[i] = other.pdata[i]; 
}

template<typename T>
Container<T>::Container(Container&& other){
    
        

        pdata = other.pdata;
        size=other.size;
        max_size=other.max_size;

        other.pdata = nullptr;
        other.size = 0;
        other.max_size = 0;
    
}

template<typename T>
Container<T>::~Container(){
    delete[] pdata;
    pdata = nullptr;
}

template<typename T>
Container<T>& Container<T>::operator=(const Container& other){
    if (this!=&other){
        delete[] pdata;
        max_size = other.max_size;
        size = other.size;
        pdata = new T[max_size];
        for(int i{0};i<size;i++){
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
        size=other.size;
        max_size=other.max_size;

        other.pdata = nullptr;
        other.max_size = 0;
        other.size = 0;

    }
    return *this;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Container<U>& c){
    for(int i{0};i<c.size;++i){
        out<<c.pdata[i]<<" ";
    }
    return out;
}

template<typename T>
void Container<T>::resize(int new_size) {
    if (new_size < 8){
        new_size = 8;
    }
    T* new_data = new T[new_size];

    for (int i = 0; i < size; i++)
        new_data[i] = pdata[i];

    delete[] pdata;
    pdata    = new_data;
    max_size = new_size;
}

template<typename T>
void Container<T>::push(T element){
    if(size>=max_size){
        resize(max_size*2);
    }
    pdata[size++]=element;
}

template<typename T>
void Container<T>::pop(int index){
    for (int i = index;i<size-1;++i){
        pdata[i]=pdata[i+1];
    }
    size--;
    if(size<max_size/4){
        resize(max_size/2);
    }
}

template<typename T>
int Container<T>::find(T element){
    for (int i = 0; i < size; i++)
        if (pdata[i] == element)
            return i;
    return -1;
}

//--------Объявления специализаций (до инстанциирования)------------
template<> void Container<const char*>::push(const char* element);
template<> void Container<const char*>::resize(int new_size);
template<> void Container<const char*>::pop(int index);
template<> int  Container<const char*>::find(const char* element);
template<> Container<const char*>::~Container();
template<> Container<const char*>::Container(const Container<const char*>& other);
template<> Container<const char*>& Container<const char*>::operator=(const Container<const char*>& other);
template<> Container<const char*>& Container<const char*>::operator=(Container<const char*>&& other);

//--------Специализации------------

template<>
int Container<const char*>::find(const char* element) {
    for (int i = 0; i < size; i++)
        if (strcmp(pdata[i], element) == 0)
            return i;
    return -1;
}

template<>
void Container<const char*>::push(const char* element){
    if(size>=max_size){
        resize(max_size*2);
    }
    char* copy = new char[strlen(element)+1];
    strcpy(copy, element);
    pdata[size++] = copy;
}

template<>
void Container<const char*>::resize(int new_size){
    if (new_size < size)
        new_size = size;

    const char** new_data = new const char*[new_size];

    for (int i = 0; i < size; ++i)
        new_data[i] = pdata[i];

    delete[] pdata;
    pdata = new_data;
    max_size = new_size;
}//изменил

template<>
Container<const char*>::~Container(){
    delete[] pdata;
}//изменил

template<>
Container<const char*>::Container(const Container<const char*>& other){
    max_size=other.max_size;
    size =other.size;
    pdata = new const char*[max_size];
    for (int i{0};i<size;++i){
        char* copy = new char[strlen(other.pdata[i])+1];
        strcpy(copy, other.pdata[i]);
        pdata[i] = copy;
    }
}

template<>
Container<const char*>& Container<const char*>::operator=(Container&& other){
    if(this!=&other){
        for(int i{0};i<size;++i){
            delete[] const_cast<char*>(pdata[i]);
        }
        delete[] pdata;
        size = other.size;
        max_size=other.max_size;
        pdata = other.pdata;

        other.size=0;
        other.max_size=0;
        other.pdata=nullptr;
    }
    return *this;
}

template<>
void Container<const char*>::pop(int index){
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; ++i)
        pdata[i] = pdata[i + 1];

    size--;
}//изменил

template<>
Container<const char*>& Container<const char*>::operator=(const Container<const char*>& other){
    if(this!=&other){
        for (int i{0};i<size;++i){
            delete[] const_cast<char*>(pdata[i]);
        }
        delete[] pdata;
        max_size = other.max_size;
        size = other.size;

        pdata = new const char*[max_size];
        for(int i{0};i<size;++i){
            char* copy = new char[strlen(other.pdata[i])+1];
            strcpy(copy, other.pdata[i]);
            pdata[i] = copy;
        }
    }
    return *this;
}