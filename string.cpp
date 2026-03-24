#include"string.hpp"
void readLine(const char* ch, int& numerator, int& denominator) {
    char buffer[256];
    std::cout << ch;
    std::cin.getline(buffer, 256);

    parseString(buffer, numerator, denominator);
}
void parseString(const char* buffer, int& numerator, int& denominator){


    int i = 0;
    bool isNegative = false;

    // знак
    if (buffer[i] == '-') {
        isNegative = true;
        i++;
    }

    // целая часть
    int whole = 0;
    while (buffer[i] >= '0' && buffer[i] <= '9') {
        whole = whole * 10 + (buffer[i] - '0');
        i++;
    }

    // пропуск пробелов
    while (buffer[i] == ' ') i++;

    int num = 0;
    int den = 1;

    // есть дробная часть?
    if (buffer[i] != '\0') {

        // читаем числитель
        while (buffer[i] >= '0' && buffer[i] <= '9') {
            num = num * 10 + (buffer[i] - '0');
            i++;
        }

        // если есть '/'
        if (buffer[i] == '/') {
            i++;
            den = 0;

            while (buffer[i] >= '0' && buffer[i] <= '9') {
                den = den * 10 + (buffer[i] - '0');
                i++;
            }
        }
    }

    // если была дробь
    if (num != 0) {
        numerator = whole * den + num;
        denominator = den;
    } else {
        numerator = whole;
        denominator = 1;
    }

    // защита от 0
    if (denominator == 0) denominator = 1;

    // знак
    if (isNegative) numerator = -numerator;

    reduceFraction(numerator, denominator);
}

void reduceFraction(int& numerator, int& denominator) {
    if (denominator == 0) return;
    
    int a = std::abs(numerator);
    int b = denominator;
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    int gcd = a;
    
    numerator /= gcd;
    denominator /= gcd;
    
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void doubleToFraction(double input, int& numerator, int& denominator) {
    const int SCALE = 1000000; 

    numerator = static_cast<int>(input * SCALE);
    denominator = SCALE;

    reduceFraction(numerator, denominator);
}