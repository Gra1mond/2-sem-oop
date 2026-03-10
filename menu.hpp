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
int const kLoadFromFile = 3;
int const kLoadToFile = 4;
int const kIndexShift = 1;
int const kDeleteObject = 5;
int const kSortMassive = 6;
int const kSearchObject = 7;
int const kRedactObject = 8;
int const kExit = 9;
bool const kIsRunning = true;
inline const char* FILE_PATH = "wineLibrary.dat";
const int kDeleteArrayLen = 200;
const int kSearchMarkLen = 50;
}  // namespace MenuConstants

enum class deleteChoise: int {
    Mark = 1,
    Year = 2,
    Price = 3,
    Count = 4
};  
void StartMenu();
