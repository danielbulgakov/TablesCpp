#ifndef _TSCANTABLE_
#define _TSCANTABLE_

#include "TArrayTable.h"
constexpr size_t TabMaxSize = 25;

class TScanTable : public TArrayTable{
private:


public:
    TScanTable(size_t size = TabMaxSize) : TArrayTable(size) {}

    virtual PTDataValue FindRecord(TKey key){
        SetRetCode(TabOk);
        size_t i;
        for (i = 0; i < (size_t)DataCount; i++){
            if (pRecord[i]->Key == key) {
                break;
            }
        }

        Efficiency = (int32_t)i + 1;
        if (i < (size_t)DataCount){
            CurPos = (int32_t)i;
            return pRecord[i]->pValue;
        }
        SetRetCode(TabNoRecord);
        return nullptr;
    }

    virtual void InsRecord(TKey key, PTDataValue value){
        SetRetCode(TabMemError);
        size_t i;
        for (i = 0; i < (size_t)DataCount; i++){
            if (pRecord[i]->Key == "nullkey"){
                break;
            }
        }
        CurPos = (int32_t)i;
        if (!isFull()){
            pRecord[i] = new TTabRecord(key, value);
            DataCount++;
        }

    }

    virtual void DelRecord(TKey key){
        PTDataValue temp = FindRecord(key);
        if (temp == nullptr) SetRetCode(TabNoRecord);
        else{
            for(int32_t i = CurPos; i < DataCount - 1; i++ ){
                pRecord[i] = pRecord[i+1];
            }
            pRecord[--DataCount] = nullptr;
            SetRetCode(TabOk);
        }
    }


};

#endif // _TSCANTABLE_

