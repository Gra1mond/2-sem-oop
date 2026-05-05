#pragma once
#include <iostream>

namespace Constants {
const int step = 10;
}
class Term {
 private:
    int coef;
    int power;

 public:
    Term() : coef(0), power(0) {}
    Term(int _) : coef(_), power(0) {}
    Term(const Term& other) : coef(other.coef), power(other.power) {}
    Term(int input_coef, int input_power) : coef(input_coef), power(input_power) {}

    void operator+=(const Term& other);
    Term operator+(const Term& other) const;
    Term& operator=(const Term&);

    int getCoef() const { return coef; }
    int getPower() const { return power; }

    friend std::istream& operator>>(std::istream& in, Term& term);
    friend std::ostream& operator<<(std::ostream& out, const Term& term);
    friend class Polynomial;
};
