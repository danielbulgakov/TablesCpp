#ifndef _TLISTHASHTABLE_
#define _TLISTHASHTABLE_

#include "THashTable.h"
#include <iostream>
#include <list>

class TListHashTable : public THashTable {
protected:
    int32_t TabSize;
    int32_t CurList;
    std::list<PTTabRecord>* pList;
    std::list<PTTabRecord>::iterator StartChain;
public:
    TListHashTable(size_t size);
    virtual ~TListHashTable();
    virtual bool IsFull() const;
    virtual PTDataValue FindRecord(TKey key);
    virtual void InsRecord(TKey key, PTDataValue pValue);
    virtual void DelRecord(TKey key);
    virtual TKey GetKey() const;
    virtual PTDataValue GetValue() const;
    virtual int32_t Reset();
    virtual int32_t GoNext();
    virtual bool IsTabEnded() const;


};



#endif //_TLISTHASHTABLE_