#ifndef _THASHTABLE_
#define _THASHTABLE_

#include <iostream>
#include "TDataValue.h"
#include "TArrayTable.h"
#include "TScanTable.h"

class THashTable : TTable{
protected:
    virtual uint32_t HashFun(const TKey key){
        uint64_t HashValue = 0;
        int Len = key.length();
        for (int  i = 0; i< Len; i++){
            HashValue = (HashValue << 3) + key[i];    
        }
        return (uint32_t)HashValue;
    }
public:
    THashTable() : TTable() {};

};


#endif //_THASHTABLE_