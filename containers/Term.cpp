#include "Term.h"
#include <cctype>

void Term::operator+=(const Term& other) {
    coef = coef + other.coef;
}

Term Term::operator+(const Term& other) const {
    if (power == other.power) {
        Term summa(*this);
        summa += other;
        return summa;
    }
    return *this;
}

Term& Term::operator=(const Term& other) {
    if (this != &other) {
        coef = other.coef;
        power = other.power;
    }
    return *this;
}

std::istream& operator>>(std::istream& in, Term& term) {
    int power = 0;
    int sign = 1;
    int coef = 0;
    bool hasCoef = false;

    in >> std::ws;

    int next = in.peek();

    if (next == '-' || next == '+') {
        char c = static_cast<char>(in.get());
        if (c == '-') {
            sign = -1;
        }

        in >> std::ws;
        next = in.peek();
    }

    while (next != EOF && next >= '0' && next <= '9') {
        coef = coef * Constants::step + (static_cast<char>(in.get()) - '0');
        hasCoef = true;
        next = in.peek();
    }

    if (!hasCoef) {
        coef = 1;
    }

    if (next == 'x') {
        in.get();
        power = 1;

        in >> std::ws;
        next = in.peek();

        if (next == '^') {
            in.get();
            power = 0;

            in >> std::ws;
            next = in.peek();

            while (next != EOF && next >= '0' && next <= '9') {
                power = power * Constants::step + (static_cast<char>(in.get()) - '0');
                next = in.peek();
            }
        }
    } else {
        power = 0;
    }
    term = Term(sign * coef, power);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Term& term) {
    int coef = term.coef;
    int power = term.power;

    if (coef == 0) {
        return out << coef;
    } else if (power == 0) {
        return out << coef;
    } else if (coef == -1 && power != 0) {
        out << '-';
    } else if (coef != 1 || power == 0) {
        out << coef;
    }
    out << 'x';

    if (power > 1) {
        out << '^' << power;
    }
    return out;
}
