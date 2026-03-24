#pragma once
#include<iostream>
class Fraction{
    int numerator;      // было numenator
    int denominator;    // было denomenator

    public:
    Fraction(int inputNumerator=0,int inputDenominator=1) noexcept;
    Fraction(const char* ch);
    Fraction(const Fraction &other);
    Fraction(double input);

    Fraction& operator=(Fraction other);
    Fraction& operator=(double input);
    Fraction& operator=(const char *ch);

    Fraction operator+(const Fraction& other) const;
    friend Fraction operator+(double f1, const Fraction& f2);
    friend Fraction operator+(int f1, const Fraction& f2);
    Fraction operator+(int f2) const;
    Fraction operator+(double f2) const;

    Fraction& operator+=(const Fraction& f2);
    Fraction& operator+=(double f2);
    Fraction& operator+=(int f2);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);
    
    ~Fraction();
    void setNumerator(int inputNumerator);
    void setDenominator(int inputDenominator);
    int getNumerator() const;
    int getDenominator() const;
};