#include "menu.hpp"
#include "sortLib.hpp"
#include "wine_library.hpp"
#include "menuFunc.hpp" 
bool isEmptyMassive(const int WineLibraryCount) {
    if (WineLibraryCount == 0) {
        std::cout << "Массив пуст\n";
        return true;
    }
    return false;
}

void loadFromFile(wineLibrary*& testarray, int* wineLibraryCount) {
    std::ifstream inputFileLibrary;
    inputFileLibrary.open(MenuConstants::FILE_PATH, std::ios::binary);
    if (!inputFileLibrary.is_open()) {
        std::cerr << "Ошибка открытия,не удалось найти путь файла\n" << MenuConstants::FILE_PATH << std::endl;
        return;
    }
    int fileWineLibraryCount{0};
    int currentIndex{0};
    char currentPos{0};

    while (inputFileLibrary.get(currentPos) && currentPos != EOF) {
        if (currentPos == '\n') {
            fileWineLibraryCount++;
        }
    }
    inputFileLibrary.clear();
    inputFileLibrary.seekg(0, std::ios::beg);
    delete[] testarray;
    testarray = new wineLibrary[fileWineLibraryCount];
    while (currentIndex < fileWineLibraryCount && inputFileLibrary >> testarray[currentIndex]) {
        currentIndex++;
    }
    inputFileLibrary.close();
    *wineLibraryCount = currentIndex;
    std::cout << "Загружено " << currentIndex << std::endl;
}
void loadToFile(wineLibrary*& testarray, int* wineLibraryCount) {
    std::ofstream outputFileLibrary(MenuConstants::FILE_PATH, std::ios::binary);
    if (!outputFileLibrary.is_open()) {
        std::cerr << "Ошибка открытия файла для записи\n";
    }
    if (isEmptyMassive(*wineLibraryCount)) {
        std::cout << "Массив пользователей пуст\n";
        return;
    }
    int currentIndex{0};
    while (currentIndex < *wineLibraryCount && outputFileLibrary << testarray[currentIndex]) {
        currentIndex++;
    }
    outputFileLibrary.close();
}
void addNewobject(wineLibrary*& testarray, int* currentPos, int* wineLibraryCount) {
    if (*currentPos < *wineLibraryCount) {
        std::cout << "Введите объект\n";
        std::cin >> testarray[*currentPos];
        (*currentPos)++;
    } else {
        std::cout << "Массив полон\n";
        return;
    }
}

void deleteObject(wineLibrary*& testarray, int* wineLibraryCount) {
    if (isEmptyMassive(*wineLibraryCount)) {
        std::cerr << "Массив пуст(нет элементов для удаления)\n";
        return;
    }
    int choice{0};
    std::cout << "Выберите критерий для удаления\n";
    std::cout << "1. Марка\n";
    std::cout << "2. Год создания\n";
    std::cout << "3. Цена\n";
    std::cout << "4. Колличество\n";
    std::cin >> choice;
    deleteChoise rightChoice = static_cast<deleteChoise>(choice);
    switch (rightChoice) {
        case deleteChoise::Mark: {
            char searchValue[MenuConstants::kSearchMarkLen];
            std::cout << "Введите марку для удаления: ";
            std::cin >> searchValue;

            int deleted{0};
            for (int i = *wineLibraryCount - 1; i >= 0; i--) {
                if (strcmp(testarray[i].getMark(), searchValue) == 0) {
                    for (int j = i; j < *wineLibraryCount - 1; j++) {
                        testarray[j] = testarray[j + 1];
                    }
                    (*wineLibraryCount)--;
                    deleted++;
                }
            }

            std::cout << "Удалено " << deleted << " объектов\n";
            break;
        }
        case deleteChoise::Year: {
            int searchYear{0};
            std::cout << "Введите год удаления: ";
            std::cin >> searchYear;

            int deleted{0};
            for (int i = *wineLibraryCount - 1; i >= 0; --i) {
                if (testarray[i].getDate() == searchYear) {
                    for (int j = i; j < *wineLibraryCount - 1; ++j) {
                        testarray[j] = testarray[j + 1];
                    }
                    deleted++;
                    (*wineLibraryCount)--;
                }
            }
            std::cout << "Удалено " << deleted << " объектов\n";
            break;
        }
        case deleteChoise::Price: {
            int searchPrice{0};
            std::cout << "Введите цену удаления: ";
            std::cin >> searchPrice;

            int deleted{0};
            for (int i = *wineLibraryCount - 1; i >= 0; --i) {
                if (testarray[i].getDate() == searchPrice) {
                    for (int j = i; j < *wineLibraryCount - 1; ++j) {
                        testarray[j] = testarray[j + 1];
                    }
                    deleted++;
                    (*wineLibraryCount)--;
                }
            }
            std::cout << "Удалено " << deleted << " объектов\n";
            break;
        }
        case deleteChoise::Count: {
            int searchCount{0};
            std::cout << "Введите количество удаления: ";
            std::cin >> searchCount;

            int deleted{0};
            for (int i = *wineLibraryCount - 1; i >= 0; --i) {
                if (testarray[i].getDate() == searchCount) {
                    for (int j = i; j < *wineLibraryCount - 1; ++j) {
                        testarray[j] = testarray[j + 1];
                    }
                    deleted++;
                    (*wineLibraryCount)--;
                }
            }
            std::cout << "Удалено " << deleted << " объектов\n";
            break;
        }
        default: {
            std::cerr << "Отсуттвует такой критерий, удаление невозможно\n";
        }
    }
}

void searchObject(wineLibrary*& testarray, int* wineLibraryCount) {
    if (isEmptyMassive(*wineLibraryCount)) {
        std::cerr << "Массив пуст(нет элементов для поиска)\n";
        return;
    }
    std::cout << "1. Марка\n";
    std::cout << "2. Год выпуска\n";
    std::cout << "3. Количество\n";
    std::cout << "4. Цена\n";
    std::cout << "Выберите критерий удаления: ";

    int choise{0};
    std::cin >> choise;
    std::cout << "Введите значение поиска\n";
    char searchMark[MenuConstants::kSearchMarkLen];
    int searchYear{0};
    char searchPrice{0};
    int searchCount{0};

    switch (static_cast<deleteChoise>(choise)) {
        case deleteChoise::Mark: {
            std::cin.getline(searchMark, MenuConstants::kSearchMarkLen);
            break;
        }

        case deleteChoise::Year: {
            std::cin >> searchYear;
            break;
        }
        case deleteChoise::Price: {
            std::cin >> searchPrice;
            break;
        }
        case deleteChoise::Count: {
            std::cin >> searchCount;
            break;
        }
        default: {
            std::cout << "Таког варианта не существует!!!\n";
            return;
        }
    }
    std::cout << "Рузультаты поиска:\n";

    for (int currentPosition{0}; currentPosition < *wineLibraryCount; ++currentPosition) {
        bool found{false};

        if (choise == static_cast<int>(deleteChoise::Year) && testarray[currentPosition].getDate() == searchYear) {
            found = true;
        }
        if (choise == static_cast<int>(deleteChoise::Price) && testarray[currentPosition].getPrice() == searchPrice) {
            found = true;
        }
        if (choise == static_cast<int>(deleteChoise::Count) && testarray[currentPosition].getCount() == searchCount) {
            found = true;
        }
        if (choise == static_cast<int>(deleteChoise::Mark) && (std::strcmp(testarray[currentPosition].getMark(), searchMark) == 0)) {
            found = true;
        }
        if (found) {
            std::cout << currentPosition + MenuConstants::kStartCountInitialize << "." << testarray[currentPosition] << std::endl;
        }
    }
}

void redactObject(wineLibrary*& testarray, int* wineLibraryCount) {
    if (isEmptyMassive(*wineLibraryCount)) {
        std::cerr << "Массив пуст(нет элементов для редактирования)\n";
        return;
    }
    std::cout << "Введите номер вина для редактирования\n";
    int inputRedactNumber{0};
    std::cin >> inputRedactNumber;
    int redactNumber{inputRedactNumber - MenuConstants::kIndexShift};
    std::cout << "Выберите параметр для изменения\n";
    std::cout << "1-Марка,2-Год,3-Цена,4-Количество";
    int redactProperty{0};
    std::cin >> redactProperty;
    switch (static_cast<deleteChoise>(redactProperty)) {
        case deleteChoise::Mark: {
            std::cout << "Выбрана марка для редактирования\n";
            std::cout << testarray[redactNumber].getMark() << std::endl;
            std::cout << "Введите новую марку\n";
            char newMark[MenuConstants::kSearchMarkLen]{0};
            std::cin >> newMark;
            testarray[redactNumber].setMark(newMark);
            break;
        }
        case deleteChoise::Year: {
            std::cout << "Выбран год для редактирования\n";
            std::cout << testarray[redactNumber].getDate() << std::endl;
            std::cout << "Введите новый год\n";
            int newDate{0};
            std::cin >> newDate;
            testarray[redactNumber].setDate(newDate);
            break;
        }
        case deleteChoise::Price: {
            std::cout << "Выбрана цена для редактирования\n";
            std::cout << testarray[redactNumber].getPrice() << std::endl;
            std::cout << "Введите новую цену\n";
            int newPrice{0};
            std::cin >> newPrice;
            testarray[redactNumber].setPrice(newPrice);
            break;
        }
        case deleteChoise::Count: {
            std::cout << "Выбрано количество для редактирования\n";
            std::cout << testarray[redactNumber].getCount() << std::endl;
            std::cout << "Введите новое количество\n";
            int newCount{0};
            std::cin >> newCount;
            testarray[redactNumber].setCount(newCount);
            break;
        }
        default: {
            std::cerr << "Ошибка: неверный выбор параметра\n";
            return;
        }
            std::cout << "Объект успешно отредактирован\n";
    }
}
