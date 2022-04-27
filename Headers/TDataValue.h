#pragma once
#include <iostream>

class TDataValue{
public:
    virtual void Print(std::ostream& where) const = 0;
    virtual TDataValue* GetCopy() = 0;
    ~TDataValue(){};

    friend std::ostream& operator<<(std::ostream& out, const TDataValue& data ){
        data.Print(out);
        return out;
    }
    
};

typedef TDataValue* PTDataValue;