#include <iostream>
#include <cmath>
#include "datelib.h"

int main() {
    int year[Constant::kAmountDate];  
    int month[Constant::kAmountDate];  
    int day[Constant::kAmountDate];    
    int out[Constant::kLenDate];       
    
    std::cout << "Введите год для двух дат: ";
    dateInput(year);
    
    std::cout << "Введите месяц для двух дат: ";
    dateInput(month);
    
    std::cout << "Введите день для двух дат: ";
    dateInput(day);
    
    dateDifference(year, month, day, out);
    
    std::cout << "Разница между датами:" << std::endl;
    std::cout << "Лет: " << abs(out[Constant::kIndexFirstDate]) << std::endl;
    std::cout << "Месяцев: " << abs(out[Constant::kIndexSecondDate]) << std::endl;
    std::cout << "Дней: " << abs(out[Constant::kIndexThirdDate]) << std::endl;
    
    return 0;
}