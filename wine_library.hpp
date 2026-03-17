#pragma once
#include <cstring>
#include <fstream>
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
    static int sizeLibrary;

 public:
    wineLibrary(int inputDate, const char* inputMark, int inputPrice, int inputCount);
    wineLibrary();
    wineLibrary(const wineLibrary& other);
    wineLibrary& operator=(const wineLibrary& other);
    void set(int inputDate, const char* inputMark, int inputPrice, int inputCount);
    int getDate() const;
    int getCount() const;
    int getPrice() const;
    const char* getMark() const;
    void setDate(int inputDate);
    void setPrice(int inputPrice);
    void setCount(int inputCount);
    void setMark(const char* inputMark);
    ~wineLibrary();
    // friend void Swap(wineLibrary& thisWine,wineLibrary& copyWine) noexcept;
};
std::ostream& operator<<(std::ostream& out, const wineLibrary& wine);
std::istream& operator>>(std::istream& in, wineLibrary& wine);
