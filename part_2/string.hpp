#pragma once
#include<iostream>
#include <cstring> 
#include <cstdlib> 
#include <numeric>
#include <cstdlib> 
void readLine(const char* ch, int& numerator, int& denominator);
void parseString(const char* buffer, int& numerator, int& denominator);
void reduceFraction(int& numerator, int& denominator);
void doubleToFraction(double input, int& numerator, int& denominator);
namespace StringConstants {
    inline constexpr int kBufferSize = 256;
    inline constexpr int kNumberSize = 10;
    inline constexpr int kScaleSize = 1000000;
}
