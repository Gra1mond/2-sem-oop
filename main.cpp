#include <iostream>
#include <sstream>

#include "containers/Polynomial.h"
#include "containers/Term.h"

static void printSection(const char* title) {
    std::cout << "\n=== " << title << " ===\n";
}

int main() {
    constexpr int sample_coef = 5;
    constexpr int sample_power = 2;
    constexpr int zero_power = 0;
    constexpr int first_coef = 3;
    constexpr int second_coef = -1;
    constexpr int third_coef = 4;

    printSection("Term");

    Term t1(first_coef, sample_power);
    Term t2(second_coef, sample_power);
    Term t3(sample_coef);

    std::cout << "t1 = " << t1 << '\n';
    std::cout << "t2 = " << t2 << '\n';
    std::cout << "t3 = " << t3 << '\n';
    std::cout << "t1 + t2 = " << (t1 + t2) << '\n';

    std::istringstream termInput("-4x^3");  // ввод как будто с клавиатуры
    Term t4;
    termInput >> t4;
    std::cout << "parsed term = " << t4 << '\n';

    printSection("Polynomial");

    Polynomial p1;
    p1.addTerm(Term(first_coef, sample_power));
    p1.addTerm(Term(second_coef, sample_power));
    p1.addTerm(Term(sample_coef, zero_power));
    std::cout << "p1 = " << p1 << '\n';

    Polynomial p2(Term(2, 1));
    p2.addTerm(Term(third_coef, zero_power));
    std::cout << "p2 = " << p2 << '\n';

    std::cout << "p1 + p2 = " << (p1 + p2) << '\n';
    std::cout << "p1 - p2 = " << (p1 - p2) << '\n';
    std::cout << "p1 * p2 = " << (p1 * p2) << '\n';

    Polynomial p3 = p1;
    p3 += p2;
    std::cout << "p3 after += : " << p3 << '\n';

    Polynomial p4 = p1;
    p4 -= p2;
    std::cout << "p4 after -= : " << p4 << '\n';

    Polynomial p5 = p1;
    p5 *= p2;
    std::cout << "p5 after *= : " << p5 << '\n';

    std::cout << "p1 == p3 ? " << (p1 == p3 ? "true" : "false") << '\n';

    std::istringstream polyInput("3x^2 - x^2 + 5x^5 - 4x^3 + x^2 - 7");  // ввод как будто с клавиатуры
    Polynomial p6;
    polyInput >> p6;
    std::cout << "parsed polynomial = " << p6 << '\n';

    return 0;
}
