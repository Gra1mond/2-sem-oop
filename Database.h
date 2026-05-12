#pragma once
#include"Container.h"
#include <fstream>
#include <algorithm> 

template<typename T>
class Database{
private:
    Container<T> data;
    template<typename Comparator>
    void quicksort(int left, int right, Comparator cmp);
public:
    Database();                              
    Database(const Database& other);         
    Database(Database&& other);             
    Database& operator=(const Database&);   
    Database& operator=(Database&&);        
    ~Database();                            

    template<typename Comparator>
    void sort_qsort(Comparator cmp);

    T* begin() { return data.begin(); }
    T* end() { return data.end(); }

    void write_to_file(const char* filename);
    void read_from_file(const char* filename);

    void add(const T& value)  { data.push(value); }
    void remove_last()        { data.pop(); }
    void remove_at(int index) { data.delete_at(index); }
    void clear()              { data.clear(); }
    void display()            { std::cout << data; }
    int find(const T& value);
    void input_from_console() {std::cin>>data;}
};

template<typename T>
Database<T>::Database():data(){}

template<typename T>
Database<T>::Database(const Database& other):data(other.data){}

template<typename T>
Database<T>::Database(Database&& other):data(std::move(other.data)){}

template<typename T>
Database<T>::~Database(){}

template<typename T>
Database<T>& Database<T>::operator=(const Database& other){
    data = other.data;
    return *this;
}

template<typename T>
Database<T>& Database<T>::operator=(Database&& other){
    data = std::move(other.data);
    return *this;
}


template<typename T>
int Database<T>::find(const T& value){
    auto it = std::find(data.begin(),data.end(),value);
    if(it == data.end()){
        return -1;
    }
    return it - data.begin();
}

template<typename T>
template<typename Comparator>
void Database<T>::quicksort(int left, int right, Comparator cmp) {
    if (left >= right) return;

    T pivot = data[left + (right - left) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (cmp(data[i], pivot)) ++i;
        while (cmp(pivot, data[j])) --j;
        if (i <= j) {
            T tmp_val = std::move(data[i]);
            data[i] = std::move(data[j]);
            data[j] = std::move(tmp_val);
            ++i;
            --j;
        }
    }
    quicksort(left, j, cmp);
    quicksort(i, right, cmp);
}

template<typename T>
template<typename Comparator>
void Database<T>::sort_qsort(Comparator cmp) {
    if (data.getSize() == 0) return;
    quicksort(0, data.getSize() - 1, cmp);
}

template<typename T>
void Database<T>::write_to_file(const char* filename) {
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cerr << "Не удалось открыть файл" << std::endl;
        return;
    }
    file<<data.getSize()<<std::endl;
    for (int i = 0; i < data.getSize(); ++i) {
        file << data[i] << "\n";     
    }
    file.close();
}

template<typename T>
void Database<T>::read_from_file(const char* filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл" << std::endl;
        return;
    }
    data.clear();
    int n;
    file>>n;
    for(int i=0;i<n;++i){
        T val;
        file>>val;
        data.push(val);
    }
    file.close();
}