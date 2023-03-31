#define EXPORT

// ----------------------包含头文件---------------------- //
#include "Bag.h"
#include <stdlib.h>

// ----------------------接口---------------------- //

// 接口函数定义

PtrBag DLL_CALL InitBag(void)
{
    PtrBag bag = (PtrBag) malloc(sizeof(Bag));
    if (!bag) {
        exit(EXIT_FAILURE);
    }
    bag->data = InitCoord();
    bag->size = 0;
    return bag;
}

bool DLL_CALL EmptyBag(cPtrBag bag)
{
    if (BagSize(bag) == 0) {
        return true;
    }
    return false;
}

void DLL_CALL ClearBag(PtrBag bag)
{
    free(bag->data);
    bag->data = (PtrCoord) realloc(bag->data, sizeof(Coordinate));
    bag->size = 0;
}

void DLL_CALL DestroyBag(PtrBag bag)
{
    free(bag->data);
    free(bag);
}

size_t DLL_CALL SearchData(cPtrBag bag, cPtrCoord coord)
{
    AssignCoordByCopy(&bag->data[0], coord);
    size_t i = bag->size;
    while (!CompareCoords(&bag->data[i], coord)) {
        --i;
    }
    return i;
}

Status DLL_CALL InsertElem(PtrBag bag, cPtrCoord coord)
{
    if (SearchData(bag, coord)) {
        return ISIN;
    }
    bag->data = (PtrCoord) realloc(bag->data, (bag->size + 2) * sizeof(Coordinate));
    if (!bag->data) {
        return ISFULL;
    }
    bag->size++;
    AssignCoordByCopy(&bag->data[bag->size], coord);
    return SUCCESS;
}

size_t DLL_CALL BagSize(cPtrBag bag)
{
    return bag->size;
}

PtrCoord DLL_CALL Begin(PtrBag bag)
{
    if (EmptyBag(bag)) {
        return NULL;
    }
    return &bag->data[1];
}

PtrCoord DLL_CALL End(PtrBag bag)
{
    return &bag->data[bag->size + 1];
}

PtrCoord DLL_CALL Next(PtrCoord now)
{
    return now + 1;
}