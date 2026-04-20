#include"Container.h"
/*
Элементы уникальны 
Элементы отсортированы
*/
template<typename T>
class Set: public Container<T>{
public:
    bool is_element(T element);
    int q_find(T element);

    void push(T element) override;
    void pop(T element);

    Set& operator+=(const Set& other);
    Set& operator-=(const Set& other);
    Set& operator*=(const Set& other);

    Set operator+(const Set& other);
    Set operator-(const Set& other);
    Set operator*(const Set& other);
    bool operator==(const Set& other);

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out,const Set<U>& s);

    ~Set() override;
};