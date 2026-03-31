#include "string.hpp"

void readLine(const char* ch, int& numerator, int& denominator) {
    char buffer[StringConstants::kBufferSize];
    std::cout << ch;
    std::cin.getline(buffer, StringConstants::kBufferSize);

    parseString(buffer, numerator, denominator);
}

void parseString(const char* buffer, int& numerator, int& denominator) {
    const char* ptr = buffer;

    const char* slash = strchr(ptr, '/');

    long num = 0;
    long den = 1;

    if (slash) {
        num = strtol(ptr, nullptr, StringConstants::kNumberSize);
        den = strtol(slash + 1, nullptr, StringConstants::kNumberSize);
    } else {
        num = strtol(ptr, nullptr, StringConstants::kNumberSize);
        den = 1;
    }

    numerator = static_cast<int>(num);
    denominator = static_cast<int>(den);

    if (denominator == 0) {
        denominator = 1;
    }

    reduceFraction(numerator, denominator);
}

void reduceFraction(int& numerator, int& denominator) {
    if (denominator == 0) {
        return;
    }

    int gcd = std::gcd(std::abs(numerator), std::abs(denominator));

    numerator /= gcd;
    denominator /= gcd;

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void doubleToFraction(double input, int& numerator, int& denominator) {
    const int SCALE = StringConstants::kScaleSize;

    numerator = static_cast<int>(input * SCALE);
    denominator = SCALE;

    reduceFraction(numerator, denominator);
}
