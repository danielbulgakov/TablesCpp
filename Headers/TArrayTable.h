#ifndef _TARRAYTABLE_
#define _TARRAYTABLE_

#include "TTable.h"
#include "TTabRecord.h"

enum TDataPos{
    FirstPos, CurPos, LastPos
};

class TArrayTable : TTable
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
};


#endif // _TARRAYTABLE_
