#ifndef _TSCANTABLE_
#define _TSCANTABLE_

#include "TArrayTable.h"
constexpr size_t TabMaxSize = 25;

class TScanTable : public TArrayTable{
private:


public:
    TScanTable(int32_t size = TabMaxSize) : TArrayTable(size) {}

    virtual PTDataValue FindRecord(TKey key){
        SetRetCode(DataOk);
        size_t i;
        for (i = 0; i < DataCount; i++){
            if (pRecord[i]->Key == key){
                break;
            }
        }

        Efficiency = i + 1;
        if (i < DataCount){
            CurPos = i;
            return pRecord[i]->pValue;
        }
        SetRetCode(TabNoRecord);
        return nullptr;
    }

    virtual void InsRecord(TKey key, PTDataValue value){

    }

    virtual void DelRecord(TKey key){

    }
};

#endif // _TSCANTABLE_

