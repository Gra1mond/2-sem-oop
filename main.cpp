#include <iostream>
#include <string>
#include "containers/Container.h"
#include "containers/Set.h"

namespace Const {
    constexpr int TWO = 2;
    constexpr int THREE = 3;
    constexpr int FIVE = 5;
    constexpr int TEN = 10;
    constexpr int BUFFER_SIZE = 20;

    constexpr double ONE_POINT_FIVE = 1.5;
    constexpr double TWO_POINT_ZERO = 2.0;
    constexpr double THREE_POINT_NINE_NINE = 3.99;
    constexpr double THREE_POINT_NINE_EIGHT = 3.98;
    constexpr double TEN_D = 10.0;
}

int main() {

    // ===== Container =====
    const char* tmp1 = "Hello!";
    const char* tmp2 = "Привет!";
    const char* tmp3 = "World";
    const char* tmp4 = "Test";
    const char* tmp5 = "Another";
    const char* tmp6 = "Example";
    const char* tmp7 = "Yes";
    const char* tmp8 = "No";
    const char* tmp9 = "Cat";
    const char* tmp10 = "Dog";

    // Создаём буферы и копируем с помощью strncpy
    char* buffer1 = new char[Const::BUFFER_SIZE];
    char* buffer2 = new char[Const::BUFFER_SIZE];
    char* buffer3 = new char[Const::BUFFER_SIZE];
    char* buffer4 = new char[Const::BUFFER_SIZE];
    char* buffer5 = new char[Const::BUFFER_SIZE];
    char* buffer6 = new char[Const::BUFFER_SIZE];
    char* buffer7 = new char[Const::BUFFER_SIZE];
    char* buffer8 = new char[Const::BUFFER_SIZE];
    char* buffer9 = new char[Const::BUFFER_SIZE];
    char* buffer10 = new char[Const::BUFFER_SIZE];

    strncpy(buffer1, tmp1, Const::BUFFER_SIZE - 1);
    buffer1[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer2, tmp2, Const::BUFFER_SIZE - 1);
    buffer2[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer3, tmp3, Const::BUFFER_SIZE - 1);
    buffer3[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer4, tmp4, Const::BUFFER_SIZE - 1);
    buffer4[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer5, tmp5, Const::BUFFER_SIZE - 1);
    buffer5[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer6, tmp6, Const::BUFFER_SIZE - 1);
    buffer6[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer7, tmp7, Const::BUFFER_SIZE - 1);
    buffer7[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer8, tmp8, Const::BUFFER_SIZE - 1);
    buffer8[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer9, tmp9, Const::BUFFER_SIZE - 1);
    buffer9[Const::BUFFER_SIZE - 1] = '\0';

    strncpy(buffer10, tmp10, Const::BUFFER_SIZE - 1);
    buffer10[Const::BUFFER_SIZE - 1] = '\0';

    Container<char*> v(buffer1);
    v.push(buffer2);
    v.push(buffer3);
    v.push(buffer4);

    std::cout << "Вектор v: " << v << std::endl;

    int index = v.find(buffer3);
    std::cout << "Индекс элемента 'World': " << index << std::endl;

    v.push(buffer5);
    v.push(buffer6);

    std::cout << "Вектор v после добавления: " << v << std::endl;

    Container<char*> v1 = v;
    std::cout << "Копия v1: " << v1 << std::endl;

    v1.pop(2);
    std::cout << "v1 после удаления элемента с индексом 2: " << v1 << std::endl;


    // ===== Set =====
    Set<char*> s(buffer7);
    Set<char*> s1(buffer1);
    Set<char*> s2;

    s.push(buffer2);
    s.push(buffer8);
    s.push(buffer3);

    std::cout << "\nМножество s: " << s << std::endl;

    if (s.is_element(buffer8)) {
        std::cout << "'No' есть в множестве s\n";
    }

    s1.push(buffer9);
    s1.push(buffer10);
    s1.push(buffer2);

    std::cout << "Множество s1: " << s1 << std::endl;

    s2 = s1 - s;
    std::cout << "s2 = s1 - s: " << s2 << std::endl;

    s2 = s1 + s;
    std::cout << "s2 = s1 + s: " << s2 << std::endl;

    s2 = s1 * s;
    std::cout << "s2 = s1 * s: " << s2 << std::endl;

    Set<char*> s3 = s2;
    std::cout << "s3: " << s3 << std::endl;

    if (s3 == s2) {
        std::cout << "s3 == s2\n";
    } else {
        std::cout << "s3 != s2\n";
    }


    // ===== Set<int> =====
    Set<int> one(1);
    one.push(Const::TWO);
    one.push(Const::THREE);
    one.push(Const::FIVE);

    Set<int> two;
    two.push(Const::TWO);
    two.push(Const::THREE);
    two.push(Const::TEN);

    std::cout << "\none: " << one << std::endl;
    std::cout << "two: " << two << std::endl;

    one -= two;
    std::cout << "one -= two: " << one << std::endl;


    // ===== Set<double> =====
    Set<double> one1(Const::ONE_POINT_FIVE);
    one1.push(Const::TWO_POINT_ZERO);
    one1.push(Const::THREE_POINT_NINE_NINE);

    Set<double> two1;
    two1.push(Const::TWO_POINT_ZERO);
    two1.push(Const::THREE_POINT_NINE_EIGHT);
    two1.push(Const::TEN_D);

    std::cout << "\none1: " << one1 << std::endl;
    std::cout << "two1: " << two1 << std::endl;

    one1 -= two1;
    std::cout << "one1 -= two1: " << one1 << std::endl;


    // ===== Set<string> =====
    Set<std::string> stroka;
    stroka.push("Привет!");
    stroka.push("Hello");
    stroka.push("Привет!"); // дубликат

    std::cout << "\nStroka: " << stroka << std::endl;

    if (!stroka.is_element("Bye")) {
        std::cout << "'Bye' отсутствует в stroka\n";
    }

    // ===== Очистка буферов =====
    delete[] buffer1;
    delete[] buffer2;
    delete[] buffer3;
    delete[] buffer4;
    delete[] buffer5;
    delete[] buffer6;
    delete[] buffer7;
    delete[] buffer8;
    delete[] buffer9;
    delete[] buffer10;

    return 0;
}