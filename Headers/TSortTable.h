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

    /**
     * @brief Запуск сортировки по типу переменное SortMethod.
     */
    void SortData();


    /**
     * @brief Сортировка методом вставок.
     * 
     * @param pMem указатель на pRecord.
     * @param DataCount параметр DataCount.
     */
    void InsertSort(PTTabRecord* pMem, size_t DataCount);


    /**
     * @brief Сортировка методом слияния.
     * 
     * @param pMem указатель на pRecord.
     * @param DataCount параметр DataCount.
     */
    void MergeSort(PTTabRecord* pMem, size_t DataCount);


    /**
     * @brief Деление массива пополам.
     * 
     * @param pData 
     * @param pBuf 
     * @param size размер pBuf.
     */
    void MergeSorter(PTTabRecord* &pData, PTTabRecord* &pBuf, size_t size);
    
    
    /**
     * @brief Слияние упорядоченных половинок массива.
     * 
     * @param pData 
     * @param pBuf 
     * @param n1 
     * @param n2 
     */
    void MergeData(PTTabRecord* &pData, PTTabRecord* &pBuf, int32_t n1, int32_t n2);
    
    
    /**
     * @brief Быстрая сортировка.
     * 
     * @param pMem указатель на pRecord.
     * @param DataCount парметр DataCount.
     * TODO  Реализовать
     */
    void QuickSort(PTTabRecord* pMem, size_t DataCount);  // Можно изменять при необходимости.
    
    
    // void QuickSplit(PTTabRecord* pData, size_t size, int32_t& pivot) { return;};  // Можно изменять при необходимости.
public:

    /**
     * @brief Конструктор класса. 
     * 
     * @param Size размер таблицы.
     */
    TSortTable(size_t Size = 20) : TScanTable(Size) {}

    /**
     * @brief Конструктор копирования класса.
     * TODO  Реализовать
     * @param tab ссылка на объект класса TScanTable.
     */
    TSortTable(const TScanTable& tab);

    /**
     * @brief Оператор присваивания.
     * 
     * @param tab ссылка на объект класса TScanTable.
     */
    TSortTable& operator= (const TScanTable& tab);


    /**
     * @brief Геттер.
     */
    TSortMethod GetMethod() { return SortMethod;}


    /**
     * @brief Сеттер.
     * @param method параметр типа TSortMethod.
     */
    void SetMethod(TSortMethod method) {SortMethod = method;}


    /**
     * @brief Найти запись в таблице. 
     * @param key ключ.
     */
    virtual PTDataValue FindRecord(TKey key);


    /**
     * @brief Вставить запись в таблицу. 
     * @param key ключ.
     * @param pValue значение.
     * TODO  Реализовать
     */
    virtual void InsRecord(TKey key, PTDataValue pValue);


    /**
     * @brief Удалить запись из таблицы. 
     * @param key ключ.
     * TODO  Реализовать
     */
    virtual void DelRecord(TKey key);
    
    
    


};

#endif // _TSORTTABLE_