#include "Headers/csvconverter.h"
#include "Headers/TScanTable.h"
#include "Headers/TSortTable.h"
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
    TSortTable ts;
    // ts.SetMethod(Merge);
    // ts = tab;
    
    
    // tab.DelRecord("Gosteeva Ekaterina");
    // tab.DelRecord("Demina Daria");


    std::cout << std::endl;
    std::cout << "Standart Table \n" << tab << std::endl;


    ts.SetMethod(Insert);
    ts = tab;
    ts.DelRecord("Gosteeva Ekaterina");
    std::cout << "Insertion Sort Table \n" << ts << std::endl;


    ts.SetMethod(Merge);
    ts = tab;
    ts.DelRecord("Demina Daria");
    std::cout << "Merge Sort Table \n" << ts << std::endl;


    ts.SetMethod(Quick);
    ts = tab;
    ts.DelRecord("Bulgakov Daniil");
    std::cout << "Quick Sort Table \n" << ts << std::endl;


    std::cout << *ts.FindRecord("Demina Daria");


    


   

    

    return 0;
}