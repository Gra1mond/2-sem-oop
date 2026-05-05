#include "Polynomial.h"

Polynomial::Polynomial() : terms(), order(true) {
}

Polynomial::Polynomial(const Term& term) : terms(term), order(true) {
}

Polynomial::Polynomial(int input_coef) : terms(input_coef), order(true) {
}

Polynomial::Polynomial(const Polynomial& other) = default;

void Polynomial::addTerm(const Term& other) {
    if (other.coef == 0) {
        return;
    }

    int idx = binar_search(other.power);

    if (idx != -1) {
        terms[idx].coef += other.coef;

        if (terms[idx].coef == 0) {
            terms.pop(idx);
        }

        return;
    }

    terms.push(other);

    sort();
}

void Polynomial::q_sort(int left, int right) {
    if (left >= right) {
        return;
    }

    Term pivot = terms[left + (right - left) / 2];

    int i = left;
    int j = right;

    while (i <= j) {
        if (order) {
            while (terms[i].power < pivot.power) {
                i++;
            }
            while (terms[j].power > pivot.power) {
                j--;
            }
        } else {
            while (terms[i].power > pivot.power) {
                i++;
            }
            while (terms[j].power < pivot.power) {
                j--;
            }
        }

        if (i <= j) {
            Term tmp = terms[i];
            terms[i] = terms[j];
            terms[j] = tmp;

            i++;
            j--;
        }
    }

    if (left < j) {
        q_sort(left, j);
    }

    if (i < right) {
        q_sort(i, right);
    }
}

void Polynomial::sort() {
    if (terms.getSize() > 1) {
        q_sort(0, terms.getSize() - 1);
    }
}

int Polynomial::binar_search(int search_power) const {
    int left = 0;
    int right = terms.getSize() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (terms[mid].power == search_power) {
            return mid;
        } else if (terms[mid].power < search_power) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

//--------------------------------------
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    for (int i = 0; i < other.terms.getSize(); ++i) {
        addTerm(other.terms[i]);
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial summa(*this);
    summa += other;
    return summa;
}

Polynomial& Polynomial::operator-=(const Polynomial& other) {
    for (int i = 0; i < other.terms.getSize(); ++i) {
        Term negativeTerm(-other.terms[i].coef, other.terms[i].power);
        addTerm(negativeTerm);
    }
    return *this;
}

Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial subtraction(*this);
    subtraction -= other;
    return subtraction;
}

Polynomial& Polynomial::operator*=(const Polynomial& other) {
    Container<Term> result;

    for (int i = 0; i < terms.getSize(); ++i) {
        for (int j = 0; j < other.terms.getSize(); ++j) {
            Term t(terms[i].coef * other.terms[j].coef, terms[i].power + other.terms[j].power);

            result.push(t);
        }
    }

    terms = Container<Term>();

    for (int i = 0; i < result.getSize(); ++i) {
        addTerm(result[i]);
    }

    return *this;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial multiply(*this);
    multiply *= other;
    return multiply;
}

bool Polynomial::operator==(const Polynomial& other) const {
    Polynomial a = *this;
    Polynomial b = other;

    a.sort();
    b.sort();

    if (a.terms.getSize() != b.terms.getSize()) {
        return false;
    }

    for (int i = 0; i < a.terms.getSize(); ++i) {
        if (a.terms[i].coef != b.terms[i].coef || a.terms[i].power != b.terms[i].power) {
            return false;
        }
    }

    return true;
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) {
        return *this;
    }

    terms = other.terms;
    order = other.order;

    return *this;
}

std::istream& operator>>(std::istream& in, Polynomial& poly) {
    poly = Polynomial();

    Term t;

    while (in >> t) {
        poly.addTerm(t);

        if (in.peek() == '\n' || in.eof()) {
            break;
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
    for (int i = 0; i < poly.terms.getSize(); ++i) {
        const Term& t = poly.terms[i];

        if (i > 0 && t.getCoef() > 0) {
            out << '+';
        }
        out << t;
    }
    return out;
}
