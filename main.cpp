#include "Headers/csvconverter.h"
#include "Headers/TScanTable.h"
#include <vector>
#include <Windows.h>


class TWord : public TDataValue{
private :
    std::vector<std::string> v;
    void Print(std::ostream& where) const { where << "{ "; for (auto el : v) where << el + " ,"; where << '}'; } 
public:
    TWord(std::initializer_list<std::string> l) {
        for (auto el : l) {v.push_back(el);}
    };
    PTDataValue GetCopy() {return new TWord({std::string()});}
};

int main(){

    TScanTable tab;


    CSVConverter csv("..\\..\\Tables\\Students.csv");
    auto v = csv.Convert();

    for (auto el : v){
        tab.InsRecord(el.first, new TWord({el.second, el.second, el.second}));
    }

    std::cout << "Found at - " << *(tab.FindRecord("Gosteeva Ekaterina"));
    tab.DelRecord("Gosteeva Ekaterina");
    tab.DelRecord("Demina Daria");
    std::cout << std::endl;
    std::cout << tab;

    return 0;
}