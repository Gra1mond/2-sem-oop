#include "datelib.h"

void dateDifference(int year[],int month[],int day[],int out[]){
    out[Constant::kIndexFirstDate] = year[Constant::kIndexFirstDate] - year[Constant::kIndexSecondDate];
    out[Constant::kIndexSecondDate] = month[Constant::kIndexFirstDate] - month[Constant::kIndexSecondDate];
    out[Constant::kIndexThirdDate] = day[Constant::kIndexFirstDate] - day[Constant::kIndexSecondDate];
}
void dateInput(int mass[]){
    for (int i = Constant::kStartDateOutput;i<Constant::kAmountDate;i++){
        std::cin>>mass[i];
    }
}