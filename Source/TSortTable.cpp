#include "../Headers/TSortTable.h"

void TSortTable::SortData(){
    Efficiency = 0;
    switch (SortMethod){
        case Insert :{ InsertSort(pRecord,DataCount); break;}
        case Merge  :{ MergeSort(pRecord,DataCount); break;}
        case Quick  :{ QuickSort(pRecord,DataCount); break;}
        default : break;
    }
}

void TSortTable::InsertSort(PTTabRecord* pMem, size_t DataCount){
    PTTabRecord pR;
    for (int32_t i = 1, j; i < DataCount; i++){
        pR = pRecord[i];
        for (j = i - 1; j > -1; j--){
            if (pRecord[j]->Key > pR->Key){
                pRecord[j+1] = pRecord[j];
                Efficiency++;
            }
            else {
                break;
            }
        }
        pRecord[j+1] = pR;
    }   
}

void TSortTable::QuickSort(PTTabRecord* pMem, size_t DataCount) {
    throw std::exception("Not implemented yet");
}

void TSortTable::MergeSort(PTTabRecord* pMem, size_t DataCount)
{
    PTTabRecord *pData = pMem;
    PTTabRecord *pBuf = new PTTabRecord[DataCount];
    PTTabRecord *pTemp = pBuf;
    MergeSorter(pMem, pBuf, DataCount);
    delete pTemp;
}

void TSortTable::MergeSorter(PTTabRecord* &pData, PTTabRecord* &pBuf, size_t size){
    int32_t n1 = ((int32_t)size + 1) / 2, n2 = (int32_t)size - n1; // Индексы начала и конца массива
    if (size > 2) {
        PTTabRecord* pData2 = pData + n1;
        PTTabRecord* pBuf2 = pBuf + n1;
        MergeSorter(pData, pBuf, n1);
        MergeSorter(pData2, pBuf2, n2);
    } 
    MergeData(pData, pBuf, n1, n2);      
};


void TSortTable::MergeData(PTTabRecord* &pData, PTTabRecord* &pBuf, int32_t n1, int32_t n2)
{
    int32_t i = 0, i1 = 0, i2 = 0;
    PTTabRecord* pDat1 = pData, *pDat2 = pData + n1;
    while((i1 < n1) && (i2 < n2)){
        if (pDat1[i1]->Key < pDat2[i2]->Key)
            pBuf[i++] = pDat1[i1++];
        else 
            pBuf[i++] = pDat2[i2++];
    }
    while(i1 < n1) pBuf[i++] = pDat1[i1++];
    while(i2 < n2) pBuf[i++] = pDat2[i2++];
    pData = pBuf;
    pBuf = pDat1;
    Efficiency += n1 + n2;
}

TSortTable::TSortTable(const TScanTable& tab)  
{
    *this = tab;
    // SortData();
    // ToDo
    // *this = tab; 
    // ToDo конструктор копирования для TScanTable
    // SortData();

}

TSortTable& TSortTable::operator= (const TScanTable& tab) {
    if (pRecord != nullptr){
        for (size_t i = 0; i < (size_t)DataCount; i++){
            delete pRecord[i];
        }
        delete[] pRecord;
        pRecord = nullptr;
    }
    TabSize = tab.GetTabSize();
    DataCount = (int32_t)tab.GetDataCount();
    pRecord = new PTTabRecord[TabSize];
    for (size_t i = 0; i < (size_t)DataCount; i++){
        pRecord[i] = (PTTabRecord)tab.pRecord[i]->GetCopy();
    }
    SortData();
    CurPos = FirstPos;
    return *this;
};

PTDataValue TSortTable::FindRecord(TKey key){
    SetRetCode(TabNoRecord);
    int32_t i = 0, i1 = 0, i2 = DataCount - 1;
    Efficiency = 0;
    while (i1 <= i2){
        Efficiency ++;
        i = (i1 + i2) / 2;
        if (pRecord[i]->Key == key){
            i1 = i + 1;
            i2 = i;
            break;
        }
        else if (pRecord[i]->Key > key)
            i2 = i - 1;
        else i1 = i + 1;
    }

    if (i2 < 0 || pRecord[i2]->Key < key)
        i2++;
    CurPos = i2;

    if (pRecord[i2]->Key == key && i2 < DataCount){
        SetRetCode(TabOk);
        return pRecord[i2]->pValue ;
    }
    else {
        return nullptr;
    }                                                                                          
};

void TSortTable::InsRecord(TKey key, PTDataValue pValue) 
{
    if (isFull()) SetRetCode(TabFull);
    else {
        PTDataValue temp = FindRecord(key);
        if (temp != nullptr) SetRetCode(TabRecDbl);
        else{
            for(int32_t i = DataCount; i > CurPos; i--){
                pRecord[i] = pRecord[i-1];
            }
            pRecord[CurPos] = new TTabRecord(key, pValue);
            DataCount++;
            SetRetCode(TabOk);
        }
    }

}

void TSortTable::DelRecord(TKey key) 
{
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