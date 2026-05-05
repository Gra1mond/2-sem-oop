#pragma once
#include"Container.h"
#include"Term.h"

class Polynomial{
private:
    Container<Term> terms;
    bool order;//возрастание или убыввание

public:
    Polynomial();
    Polynomial(const Term&);
    Polynomial(int);
    Polynomial(const Polynomial&);

    void addTerm(const Term&);
    void q_sort(int,int);
    void sort();
    int binar_search(int)const;
    

    Polynomial operator+(const Polynomial&)const;
    Polynomial& operator+=(const Polynomial&);
    Polynomial operator-(const Polynomial&)const;
    Polynomial& operator-=(const Polynomial&);
    Polynomial& operator*=(const Polynomial&);
    Polynomial operator*(const Polynomial&)const;
    bool operator==(const Polynomial&)const;
    Polynomial& operator=(const Polynomial&);



    friend std::istream& operator>>(std::istream&, Polynomial&);
    friend std::ostream& operator<<(std::ostream&, const Polynomial&);

};