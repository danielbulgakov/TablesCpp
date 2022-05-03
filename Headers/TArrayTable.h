#ifndef _TARRAYTABLE_
#define _TARRAYTABLE_

#include "TTable.h"
#include "TTabRecord.h"

enum TDataPos{
    FirstPos, CurPos, LastPos
};

class TArrayTable : protected TTable
{
protected:
    PTTabRecord* pRecord;
    int32_t TabSize;
    int32_t CurPos;
public:
    TArrayTable(size_t size = 100){
        TabSize = (int32_t)size;
        *pRecord = new TTabRecord[size];
        for (size_t i=0; i < size; i++){
            pRecord[i] = nullptr;
        }
        CurPos = 0;
    }
    ~TArrayTable(){
        for (size_t i=0; i < DataCount; i++){
            delete pRecord[i];
        }
        delete[] pRecord;
    }

    virtual bool IsFull() const {
        return DataCount >= TabSize;
    }

    int32_t GetTabSize() const{
        return TabSize;
    }

    // virtual TKey GetKey() const{ реализовать самостоятельно
    //     return TKey(CurPos);
    // }

    // virtual PTDataValue GetValuePtr() { реализовать самостоятельно
    //     return GetValuePtr(CurPos);
    // }

    virtual TKey GetKey(TDataPos mode) const{
        int32_t pos = -1;
        if (!isEmpty()){
            switch (mode) {
                case FirstPos: pos = 0; break;
                case LastPos: pos = DataCount - 1; break;
                default: pos = CurPos; break;
            }
        }
        return TKey(std::to_string(pos));
    }

    virtual PTDataValue GetValuePtr(TDataPos mode) const{
        PTDataValue value = nullptr;
        if (!isEmpty()){
            pRecord[mode]->pValue;           
        }
        return value;
    }
    
    bool IsTabEnded() const {
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




};


#endif // _TARRAYTABLE_
