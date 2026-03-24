#pragma once
#include<iostream>
void readLine(const char* ch, int& numerator, int& denominator);
void parseString(const char* buffer, int& numerator, int& denominator);
void reduceFraction(int& numerator, int& denominator);
void doubleToFraction(double input, int& numerator, int& denominator);