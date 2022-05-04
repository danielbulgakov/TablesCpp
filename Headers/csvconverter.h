#ifndef _CSVCONVERTER_
#define _CSVCONVERTER_

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "TScanTable.h"

class CSVConverter{
private:
    std::vector<std::pair<std::string, std::string>> ArrayTable;
    std::ifstream File;
    std::string Path;
public:
    CSVConverter(std::string path) : Path(path) {} 
    std::vector<std::pair<std::string, std::string>>& Convert(){
        bool isFirst = true;
        char delim = ',';
        std::string buff;
        File.open(Path);
        if (File.is_open())
        {
            while (getline(File,buff) )
            {
                size_t pos = 0;
                pos = buff.find(delim); 
                std::pair<std::string, std::string> pair;
                if (isFirst) {
                    pair = std::make_pair(buff.substr(3, pos - 3),
                    buff.substr(pos + 1));
                }
                else{
                    pair = std::make_pair(buff.substr(0, pos),
                    buff.substr(pos + 1));
                }
                ArrayTable.push_back(pair);
                isFirst = false;
            }
            File.close();
        }
        return ArrayTable;
    };

};



#endif //_CSVCONVERTER_