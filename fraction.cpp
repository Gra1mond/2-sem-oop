#include "fraction.hpp"
#include"string.hpp"
#include <iostream>
#include <utility>

Fraction::Fraction(int inputNumerator, int inputDenominator) noexcept
    : numerator(inputNumerator), denominator(inputDenominator) {
        reduceFraction(numerator, denominator);
    }
Fraction::Fraction(const Fraction &other) 
    : numerator(other.numerator), denominator(other.denominator) {
        reduceFraction(numerator, denominator);
    }
Fraction::Fraction(double input) {
    doubleToFraction(input, numerator, denominator);
}
Fraction::Fraction(const char* ch){
    int num{0};
    int den{0};
    parseString(ch, num, den); 
    setDenominator(den);
    setNumerator(num);
    reduceFraction(numerator, denominator);
}

int Fraction::getNumerator() const { 
    return numerator; }
int Fraction::getDenominator() const {
     return denominator; 
    }
void Fraction::setDenominator(int inputDenominator){
    this->denominator = inputDenominator;
}
void Fraction::setNumerator(int inputNumerator){
    this->numerator = inputNumerator;
}

Fraction operator+(int f1, const Fraction& f2) {
    int num = f1 * f2.getDenominator() + f2.getNumerator();
    int den = f2.getDenominator();
    reduceFraction(num, den);  
    return Fraction(num, den);
}

Fraction Fraction::operator+(int f2) const {
    int num = numerator + f2 * denominator;
    int den = denominator;
    reduceFraction(num, den);  
    return Fraction(num, den);
}

Fraction operator+(double f1, const Fraction& f2) {
    int num1, den1;
    doubleToFraction(f1, num1, den1);
    
    int num = num1 * f2.getDenominator() + f2.getNumerator() * den1;
    int den = den1 * f2.getDenominator();
    reduceFraction(num, den);  
    return Fraction(num, den);
}

Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;
    reduceFraction(num, den);  
    return Fraction(num, den);
}

Fraction Fraction::operator+(double f2) const {
    int num, den;
    doubleToFraction(f2, num, den);
    
    int newNum = numerator * den + num * denominator;
    int newDen = denominator * den;
    reduceFraction(newNum, newDen);  
    return Fraction(newNum, newDen);
}

Fraction& Fraction::operator=(Fraction other) {
    std::swap(numerator,other.numerator);
    std::swap(denominator,other.denominator);
    return *this;
}
Fraction& Fraction::operator=(double input){//Функиця с алгоритмом Евклида
    doubleToFraction(input, this->numerator, this->denominator);
    return *this;
}
Fraction& Fraction::operator=(const char* ch) {
    int num, den;
    parseString(ch, num, den); 
    this->numerator = num;
    this->denominator = den;
    return *this;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;

    numerator = newNum;
    denominator = newDen;
    
    reduceFraction(numerator, denominator);  // ← добавить
    
    return *this;
}

Fraction& Fraction::operator+=(double f2) {
    Fraction temporary;
    int num{0};
    int den{0};
    doubleToFraction(f2, num, den);
    temporary.setDenominator(den);
    temporary.setNumerator(num);
    
    int newNum = numerator * temporary.denominator + temporary.numerator * denominator;
    int newDen = denominator * temporary.denominator;
    
    numerator = newNum;
    denominator = newDen;
    
    reduceFraction(numerator, denominator);
    
    return *this;
}
Fraction& Fraction::operator+=(int f2) {
    numerator = numerator + f2 * denominator;  // формула: a/b + c = (a + c*b)/b
    
    reduceFraction(numerator, denominator);
    return *this;
}


std::ostream& operator<<(std::ostream& out, const Fraction& f){
    if (f.getDenominator() == 1){
        out<<f.getNumerator();
    } else{
        out<<f.getNumerator()<<"/"<<f.getDenominator();
    }
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    int whole = 0;
    int num = 0;
    int den = 1;
    bool isNegative = false;
    
    
    if (in.peek() == '-') {
        isNegative = true;
        in.get(); 
    }
    
    in >> whole;
    
    if (in.peek() == ' ') {
        in.get(); 
        in >> num;
        if (in.peek() == '/') {
            in.get(); 
            in >> den;
        }
        
        num = whole * den + num;
    } else if (in.peek() == '/') {
        in.get();
        in >> den;
        num = whole;
        whole = 0;
    } else {
        num = whole;
        den = 1;
    }
    
    if (isNegative) {
        num = -num;
    }
    
    f.setNumerator(num);
    f.setDenominator(den);
    
    return in;
}

Fraction::~Fraction(){}