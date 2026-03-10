#include"wine_library.hpp"
#include"sortLib.hpp"

void sortWineLibrary(wineLibrary* &testarray, int *wineLibraryCount){
    std::cout<<"1. Марка\n";
    std::cout<<"2. Год выпуска\n";
    std::cout<<"3. Количество\n";
    std::cout<<"4. Цена\n";
    std::cout<<"Выберите критерий для сортировки:";
    int choice{0};
    std::cin>>choice;
    bool shouldSwap{0};
    std::cout<<"Выберите как сортировать: 1 - по возрастанию/2 - по убыванию\n";
    int choiseParametr{0};
    std::cin>>choiseParametr;
    for(int i = 0;i<*wineLibraryCount;++i){
        for(int j = 0;j<*wineLibraryCount - SortConstant::kBufferAccess;++j){

        switch(static_cast<SortSelect>(choice)){
            
            case SortSelect::Mark:{
                shouldSwap = strcmp(testarray[j].getMark(),testarray[j+SortConstant::kBufferAccess].getMark()) > 0;
                break;
            }

            case SortSelect::Date:{
                shouldSwap = testarray[j].getDate()>testarray[j+SortConstant::kBufferAccess].getDate();
                break;
            }

            case SortSelect::Count:{
                shouldSwap = testarray[j].getCount()>testarray[j+SortConstant::kBufferAccess].getCount();
                break;
            }

            case SortSelect::Price:{
                shouldSwap = testarray[j].getPrice()>testarray[j+SortConstant::kBufferAccess].getPrice();
                break;
            }
            default:{
                std::cout<<"Ошибка выбора критерия сортировки!!!\n";
                return;
            }
        }
            if(shouldSwap && choiseParametr==1){
                Swap(testarray[j],testarray[j+SortConstant::kBufferAccess]);
            } else if(!shouldSwap && choiseParametr==2){
                Swap(testarray[j],testarray[j+SortConstant::kBufferAccess]);
            }
        
        }
    }
    std::cout<<"Сортировка завершена\n";
}