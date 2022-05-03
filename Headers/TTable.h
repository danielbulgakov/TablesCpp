#ifndef _TTABLE_
#define _TTABLE_
#include "TDataCom.h"
#include "TDataValue.h"
#include "TTabRecord.h"
#include <iostream>

constexpr int8_t TabOk = 0;
constexpr int8_t TabNoRecord = -1;

class TTable : public TDataCom{
protected:
    size_t DataCount;
    int32_t Efficiency;

public:
    TTable() : DataCount(0) , Efficiency(0) {}
    virtual ~TTable();

    size_t GetDataCount() const {return DataCount;}
    int32_t GetEfficiency() const {return Efficiency;}
    bool isEmpty() const {return DataCount <= 0;}

    virtual bool isFull() const = 0;
    virtual PTDataValue FindRecord(TKey key) = 0;
    virtual void InsRecord (TKey key, PTDataValue pvalue) = 0;
    virtual void DelRecord (TKey key) = 0;

    virtual int32_t Reset() = 0;
    virtual int32_t GoNext() = 0;
    virtual bool isTabEnded() = 0;

    virtual TKey GetKey() const = 0;
    virtual PTDataValue GetValue() const = 0;

    friend std::ostream& operator<< (std::ostream& out, TTable& t){
        for (t.Reset(); !t.isTabEnded(); t.GoNext()){
            out << "Key " << t.GetKey() << " Val " << t.GetValue();
        }
        return out;
    }
};

#endif // _TTABLE_