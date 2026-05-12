#pragma once
#include <cstring>
#include <iostream>

namespace ClassConstants {
const int kDefaultDate = 0;
const int kDefaultPrice = 0;
const int kDefaultLenMark = 8;
const int kDefaultCount = 0;
const char kDefaulMarkText[] = "default";
const int kEmptySymbolAppend = 1;
const int kBufferSizeInitialize = 25;
}  // namespace ClassConstants

class wineLibrary {
    int date;
    char* mark;
    int price;
    int countBottles;

public:
    wineLibrary(int inputDate, const char* inputMark, int inputPrice, int inputCount);
    wineLibrary();
    wineLibrary(const wineLibrary& other);
    wineLibrary(wineLibrary&& other);
    wineLibrary& operator=(wineLibrary other);
    ~wineLibrary();

    bool operator==(const wineLibrary& other) const;
    bool operator<(const wineLibrary& other) const;

    friend std::ostream& operator<<(std::ostream& out, const wineLibrary& wine);
    friend std::istream& operator>>(std::istream& in, wineLibrary& wine);
};

wineLibrary::wineLibrary(int inputDate, const char* inputMark, int inputPrice, int inputCount)
    : date(inputDate), mark(new char[strlen(inputMark) + 1]), price(inputPrice), countBottles(inputCount) {
    memcpy(mark, inputMark, strlen(inputMark) + 1);
}

wineLibrary::wineLibrary()
    : date(ClassConstants::kDefaultDate),
      mark(new char[ClassConstants::kDefaultLenMark]),
      price(ClassConstants::kDefaultPrice),
      countBottles(ClassConstants::kDefaultCount) {
    memcpy(mark, ClassConstants::kDefaulMarkText, ClassConstants::kDefaultLenMark);
}

wineLibrary::wineLibrary(const wineLibrary& other)
    : date(other.date), mark(new char[strlen(other.mark) + 1]), price(other.price), countBottles(other.countBottles) {
    memcpy(mark, other.mark, strlen(other.mark) + 1);
}

wineLibrary::wineLibrary(wineLibrary&& other)
    : date(other.date), mark(other.mark), price(other.price), countBottles(other.countBottles) {
    other.mark = nullptr;
}

wineLibrary& wineLibrary::operator=(wineLibrary other) {
    std::swap(date, other.date);
    std::swap(mark, other.mark);
    std::swap(price, other.price);
    std::swap(countBottles, other.countBottles);
    return *this;
}

wineLibrary::~wineLibrary() {
    delete[] mark;
}

bool wineLibrary::operator==(const wineLibrary& other) const {
    return date == other.date &&
           price == other.price &&
           countBottles == other.countBottles &&
           strcmp(mark, other.mark) == 0;
}

bool wineLibrary::operator<(const wineLibrary& other) const {
    return strcmp(mark, other.mark) < 0;
}

std::ostream& operator<<(std::ostream& out, const wineLibrary& wine) {
    if (&out == &std::cout) {
        out << "марка:" << wine.mark
            << " (" << wine.date << " год)"
            << " - " << wine.price << " руб"
            << " [" << wine.countBottles << " шт]" << std::endl;
    } else {
        out << wine.mark << " " << wine.date << " " << wine.price << " " << wine.countBottles << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, wineLibrary& wine) {
    char buf[ClassConstants::kBufferSizeInitialize];

    if (&in == &std::cin) std::cout << "Введите марку:\t";
    in >> buf;
    delete[] wine.mark;
    wine.mark = new char[strlen(buf) + 1];
    memcpy(wine.mark, buf, strlen(buf) + 1);

    if (&in == &std::cin) std::cout << "Введите год:\t";
    in >> wine.date;

    if (&in == &std::cin) std::cout << "Введите цену:\t";
    in >> wine.price;

    if (&in == &std::cin) std::cout << "Введите количество:\t";
    in >> wine.countBottles;

    return in;
}
    