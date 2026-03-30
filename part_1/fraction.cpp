#include "fraction.hpp"
#include "string.hpp"

#include <cstdlib>
#include <iostream>
#include <numeric>
#include <utility>

Fraction::Fraction(int inputNumerator, int inputDenominator) noexcept : numerator(inputNumerator), denominator(inputDenominator) {
    reduceFraction(numerator, denominator);
}

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

Fraction operator+(int f1, const Fraction& f2) {
    int num = f1 * f2.getDenominator() + f2.getNumerator();
    int den = f2.getDenominator();

    reduceFraction(num, den);
    return {num, den};
}

// Fraction + int
Fraction Fraction::operator+(int f2) const {
    int num = numerator + f2 * denominator;
    int den = denominator;

    reduceFraction(num, den);
    return {num, den};
}

Fraction operator+(double f1, const Fraction& f2) {
    int num1 = Constants::kNumStart;
    int den1 = Constants::kDenStart;

    doubleToFraction(f1, num1, den1);

    int num = num1 * f2.getDenominator() + f2.getNumerator() * den1;
    int den = den1 * f2.getDenominator();

    reduceFraction(num, den);
    return {num, den};
}

Fraction Fraction::operator+(const Fraction& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int den = denominator * other.denominator;

    reduceFraction(num, den);
    return {num, den};
}

Fraction Fraction::operator+(double f2) const {
    int num = Constants::kNumStart;
    int den = Constants::kDenStart;

    doubleToFraction(f2, num, den);

    int newNum = numerator * den + num * denominator;
    int newDen = denominator * den;

    reduceFraction(newNum, newDen);
    return {newNum, newDen};
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

Fraction& Fraction::operator+=(const Fraction& other) {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;

    numerator = newNum;
    denominator = newDen;

    reduceFraction(numerator, denominator);
    return *this;
}

Fraction& Fraction::operator+=(double f2) {
    int num = Constants::kNumStart;
    int den = Constants::kDenStart;

    doubleToFraction(f2, num, den);

    numerator = numerator * den + num * denominator;
    denominator *= den;

    reduceFraction(numerator, denominator);
    return *this;
}

Fraction& Fraction::operator+=(int f2) {
    numerator += f2 * denominator;

    reduceFraction(numerator, denominator);
    return *this;
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
