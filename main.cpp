#include <iostream>
#include <string>
#include "containers/Container.h"
#include "containers/Set.h"

namespace Const {
    constexpr int TWO = 2;
    constexpr int THREE = 3;
    constexpr int FIVE = 5;
    constexpr int TEN = 10;

    constexpr double ONE_POINT_FIVE = 1.5;
    constexpr double TWO_POINT_ZERO = 2.0;
    constexpr double THREE_POINT_NINE_NINE = 3.99;
    constexpr double THREE_POINT_NINE_EIGHT = 3.98;
    constexpr double TEN_D = 10.0;
}

int main() {

    // ===== Container =====
    Container<const char*> v("Hello!");
    v.push("Привет!");
    v.push("World");
    v.push("Test");

    std::cout << "Вектор v: " << v << std::endl;

    int index = v.find("World");
    std::cout << "Индекс элемента 'World': " << index << std::endl;

    v.push("Another");
    v.push("Example");

    std::cout << "Вектор v после добавления: " << v << std::endl;

    Container<const char*> v1 = v;
    std::cout << "Копия v1: " << v1 << std::endl;

    v1.pop(2);
    std::cout << "v1 после удаления элемента с индексом 2: " << v1 << std::endl;


    // ===== Set =====
    Set<const char*> s("Yes");
    Set<const char*> s1("Hello!");
    Set<const char*> s2;

    s.push("Привет!");
    s.push("No");
    s.push("World");

    std::cout << "\nМножество s: " << s << std::endl;

    if (s.is_element("No")) {
        std::cout << "'No' есть в множестве s\n";
    }

    s1.push("Cat");
    s1.push("Dog");
    s1.push("Привет!");

    std::cout << "Множество s1: " << s1 << std::endl;

    s2 = s1 - s;
    std::cout << "s2 = s1 - s: " << s2 << std::endl;

    s2 = s1 + s;
    std::cout << "s2 = s1 + s: " << s2 << std::endl;

    s2 = s1 * s;
    std::cout << "s2 = s1 * s: " << s2 << std::endl;

    Set<const char*> s3 = s2;
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

    return 0;
}
