#ifndef _TSCANTABLE_
#define _TSCANTABLE_

#include "TArrayTable.h"
constexpr size_t TabMaxSize = 25;

class TScanTable : public TArrayTable{
private:


public:
    TScanTable(int32_t size = TabMaxSize) : TArrayTable(size) {}

    virtual PTDataValue FindRecord(TKey key){
        SetRetCode(TabOk);
        size_t i;
        for (i = 0; i < DataCount; i++){
            if (pRecord[i]->Key == key) {
                break;
            }
        }

        Efficiency = (int32_t)i + 1;
        if (i < DataCount){
            CurPos = (int32_t)i;
            return pRecord[i]->pValue;
        }
        SetRetCode(TabNoRecord);
        return nullptr;
    }

    virtual void InsRecord(TKey key, PTDataValue value){
        SetRetCode(TabMemError);
        size_t i;
        for (i = 0; i < DataCount; i++){
            if (pRecord[i]->Key == "nullkey"){
                break;
            }
        }
        CurPos = (int32_t)i;
        if (!isTabEnded()){
            pRecord[i] = new TTabRecord(key, value);
            DataCount++;
        }

    }

    virtual void DelRecord(TKey key){
        SetRetCode(TabMemError);
        size_t i;
        for (i = 0; i < DataCount; i++){
            if (pRecord[i]->Key == key){
                break;
            }
        }

        if (i < DataCount){
            CurPos = (int32_t)i;
            delete (pRecord)[i];
            pRecord = new PTTabRecord();
            SetRetCode(TabOk);
        }

    }


};

#endif // _TSCANTABLE_

