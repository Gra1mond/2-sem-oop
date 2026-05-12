#include <iostream>
#include "containers/Polynomial.h"
#include "containers/Term.h"


constexpr int kCoefA = 2;
constexpr int kPowerA = 5;
constexpr int kCoefB = 3;
constexpr int kPowerB = 7;


int main() {
    Term a(kCoefA, kPowerA);
    Term b(kCoefB, kPowerB);
    Polynomial c;
    Polynomial y;
    c.addTerm(a);
    c.addTerm(b);
    std::cin>>y;
    std::cout<<(c+y)<<' ';
    std::cout<<(c*y)<<' ';
    Polynomial ab;
    ab.addTerm(a);
    ab.addTerm(b);
    std::cout<<ab;
    return 0;
}