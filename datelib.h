#include <iostream>
#ifndef DATELIB_H
#define DATELIB_H
namespace Constant {
const int kLenDate = 3;
const int kIndexFirstDate = 0;
const int kIndexSecondDate = 1;
const int kStartDateOutput = 0;
const int kIndexThirdDate = 2;
const int kAmountDate = 2;
}  // namespace Constant
void dateDifference(int year[], int month[], int day[], int out[]);
void dateInput(int mass[]);
#endif
