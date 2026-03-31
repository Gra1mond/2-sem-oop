#ifndef FRACTION_H
#define FRACTION_H

#include <cmath>
#include <cstring>
#include <iostream>
#include <numeric>

namespace Constant {
const int kMaxBufferLength = 100;
const int kNumberDecimalPlaces = 10000;
}  // namespace Constant

class Fraction {
 private:
    int numerator;
    int denominator;

    void ParsingBuffer(const char* inputBuffer);
    void Normalize();

 public:
    Fraction() noexcept;
    Fraction(const char* inputBuffer);
    Fraction(int inputNumerator, int inputDenominator = 1);
    Fraction(const double n);

    Fraction(const Fraction& other) = default;
    Fraction& operator=(const Fraction& other) = default;

    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);

    void operator+=(const Fraction& summand);
    Fraction operator+(const Fraction& summand) const;

    Fraction operator++(int);
};

#endif
