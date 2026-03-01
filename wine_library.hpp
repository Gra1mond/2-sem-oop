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
const int kBufferSizeInitialize = 256;
}  // namespace ClassConstants
class wineLibrary {
    int date;
    char* mark;
    int price;
    int count;

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
    ~wineLibrary();
};
std::ostream& operator<<(std::ostream& out, const wineLibrary& wine);
std::istream& operator>>(std::istream& in, wineLibrary& wine);
