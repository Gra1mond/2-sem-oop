#pragma once

#include "wine_library.hpp"

bool isEmptyMassive(const int WineLibraryCount);
void loadFromFile(wineLibrary*& testarray, int* wineLibraryCount);
void loadToFile(wineLibrary*& testarray, int* wineLibraryCount);
void addNewobject(wineLibrary*& testarray, int* currentPos, int* wineLibraryCount);
void deleteObject(wineLibrary*& testarray, int* wineLibraryCount);
void searchObject(wineLibrary*& testarray, int* wineLibraryCount);
void redactObject(wineLibrary*& testarray, int* wineLibraryCount);