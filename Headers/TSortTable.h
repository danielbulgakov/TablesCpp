#ifndef _TSORTTABLE_
#define _TSORTTABLE_

#include "TScanTable.h"

enum TSortMethod{
    Insert, Merge, Quick
};

class TSortTable : public TScanTable
{
private:
    TSortMethod SortMethod;
protected:
    void SortData(){
        Efficiency = 0;
        switch (SortMethod){
            case Insert :{InsertSort(pRecord,DataCount); break;}
            case Merge  :{ MergeSort(pRecord,DataCount); break;}
            case Quick  :{ QuickSort(pRecord,DataCount); break;}
        }
    };
    /**
     * @brief Сортировка методом вставок
     * 
     * @param pMem указатель на pRecord
     * @param DataCount параметр DataCount
     */
    void InsertSort(PTTabRecord* pMem, size_t DataCount){
        PTTabRecord pR;
        for (size_t i = 1, j; i < DataCount; i++){
            pR = pRecord[i];
            for (j = i - 1; j > -1; j++){
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
    };
    /**
     * @brief Сортировка методом слияния
     * 
     * @param pMem указатель на pRecord
     * @param DataCount параметр DataCount
     */
    void MergeSort(PTTabRecord* pMem, size_t DataCount){
        PTTabRecord *pData = pMem;
        PTTabRecord *pBuf = new PTTabRecord[DataCount];
        PTTabRecord *pTemp = pBuf;
        MergeSorter(pMem, pBuf, DataCount);
        MergeSort

    }
    void MergeSorter(PTTabRecord* &pData, PTTabRecord* &pBuf, size_t size);
    void MergeData(PTTabRecord* &pData, PTTabRecord* &pBuf, int32_t n1, int32_t n2);
    void QuickSort(PTTabRecord* pMem, size_t DataCount);  // Можно изменять при необходимости.
    void QuickSplit(PTTabRecord* pData, size_t size, int32_t& pivot);  // Можно изменять при необходимости.
public:
    TSortTable(size_t Size = 20) : TScanTable(Size) {}
    TSortTable(const TScanTable& tab){
        // ToDo
        // *this = tab; 
        // ToDo конструктор копирования для TScanTable
        // SortData();
    }
    TSortTable& operator= (const TScanTable& tab) {
        if (pRecord != nullptr){
            for (size_t i = 0; i < DataCount; i++){
                delete pRecord[i];
            }
            delete[] pRecord;
            pRecord = nullptr;
        }
        TabSize = tab.GetTabSize();
        DataCount = tab.GetDataCount();
        pRecord = new PTTabRecord[TabSize];
        for (size_t i = 0; i < DataCount; i++){
            pRecord[i] = (PTTabRecord)tab.pRecord[i]->GetCopy();
        }
        SortData();
        CurPos = FirstPos;
        return *this;
    };
    TSortMethod GetMethod() { return SortMethod;}
    void SetMethod(TSortMethod method) {SortMethod = method;}
    virtual PTDataValue FindRecord(TKey key){
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
            if (pRecord[i]->Key > key)
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
    virtual void InsRecord(TKey key, PTDataValue pValue);
    virtual void DelRecord(TKey key);
    
    


};

#endif // _TSORTTABLE_