#include "menu.hpp"
#include "menuFunc.hpp"
#include "sortLib.hpp"


void StartMenu() {
    wineLibrary test(MenuConstants::kTestDate, MenuConstants::kTestMarkText, MenuConstants::kTestPrice, MenuConstants::kTestCount);
    std::cout << test;
    wineLibrary* testarray = new wineLibrary[MenuConstants::kArraySize];
    int choice{};

    int wineLibraryCount{MenuConstants::kStartCountInitialize};
    std::cout << std::endl;
    while (MenuConstants::kIsRunning) {
        std::cout << "1. Добавить объект в массив\n";
        std::cout << "2. Вывести весь массив\n";
        std::cout << "3. Загрузка данных из файла\n";
        std::cout << "4. Сохранение данных в файл\n";
        std::cout << "5. Удаление объекта\n";
        std::cout << "6. Сортировка массива\n";
        std::cout << "7. Поиск объекта\n";
        std::cout << "8. Редактирование объекта\n";
        std::cout << "9. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case MenuConstants::kAppendObject: {
                if (wineLibraryCount < MenuConstants::kArraySize) {
                    std::cout << "Введите объект\n";
                    std::cin >> testarray[wineLibraryCount];
                    wineLibraryCount++;
                } else {
                    std::cout << "Массив полон\n";
                }
                break;
            }

            case MenuConstants::kShowAllMassive: {
                if (wineLibraryCount == MenuConstants::kStartCountInitialize) {
                    std::cout << "Массив пуст\n";
                    break;
                }
                for (int i = MenuConstants::kStartCountInitialize; i < wineLibraryCount; ++i) {
                    std::cout << testarray[i];
                }
                break;
            }

            case MenuConstants::kLoadFromFile: {
                loadFromFile(testarray, &wineLibraryCount);
                break;
            }
            case MenuConstants::kLoadToFile: {
                loadToFile(testarray, &wineLibraryCount);
                break;
            }
            case MenuConstants::kDeleteObject: {
                deleteObject(testarray, &wineLibraryCount);
                break;
            }
            case MenuConstants::kSortMassive: {
                sortWineLibrary(testarray, &wineLibraryCount);
                break;
            }
            case MenuConstants::kSearchObject: {
                searchObject(testarray, &wineLibraryCount);
                break;
            }
            case MenuConstants::kRedactObject: {
                redactObject(testarray, &wineLibraryCount);
                break;
            }
            case MenuConstants::kExit: {
                delete[] testarray;
                std::cout << "Программа завершена\n";
                return;
            }
        }
    }
    delete[] testarray;
}
