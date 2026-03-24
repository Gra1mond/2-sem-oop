#include "wine_library.hpp"
wineLibrary::wineLibrary(int inputDate, const char* inputMark, int inputPrice, int inputCount)
    : date(inputDate), mark(new char[strlen(inputMark) + 1]), price(inputPrice), countBottles(inputCount) {
    memcpy(mark, inputMark, strlen(inputMark) + 1);
    sizeLibrary++;
}
wineLibrary::wineLibrary()
    : date(ClassConstants::kDefaultDate),
      mark(new char[ClassConstants::kDefaultLenMark]),
      price(ClassConstants::kDefaultPrice),
      countBottles(ClassConstants::kDefaultCount) {
    memcpy(mark, ClassConstants::kDefaulMarkText, ClassConstants::kDefaultLenMark);
    sizeLibrary++;
}
wineLibrary::wineLibrary(const wineLibrary& other)
    : date(other.date), mark(new char[strlen(other.mark) + 1]), price(other.price), countBottles(other.countBottles) {
    memcpy(mark, other.mark, strlen(other.mark) + 1);
    sizeLibrary++;
}
wineLibrary& wineLibrary::operator=(wineLibrary other) {
    std::swap(date, other.date);
    std::swap(mark, other.mark);
    std::swap(price, other.price);
    std::swap(countBottles, other.countBottles);
    return *this;
}
void wineLibrary::set(int inputDate, const char* inputMark, int inputPrice, int inputCount) {
    delete[] mark;

    date = inputDate;
    price = inputPrice;
    countBottles = inputCount;

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
    return countBottles;
}
int wineLibrary::getPrice() const {
    return price;
}
const char* wineLibrary::getMark() const {
    return mark;
}
void wineLibrary::setDate(int inputDate) {
    date = inputDate;
}
void wineLibrary::setPrice(int inputPrice) {
    price = inputPrice;
}
void wineLibrary::setCount(int inputCount) {
    countBottles = inputCount;
}
void wineLibrary::setMark(const char* inputMark) {
    delete[] mark;
    if (inputMark) {
        size_t len = strlen(inputMark) + ClassConstants::kEmptySymbolAppend;
        mark = new char[len];
        memcpy(mark, inputMark, len);
    } else {
        mark = nullptr;
    }
}
wineLibrary::~wineLibrary() {
    delete[] mark;
    sizeLibrary--;
};
std::ostream& operator<<(std::ostream& out, const wineLibrary& wine) {
    if (&out == &std::cout) {
        out << "марка:" << wine.getMark();
        out << " (" << wine.getDate() << " год)";
        out << " - " << wine.getPrice() << " руб";
        out << " [" << wine.getCount() << " шт]" << std::endl;
    } else {
        out << wine.getMark() << " " << wine.getDate() << " " << wine.getPrice() << " " << wine.getCount();
        out << "\n";
    }

    return out;
}
std::istream& operator>>(std::istream& in, wineLibrary& wine) {
    char inputBuffer[ClassConstants::kBufferSizeInitialize];
    int inputDate{ClassConstants::kDefaultCount};
    int inputCount{ClassConstants::kDefaultCount};
    int inputPrice{ClassConstants::kDefaultCount};

    if (&in == &std::cin) {
        std::cout << "Введите марку:\t";
    }
    in >> inputBuffer;

    if (&in == &std::cin) {
        std::cout << "Введите год:\t";
    }
    in >> inputDate;

    if (&in == &std::cin) {
        std::cout << "Введите цену:\t";
    }
    in >> inputPrice;

    if (&in == &std::cin) {
        std::cout << "Введите количество:\t";
    }
    in >> inputCount;

    wine.set(inputDate, inputBuffer, inputPrice, inputCount);
    return in;
}
