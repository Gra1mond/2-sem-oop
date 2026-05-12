#include"Database.h"
#include"Planet.h"
#include"functors.h"
#include <algorithm>
#include "WineLibrary.h"

void RunWineApplication() {
    const int kMenuAdd      = 1;
    const int kMenuDisplay  = 2;
    const int kMenuSortAsc  = 3;
    const int kMenuSortDesc = 4;
    const int kMenuCopy     = 5;
    const int kMenuFind     = 6;
    const int kMenuSave     = 7;
    const int kMenuLoad     = 8;
    const int kMaxItems     = 100;

    Database<wineLibrary> db;
    int choice = 0;
    while (true) {
        std::cout << "\n1. Добавить\n2. Вывести\n3. Сортировка ↑\n"
                  << "4. Сортировка \n5. Скопировать с условием\n"
                  << "6. Найти\n7. Сохранить\n8. Загрузить\n0. Выход\nВыбор: ";
        std::cin >> choice;
        if (choice == 0) { break; }
        switch (choice) {
            case kMenuAdd:     db.input_from_console(); break;
            case kMenuDisplay: db.display(); break;
            case kMenuSortAsc:  db.sort_qsort(Ascending<wineLibrary>()); break;
            case kMenuSortDesc: db.sort_qsort(Descending<wineLibrary>()); break;
            case kMenuCopy: {
                Database<wineLibrary> db2;
                wineLibrary tmp[kMaxItems];
                wineLibrary* end_ptr = std::copy_if(db.begin(), db.end(), tmp,
                    [](const wineLibrary&){ return true; });
                for (wineLibrary* it = tmp; it != end_ptr; ++it) {
                    db2.add(*it);
                }
                db2.display();
                break;
            }
            case kMenuFind: {
                char buf[256];
                std::cout << "Введите марку: ";
                std::cin >> buf;
                std::string query(buf);
                int idx = db.find_if([&query](const wineLibrary& w){
                    return strcmp(w.getMark(), query.c_str()) == 0;
                });
                std::cout << (idx == -1 ? "Не найдено" : "Индекс: " + std::to_string(idx)) << "\n";
                break;
            }
            case kMenuSave: db.write_to_file("wine.txt"); break;
            case kMenuLoad: db.clear(); db.read_from_file("wine.txt"); db.display(); break;
        }
    }
}

void RunApplication() {
    const int kMenuAdd      = 1;
    const int kMenuDisplay  = 2;
    const int kMenuSortAsc  = 3;
    const int kMenuSortDesc = 4;
    const int kMenuCopy     = 5;
    const int kMenuFind     = 6;
    const int kMenuSave     = 7;
    const int kMenuLoad     = 8;
    const int kMaxItems     = 100;

    Database<Planet> db;
    int choice = 0;

    while (true) {
        std::cout << "\n1. Добавить элемент\n"
                  << "2. Вывести содержимое\n"
                  << "3. Сортировка по возрастанию\n"
                  << "4. Сортировка по убыванию\n"
                  << "5. Скопировать с условием\n"
                  << "6. Найти элемент\n"
                  << "7. Сохранить в файл\n"
                  << "8. Загрузить из файла\n"
                  << "0. Выход\n"
                  << "Выбор: ";
        std::cin >> choice;
        if (choice == 0) { break; }

        switch (choice) {
            case kMenuAdd:     db.input_from_console(); break;
            case kMenuDisplay: db.display(); break;
            case kMenuSortAsc:  db.sort_qsort(Ascending<Planet>()); break;
            case kMenuSortDesc: db.sort_qsort(Descending<Planet>()); break;
            case kMenuCopy: {
                Database<Planet> db2;
                Planet tmp[kMaxItems];
                Planet* end_ptr = std::copy_if(db.begin(), db.end(), tmp,
                    [](const Planet& p){ return p.getHasLife(); });
                for (Planet* it = tmp; it != end_ptr; ++it) {
                    db2.add(*it);
                }
                db2.display();
                break;
            }
            case kMenuFind: {
                char buf[256];
                std::cout << "Введите название планеты: ";
                std::cin >> buf;
                std::string query(buf);
                int idx = db.find_if([&query](const Planet& p){
                    return strcmp(p.getName(), query.c_str()) == 0;
                });
                std::cout << (idx == -1 ? "Не найдено" : "Найдено на индексе: " + std::to_string(idx)) << "\n";
                break;
            }
            case kMenuSave: db.write_to_file("planets.txt"); break;
            case kMenuLoad: db.clear(); db.read_from_file("planets.txt"); db.display(); break;
        }
    }
}

int main() {
    int choice = 0;
    std::cout << "1. База планет\n2. База вин\nВыбор: ";
    std::cin >> choice;
    if (choice == 1) {
        RunApplication();
    } else {
        RunWineApplication();
    }
    return 0;
}
