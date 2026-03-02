#include "menu.hpp"
#include "wine_library.hpp"
void StartMenu() {
    wineLibrary test(MenuConstants::kTestDate, MenuConstants::kTestMarkText, MenuConstants::kTestPrice, MenuConstants::kTestCount);
    std::cout << test;

    wineLibrary testarray[MenuConstants::kArraySize];
    int choice{};

    int realCount{MenuConstants::kStartCountInitialize};
    std::cout << std::endl;
    while (MenuConstants::kIsRunning) {
        std::cout << "1. Добавить объект в массив\n";
        std::cout << "2. Вывести весь массив\n";
        std::cout << "3. Ввести несколько объектов в массив\n";
        std::cout << "4. Вывод конкретного n-го объекта массива\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case MenuConstants::kAppendObject:
                if (realCount < MenuConstants::kArraySize) {
                    std::cout << "Введите объект\n";
                    std::cin >> testarray[realCount];
                    realCount++;
                } else {
                    std::cout << "Массив полон\n";
                }
                break;

            case MenuConstants::kShowAllMassive:
                if (realCount == MenuConstants::kStartCountInitialize) {
                    std::cout << "Массив пуст\n";
                    break;
                }
                for (int i = MenuConstants::kStartCountInitialize; i < realCount; ++i) {
                    std::cout << testarray[i];
                }
                break;

            case MenuConstants::kShowSomeElements: {
                std::cout << "Введите количество объектов для добавления\n";
                int numberObjects{MenuConstants::kStartCountInitialize};
                std::cin >> numberObjects;
                if (numberObjects > MenuConstants::kArraySize - realCount) {
                    std::cout << "Нельзя добавить так много объектов\n";
                    break;
                }
                for (int i = MenuConstants::kStartCountInitialize; i < numberObjects; i++) {
                    std::cin >> testarray[realCount];
                    realCount++;
                }
                break;
            }

            case MenuConstants::kShowNElement: {
                int indexObject{MenuConstants::kStartCountInitialize};
                std::cout << "Введите номер переменной\n";
                std::cin >> indexObject;
                if (indexObject > MenuConstants::kArraySize) {
                    std::cout << "Номер не может быть больше размера массива\n";
                    break;
                }
                std::cout << testarray[indexObject - MenuConstants::kIndexShift] << std::endl;
                break;
            }

            case MenuConstants::kExit:
                std::cout << "Программа завершена\n";
                return;

            default:
                std::cout << "Неверный выбор\n";
        }
    }
}
