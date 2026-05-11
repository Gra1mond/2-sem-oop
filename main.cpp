#include <algorithm>
#include <list>
#include <map>
#include <numeric>
#include <vector>
#include "myStack.h"

// ========== ЗАДАНИЕ 2 ==========

void Multipliers(int n, MyStack<int>& stack) {
    int d = 2;
    while (n > 1) {
        while (n % d == 0) {
            stack.push(d);
            n /= d;
        }
        d++;
    }
}

// ========== ЗАДАНИЕ 3.1 ==========

// 3.1.3
struct Descending {
    bool operator()(int a, int b) { return a > b; }
};

void task3_1(MyStack<int>& stack) {
    // 3.1.1
    MyStack<int> stack2;
    int val = 0;
    while (stack.pop(val)) {
        stack2.push(val);
    }
    std::vector<int> vect;
    while (stack2.pop(val)) {
        vect.push_back(val);
    }

    std::cout << "Исходный вектор (возрастающий): ";
    std::for_each(vect.begin(), vect.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    // 3.1.2
    std::sort(vect.begin(), vect.end(), Descending());

    std::cout << "Вектор после сортировки по убыванию: ";
    std::for_each(vect.begin(), vect.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    int target = 2;
    auto count = std::count_if(vect.begin(), vect.end(), [target](int x) { return x == target; });
    std::cout << "Количество двоек: " << count << std::endl;

    std::vector<int> squares(vect.size());
    std::transform(vect.begin(), vect.end(), squares.begin(), [](int x) { return x * x; });

    std::cout << "Квадраты элементов: ";
    std::for_each(squares.begin(), squares.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    std::cout << "Вывод через for_each: ";
    std::for_each(vect.begin(), vect.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;
}

// ========== ЗАДАНИЕ 3.2 ==========

void task3_2(MyStack<int>& stack) {
    // 3.2.1
    MyStack<int> stack2;
    int val = 0;
    while (stack.pop(val)) {
        stack2.push(val);
    }
    std::list<int> list;
    while (stack2.pop(val)) {
        list.push_back(val);
    }

    std::cout << "Исходный список: ";
    std::for_each(list.begin(), list.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    // 3.2.2
    int target_remove = 2;
    auto it_remove = std::remove_if(list.begin(), list.end(), [target_remove](int x) { return x == target_remove; });
    list.erase(it_remove, list.end());

    std::cout << "Список после удаления двоек: ";
    std::for_each(list.begin(), list.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    const int target_find = 5;
    auto it = std::find_if(list.begin(), list.end(), [](int x) { return x == target_find; });
    if (it != list.end()) {
        std::cout << "Поиск элемента " << target_find << ": найден" << std::endl;
    } else {
        std::cout << "Поиск элемента " << target_find << ": не найден" << std::endl;
    }

    int target_count = 3;
    auto count = std::count_if(list.begin(), list.end(), [target_count](int x) { return x > target_count; });
    std::cout << "Количество элементов > " << target_count << ": " << count << std::endl;
}

// ========== ЗАДАНИЕ 3.3 ==========

void task3_3(MyStack<int>& stack) {
    // 3.3.1
    MyStack<int> stack2;
    int val = 0;
    while (stack.pop(val)) {
        stack2.push(val);
    }
    std::vector<int> vect;
    while (stack2.pop(val)) {
        vect.push_back(val);
    }
    std::map<int, int> map;
    for (int x : vect) {
        map[x]++;
    }
    // 3.3.2
    std::cout << "Содержимое map (множитель -> количество):" << std::endl;
    for (auto& pair : map) {
        std::cout << pair.first << " -> " << pair.second << std::endl;
    }

    int search_key = 3;
    auto it = map.find(search_key);
    if (it != map.end()) {
        std::cout << "Поиск ключа " << search_key << ": найден, количество = " << it->second << std::endl;
    } else {
        std::cout << "Поиск ключа " << search_key << ": не найден" << std::endl;
    }

    auto count = std::count_if(map.begin(), map.end(), [](auto& pair) { return pair.second > 1; });
    std::cout << "Количество множителей, встречающихся более 1 раза: " << count << std::endl;
}

// ========== ЗАДАНИЕ 3.4 ==========

void task3_4(MyStack<int>& stack) {
    // 3.4.1
    MyStack<int> stack2;
    int val = 0;
    while (stack.pop(val)) {
        stack2.push(val);
    }
    std::vector<int> vect;
    while (stack2.pop(val)) {
        vect.push_back(val);
    }
    std::vector<int> squares(vect.size());
    std::transform(vect.begin(), vect.end(), squares.begin(), [](int x) { return x * x; });

    std::cout << "Вектор множителей: ";
    std::for_each(vect.begin(), vect.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    std::cout << "Вектор квадратов: ";
    std::for_each(squares.begin(), squares.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    // 3.4.2
    int result = std::inner_product(vect.begin(), vect.end(), squares.begin(), 0);
    std::cout << "Скалярное произведение: " << result << std::endl;

    // 3.4.3
    std::vector<int> summs(vect.size());
    std::transform(vect.begin(), vect.end(), squares.begin(), summs.begin(), [](int a, int b) { return a + b; });

    std::cout << "Вектор сумм: ";
    std::for_each(summs.begin(), summs.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;
}

// ========== ЗАДАНИЕ 4 ==========

void task4(MyStack<int>& stack) {
    MyStack<int> stack2;
    int val = 0;
    while (stack.pop(val)) {
        stack2.push(val);
    }
    std::vector<int> vect;
    while (stack2.pop(val)) {
        vect.push_back(val);
    }

    // 4.3
    int product = std::accumulate(vect.begin(), vect.end(), 1, [](int a, int b) { return a * b; });
    std::cout << "Произведение всех множителей: " << product << std::endl;
}

template<typename Container>
void printContainer(const Container& cont) {
    std::for_each(cont.begin(), cont.end(), [](const auto& elem) { std::cout << elem << ' '; });
    std::cout << std::endl;
}

template<typename K, typename V>
void printContainer(const std::map<K, V>& cont) {
    std::for_each(cont.begin(), cont.end(), [](const auto& pair) { std::cout << pair.first << " -> " << pair.second << ' '; });
    std::cout << std::endl;
}
// ========== MAIN ==========

int main() {
    MyStack<int> stack;
    const int number = 3960;

    std::cout << "========== ЗАДАНИЕ 2: Разложение на множители ==========" << std::endl;
    Multipliers(number, stack);

    std::vector<int> factors;
    int val = 0;
    while (stack.pop(val)) {
        factors.push_back(val);
    }

    std::cout << number << " = ";
    for (size_t i = 0; i < factors.size(); i++) {
        if (i > 0) {
            std::cout << " * ";
        }
        std::cout << factors[i];
    }
    std::cout << std::endl;

    std::cout << number << " = ";
    for (int i = (int)factors.size() - 1; i >= 0; i--) {
        if (i < (int)factors.size() - 1) {
            std::cout << " * ";
        }
        std::cout << factors[i];
    }
    std::cout << std::endl << std::endl;

    std::cout << "========== ЗАДАНИЕ 3.1: Работа с vector ==========" << std::endl;
    Multipliers(number, stack);
    task3_1(stack);
    std::cout << std::endl;

    std::cout << "========== ЗАДАНИЕ 3.2: Работа с list ==========" << std::endl;
    Multipliers(number, stack);
    task3_2(stack);
    std::cout << std::endl;

    std::cout << "========== ЗАДАНИЕ 3.3: Работа с map ==========" << std::endl;
    Multipliers(number, stack);
    task3_3(stack);
    std::cout << std::endl;

    std::cout << "========== ЗАДАНИЕ 3.4: Работа с несколькими контейнерами ==========" << std::endl;
    Multipliers(number, stack);
    task3_4(stack);
    std::cout << std::endl;

    std::cout << "========== ЗАДАНИЕ 4: Дополнительные задания ==========" << std::endl;
    Multipliers(number, stack);
    task4(stack);

    std::cout << "\n4.2 Демонстрация printContainer:" << std::endl;
    Multipliers(number, stack);
    MyStack<int> tmp;
    int v = 0;
    while (stack.pop(v)) {
        tmp.push(v);
    }
    std::vector<int> demo_vec;
    while (tmp.pop(v)) {
        demo_vec.push_back(v);
    }

    std::list<int> demo_list(demo_vec.begin(), demo_vec.end());
    std::map<int, int> demo_map;
    for (int x : demo_vec) {
        demo_map[x]++;
    }

    std::cout << "vector: ";
    printContainer(demo_vec);
    std::cout << "list:   ";
    printContainer(demo_list);
    std::cout << "map:    ";
    printContainer(demo_map);

    return 0;
}
