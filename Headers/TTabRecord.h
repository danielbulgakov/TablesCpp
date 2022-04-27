#ifndef _TTABRECORD_
#define _TTABRECORD_

#include <string>
#include <iostream>
#include "TDataValue.h"

typedef std::string TKey;
typedef TDataValue* PTDataValue;

class TTabRecord;
typedef TTabRecord* PTTabRecord;

class TTabRecord : TDataValue
{
protected:
    TKey Key;
    PTDataValue pValue;

    virtual void Print(std::ostream& where) const override { where << Key << "   " << pValue;}

public:

    TTabRecord(TKey key, PTDataValue pvalue) : Key(key), pValue(pvalue) {}

    void SetKet(TKey key) {this->Key = key;}
    TKey GetKet(TKey key) {return this->Key;}
    void SetValue(PTDataValue pvalue){this->pValue = pvalue;}
    PTDataValue GetValue (){return this->pValue;}
    PTDataValue GetCopy() override {return new TTabRecord(this->Key, this->pValue);}

    TTabRecord& operator= (const TTabRecord& tr){  // Check if it works
        this->Key = tr.Key;
        this->pValue = tr.pValue; // GetCopy() ? SetValue()?
        return *this;
    }

    virtual bool operator==(const TTabRecord& tr) const{
        return this->Key == tr.Key;
    } 

    virtual bool operator> (const TTabRecord& tr) const{
        return this->Key > tr.Key;
    }

    virtual bool operator< (const TTabRecord& tr) const{
        return this->Key < tr.Key; 
    }

    friend class TArrayTable;
    friend class TScanTable;
    friend class TSortTable;
    friend class TTreeTable;
    friend class TTreeNode;
    friend class TArrayHashTable;
    friend class TListHashTable;



};


#endif //_TTABRECORD_