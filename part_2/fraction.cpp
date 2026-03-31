#include "fraction.hpp"

Fraction::Fraction() noexcept : numerator(0), denominator(0) {
}
Fraction::Fraction(const char* inputBuffer) : Fraction() {
    ParsingBuffer(inputBuffer);
}
Fraction::Fraction(int inputNumerator, int inputDenominator) : numerator(inputNumerator), denominator(inputDenominator) {
    if (denominator == 0) {
        std::cerr << "Ошибка!" << std::endl;
        exit(1);
    }
}
Fraction::Fraction(const double a)
    : numerator(static_cast<int>(std::round(a * Constant::kNumberDecimalPlaces))), denominator(Constant::kNumberDecimalPlaces) {
    Normalize();
}

std::istream& operator>>(std::istream& in, Fraction& fraction) {
    char inputBuffer[Constant::kMaxBufferLength];
    if (in.getline(inputBuffer, Constant::kMaxBufferLength)) {
        fraction.ParsingBuffer(inputBuffer);
        fraction.Normalize();
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    if (fraction.denominator == 0) {
        return out << "none";
    }

    Fraction outputFraction(fraction);
    outputFraction.Normalize();

    int wholePart = outputFraction.numerator / outputFraction.denominator;
    int remainingNumerator = std::abs(outputFraction.numerator % outputFraction.denominator);
    int absDenominator = std::abs(outputFraction.denominator);

    if (wholePart != 0) {
        out << wholePart;
        if (remainingNumerator != 0) {
            out << " " << std::abs(remainingNumerator) << "/" << std::abs(absDenominator);
        }
    } else {
        if (remainingNumerator == 0) {
            out << "0";
        } else {
            if (outputFraction.numerator < 0) {
                out << "-";
            }
            out << remainingNumerator << "/" << absDenominator;
        }
    }
    return out;
}

void Fraction::ParsingBuffer(const char* inputBuffer) {
    if (!inputBuffer || strlen(inputBuffer) == 0) {
        std::cout << "Буфер пуст!\n";
        exit(1);
    }

    int whole{0};
    const char* slashPtr = strchr(inputBuffer, '/');
    const char* spacePtr = strchr(inputBuffer, ' ');

    if (slashPtr) {
        denominator = atoi(slashPtr + 1);
        if (denominator == 0) {
            std::cout << "Ошибка!\n";
            exit(1);
        }

        if (spacePtr) {
            whole = atoi(inputBuffer);
            numerator = atoi(spacePtr + 1);
        } else {
            whole = 0;
            numerator = atoi(inputBuffer);
        }
    } else {
        whole = atoi(inputBuffer);
        numerator = 0;
        denominator = 1;
    }

    if (whole != 0) {
        if (whole < 0) {
            numerator = whole * denominator - std::abs(numerator);
        } else {
            numerator = whole * denominator + std::abs(numerator);
        }
    }
}
void Fraction::Normalize() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    if (denominator != 0) {
        int common = std::gcd(std::abs(numerator), std::abs(denominator));
        numerator /= common;
        denominator /= common;
    }
}

void Fraction::operator+=(const Fraction& summand) {
    numerator = numerator * summand.denominator + summand.numerator * denominator;
    denominator = denominator * summand.denominator;
    Normalize();
}

Fraction Fraction::operator+(const Fraction& summand) const {
    Fraction summa(*this);
    summa += summand;
    return summa;
}

Fraction Fraction::operator++(int) {
    Fraction temp(*this);
    this->numerator += this->denominator;

    return temp;
}
