#include"Database.h"
#include"Planet.h"
#include"functors.h"
#include <algorithm>
#include "WineLibrary.h"
void RunWineApplication() {
      Database<wineLibrary> db;
      int choice;
      do {
          std::cout << "\n1. Добавить\n2. Вывести\n3. Сортировка ↑\n"
                    << "4. Сортировка ↓\n5. Скопировать с условием\n"
                    << "6. Найти\n7. Сохранить\n8. Загрузить\n0. Выход\nВыбор: ";
          std::cin >> choice;
          switch (choice) {
              case 1: db.input_from_console(); break;
              case 2: db.display(); break;
              case 3: db.sort_qsort(Ascending<wineLibrary>()); break;
              case 4: db.sort_qsort(Descending<wineLibrary>()); break;
              case 5: {
                  Database<wineLibrary> db2;
                  wineLibrary tmp[100];
                  wineLibrary* end_ptr = std::copy_if(db.begin(), db.end(), tmp,
                      [](const wineLibrary& w){ return true; }); 
                  for (wineLibrary* it = tmp; it != end_ptr; ++it)
                      db2.add(*it);
                  db2.display();
                  break;
              }
              case 6: {
                  wineLibrary w;
                  std::cin >> w;
                  int idx = db.find(w);
                  std::cout << (idx == -1 ? "Не найдено" : "Индекс: " + std::to_string(idx)) << "\n";
                  break;
              }   
              case 7: db.write_to_file("wine.txt"); break;
              case 8: db.clear(); db.read_from_file("wine.txt"); db.display(); break;
          }
      } while (choice != 0);
  }
void RunApplication() {
    Database<Planet> db;
    int choice;

    do {
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

        switch (choice) {
            case 1: db.input_from_console(); break;
            case 2: db.display(); break;
            case 3: db.sort_qsort(Ascending<Planet>()); break;
            case 4: db.sort_qsort(Descending<Planet>()); break;
              case 5: {
                Database<Planet> db2;
                Planet tmp[100];
                Planet* end_ptr = std::copy_if(db.begin(), db.end(), tmp,
                    [](const Planet& p){ return p.getHasLife(); });
                for (Planet* it = tmp; it != end_ptr; ++it)
                    db2.add(*it);
                db2.display();
                break;
            }
           case 6: {
                Planet p;
                std::cout << "Введите данные планеты для поиска:\n";
                std::cin >> p;
                int idx = db.find(p);
                if (idx == -1)
                    std::cout << "Не найдено\n";
                else
                    std::cout << "Найдено на индексе: " << idx << "\n";
                break;
            }
            case 7: db.write_to_file("planets.txt"); break;
            case 8: db.clear(); db.read_from_file("planets.txt"); db.display(); break;
        }
    } while (choice != 0);
}

int main() {
      int choice;
      std::cout << "1. База планет\n2. База вин\nВыбор: ";
      std::cin >> choice;
      if (choice == 1) RunApplication();
      else RunWineApplication();
      return 0;
}