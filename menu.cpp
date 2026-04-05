#include "EngineClass.hpp"

void startMenu() {
    int choice{-1};
    while (choice != 0) {
        std::cout << "\n===== МЕНЮ =====\n";
        std::cout << "1. Добавить двигатель\n";
        std::cout << "2. Удалить двигатель\n";
        std::cout << "3. Показать все двигатели\n";
        std::cout << "4. Очистить контейнер\n";
        std::cout << "0. Выход\n";
        std::cout << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int type{0};
                std::cout << "Тип двигателя:\n";
                std::cout << "1 - ДВС\n";
                std::cout << "2 - Дизель\n";
                std::cout << "3 - Турбореактивный\n";
                std::cin >> type;

                Engine* e = nullptr;

                if (type == 1) {
                    int power{0};
                    int price{0};
                    std::cout << "Введите мощность и цену: ";
                    std::cin >> power >> price;
                    e = new InternalCombustionEngine(power, price);
                } else if (type == 2) {
                    double torque{0.0};
                    std::cout << "Введите крутящий момент: ";
                    std::cin >> torque;
                    e = new DieselEngine(torque);
                } else if (type == 3) {
                    int input{0};
                    bool turbine{false};
                    std::cout << "Определите наличие турбины:\nВведите 0 - если турбины нет, или введите количество турбин\n";
                    std::cin >> input;
                    turbine=static_cast<bool>(input); 
                    e = new TurbojetEngine(turbine);
                }
                if (e) {
                    Engine::add(e);
                }
                break;
            }
            case (2): {
                std::cout << "Введите id для удаления:\t";
                int deleteId{0};
                std::cin >> deleteId;
                Engine::remove(deleteId);
                break;
            }
            case (3): {
                Engine::print();
                break;
            }
            case (4): {
                Engine::clear();
                break;
            }
            case (0): {
                std::cout << "Выход...\n";
                break;
            }
            default: {
                std::cout << "Неправильный выбор команды!!!\n";
            }
        }
    }
}
