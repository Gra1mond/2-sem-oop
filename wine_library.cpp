#include "wine_library.hpp"

wineLibrary::wineLibrary(int inputDate, const char* inputMark, int inputPrice, int inputCount)
    : date(inputDate), mark(new char[strlen(inputMark) + 1]), price(inputPrice), count(inputCount) {
    memcpy(mark, inputMark,strlen(inputMark) + 1);
}
wineLibrary::wineLibrary()
    : date(ClassConstants::kDefaultDate),
      mark(new char[ClassConstants::kDefaultLenMark]),
      price(ClassConstants::kDefaultPrice),
      count(ClassConstants::kDefaultCount) {
    memcpy(mark, ClassConstants::kDefaulMarkText,ClassConstants::kDefaultLenMark);
}
wineLibrary::wineLibrary(const wineLibrary& other)
    : date(other.date), mark(new char[strlen(other.mark) + 1]), price(other.price), count(other.count) {
    memcpy(mark, other.mark,strlen(other.mark) + 1);
}
wineLibrary& wineLibrary::operator=(const wineLibrary& other) {
    if (this != &other) {
        delete[] mark;

        date = other.date;
        price = other.price;
        count = other.count;

        if (other.mark) {
            size_t len = strlen(other.mark) + ClassConstants::kEmptySymbolAppend;
            mark = new char[len];
            memcpy(mark, other.mark, len); 
        } else {
            mark = nullptr;
        }
    }
    return *this;
}
void wineLibrary::set(int inputDate, const char* inputMark, int inputPrice, int inputCount) {
    delete[] mark;

    date = inputDate;
    price = inputPrice;
    count = inputCount;

    if (inputMark) {
        size_t len = strlen(inputMark) + ClassConstants::kEmptySymbolAppend;
        mark = new char[len];
        memcpy(mark, inputMark, len);
    } else {
        mark = nullptr;
    }
}
int wineLibrary::getDate() const {
    return date;
}
int wineLibrary::getCount() const {
    return count;
}
int wineLibrary::getPrice() const {
    return price;
}
const char* wineLibrary::getMark() const {
    return mark;
}
wineLibrary::~wineLibrary() {
    delete[] mark;
};

std::ostream& operator<<(std::ostream& out, const wineLibrary& wine) {
    out << "марка:" << wine.getMark();
    out << " (" << wine.getDate() << " год)";
    out << " - " << wine.getPrice() << " руб";
    out << " [" << wine.getCount() << " шт]" << std::endl;

    return out;
}
std::istream& operator>>(std::istream& in, wineLibrary& wine) {
    char inputBuffer[ClassConstants::kBufferSizeInitialize];
    int inputDate{ClassConstants::kDefaultCount};
    int inputCount{ClassConstants::kDefaultCount};
    int inputPrice{ClassConstants::kDefaultCount};

    std::cout << "Введите марку:\t";
    in >> inputBuffer;

    std::cout << "Введите год:\t";
    in >> inputDate;

    std::cout << "Введите цену:\t";
    in >> inputPrice;

    std::cout << "Введите количество:\t";
    in >> inputCount;

    wine.set(inputDate, inputBuffer, inputPrice, inputCount);

    return in;
}
