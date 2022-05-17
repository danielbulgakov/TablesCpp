#ifndef _TARRAYTABLE_
#define _TARRAYTABLE_

#include "TTable.h"
#include "TTabRecord.h"

enum TDataPos{
    FirstPos, CurPos, LastPos
};

class TArrayTable : public TTable
{
protected:
    int32_t TabSize;
    int32_t CurPos;
    PTTabRecord* pRecord;
public:
    TArrayTable(size_t size = 100){
        TabSize = (int32_t)size;
        pRecord = new PTTabRecord[TabSize];
        for (size_t i = 0; i < size; ){
            pRecord[i] = NULL;
            i++;
        }
        CurPos = 0;
    }
    ~TArrayTable(){
        for (size_t i=0; i < (size_t)DataCount; i++){
            delete pRecord[i];
        }
        delete[] pRecord;
    }

    virtual bool isFull() const {
        return DataCount >= TabSize;
    }

    int32_t GetTabSize() const{
        return TabSize;
    }

    virtual TKey GetKey() const { 
        return GetKey(TDataPos::CurPos);
    }

    virtual PTDataValue GetValue() const { 
        return GetValuePtr(TDataPos::CurPos);
    }

    virtual TKey GetKey(TDataPos mode) const{
        int32_t pos = -1;
        if (!isEmpty()){
            switch (mode) {
                case FirstPos: pos = 0; break;
                case LastPos: pos = DataCount - 1; break;
                default: pos = CurPos; break;
            }
        }
        return pRecord[pos]->GetKey();
    }

    virtual PTDataValue GetValuePtr(TDataPos mode) const{
        PTDataValue value = nullptr;
        int32_t pos = -1;
        if (!isEmpty()){
            switch (mode) {
                case FirstPos: pos = 0; break;
                case LastPos: pos = DataCount - 1; break;
                default: pos = CurPos; break;
            }           
        }
        value = pRecord[pos]->pValue;
        return value;
    }
    
    bool isTabEnded() override {
        return CurPos >= TabSize;
    }

    int32_t Reset() override{
        CurPos = 0;
        return isTabEnded();
    }

    int32_t GoNext() override{
        if (!isTabEnded()){
            CurPos++;
        }
        return isTabEnded();
    }

    int32_t GetCurrentPos() const {
        return CurPos;
    }

    virtual bool SetCurrentPos(int32_t pos) {
        CurPos = (pos > -1) && (pos < DataCount) ? pos : 0;
        return isTabEnded();
    }



    friend TSortTable;
};


#endif // _TARRAYTABLE_
