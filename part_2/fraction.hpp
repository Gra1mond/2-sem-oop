#pragma once
#include <iostream>
class Fraction {
    int numerator;
    int denominator;

 public:
    Fraction();
    Fraction(int inputNumerator, int inputDenominator) noexcept;
    Fraction(const char* ch);
    Fraction(const Fraction& other);
    Fraction(double input);
    explicit operator double() const;
    Fraction(int value);

    Fraction& operator=(Fraction other);
    Fraction& operator=(double input);
    Fraction& operator=(const char* ch);

    Fraction& operator+=(const Fraction& f2);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
    friend std::istream& operator>>(std::istream& in, Fraction& f);

    ~Fraction();
    void setNumerator(int inputNumerator);
    void setDenominator(int inputDenominator);
    int getNumerator() const;
    int getDenominator() const;
};
Fraction operator+(Fraction lhs, const Fraction& rhs);
namespace Constants {
  inline constexpr int kNumStart = 0;
  inline constexpr int kDenStart = 1;
}
