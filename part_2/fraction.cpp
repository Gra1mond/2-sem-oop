#include "fraction.hpp"
#include "string.hpp"

#include <cstdlib>
#include <iostream>
#include <numeric>
#include <utility>



Fraction::Fraction(int inputNumerator, int inputDenominator) noexcept : numerator(inputNumerator), denominator(inputDenominator) {
    reduceFraction(numerator, denominator);
}
Fraction::Fraction(int value) : numerator(value), denominator(1) {};

Fraction::Fraction():numerator(0),denominator(1){};

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {
    reduceFraction(numerator, denominator);
}

Fraction::Fraction(double input) : numerator(0), denominator(1) {
    doubleToFraction(input, numerator, denominator);
    reduceFraction(numerator, denominator);
}

Fraction::Fraction(const char* ch) : numerator(0), denominator(1) {
    int num = Constants::kNumStart;
    int den = Constants::kDenStart;

    parseString(ch, num, den);

    numerator = num;
    denominator = den;

    reduceFraction(numerator, denominator);
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int inputDenominator) {
    denominator = inputDenominator;
}

void Fraction::setNumerator(int inputNumerator) {
    numerator = inputNumerator;
}

Fraction& Fraction::operator=(Fraction other) {
    std::swap(numerator, other.numerator);
    std::swap(denominator, other.denominator);
    return *this;
}

Fraction& Fraction::operator=(double input) {
    doubleToFraction(input, numerator, denominator);
    return *this;
}

Fraction& Fraction::operator=(const char* ch) {
    int num = Constants::kNumStart;
    int den = Constants::kDenStart;

    parseString(ch, num, den);

    numerator = num;
    denominator = den;

    return *this;
}

Fraction::operator double() const {
    if (denominator == 0) {
        return 0.0;
    }
    return static_cast<double>(numerator) / denominator;
}

Fraction& Fraction::operator+=(const Fraction& other) {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;

    numerator = newNum;
    denominator = newDen;

    reduceFraction(numerator, denominator);
    return *this;
}


Fraction operator+(Fraction lhs,const Fraction& rhs){
    lhs+=rhs;
    return lhs;
}


std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    if (f.getDenominator() == 1) {
        out << f.getNumerator();
    } else {
        out << f.getNumerator() << "/" << f.getDenominator();
    }
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& f) {
    int whole = Constants::kNumStart;
    int num = Constants::kNumStart;
    int den = Constants::kDenStart;
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

Fraction::~Fraction() = default;
