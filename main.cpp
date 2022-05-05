#include "Headers/csvconverter.h"
#include "Headers/TScanTable.h"
#include <vector>
#include <Windows.h>


class TWord : public TDataValue{
private :
    std::string Word;
    void Print(std::ostream& where) const { where << Word; } 
public:
    TWord(std::string word = std::string()) : Word(word) {};
    PTDataValue GetCopy() {return new TWord(Word);}
};

int main(){

    TScanTable tab;


    CSVConverter csv("D:\\Study\\Cpp\\TablesCpp\\Tables\\Students.csv");
    auto v = csv.Convert();

    for (auto el : v){
        tab.InsRecord(el.first, new TWord(el.second));
    }

    std::cout << "Found at - " << *(tab.FindRecord("Gosteeva Ekaterina"));
    tab.DelRecord("Gosteeva Ekaterina");
    tab.DelRecord("Demina Daria");
    std::cout << std::endl;
    std::cout << tab;

    return 0;
}