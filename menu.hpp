#pragma once
#include "wine_library.hpp"

namespace MenuConstants {
int const kTestDate = 1990;
int const kTestPrice = 1000;
int const kTestCount = 10;
char const kTestMarkText[] = "abraudurso";
int const kArraySize = 5;
int const kStartCountInitialize = 0;
int const kAppendObject = 1;
int const kShowAllMassive = 2;
int const kShowSomeElements = 3;
int const kShowNElement = 4;
int const kIndexShift = 1;
int const kExit = 5;
bool const kIsRunning = true;
}  // namespace MenuConstants

void StartMenu();
