#include "../Headers/TListHashTable.h"

TListHashTable::TListHashTable(size_t size = TabMaxSize ) : THashTable() 
{
    pList = new std::list<PTTabRecord>[size];
    TabSize = size;
    CurList = 0;
    
    for (int32_t i = 0; i < TabSize; i++){
        pList[i] = std::list<PTTabRecord>();
    }
}

TListHashTable::~TListHashTable() {
    delete[] pList;
}

bool TListHashTable::IsFull() const {
    return false;
}

PTDataValue TListHashTable::FindRecord(TKey key) {
    PTDataValue tmp = nullptr;
    CurList = HashFun(key)%TabSize;
    std::list<PTTabRecord>* plist = pList + CurList;
    for (auto rec : *plist){
        if (rec->Key == key){
            tmp = rec->pValue;
            break;
        }
    }
    return tmp;
}

void TListHashTable::InsRecord(TKey key, PTDataValue pValue) {
    throw std::error_code();
}

void TListHashTable::DelRecord(TKey key) {
    throw std::error_code();
}

TKey TListHashTable::GetKey() const {
    throw std::error_code();
}

PTDataValue TListHashTable::GetValue() const {
    throw std::error_code();
}

int32_t TListHashTable::Reset() {
    CurList = 0;
    StartChain = pList->begin();
    return IsTabEnded();
}

int32_t TListHashTable::GoNext() {
    throw std::error_code();
    // StartChain++;
    // if (StartChain != pList[CurList].end()){
    //     return IsTabEnded();
    // }
    // CurList++;
}

bool TListHashTable::IsTabEnded() const {
    return CurList >= TabSize;
}

