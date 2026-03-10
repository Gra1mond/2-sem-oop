enum class SortSelect: int {
    Mark = 1,
    Date = 2,
    Count = 3,
    Price = 4
};
namespace SortConstant{
    int const kBufferAccess = 1;
}
void sortWineLibrary(wineLibrary* &testarray, int *wineLibraryCount);