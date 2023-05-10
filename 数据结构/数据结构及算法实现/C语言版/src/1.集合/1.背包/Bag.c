#define EXPORT

#include "Bag.h"
#include <stdlib.h>

// 局部函数声明
static bool Existed(cPtrBag bag, cPtrElem elem);
static int Find(cPtrBag bag, cPtrElem elem);
static bool BagFull(cPtrBag bag);

// 接口函数定义
PtrBag DLL_CALL CreateBag(void)
{
    PtrBag bag = (PtrBag) malloc(sizeof(Bag));
    if (!bag) {
        exit(EXIT_FAILURE);
    }
    bag->capacity = 1;
    bag->length = 0;
    bag->data = (PtrElem) malloc((bag->capacity + 1) * sizeof(ElemType));
    if (!bag->data) {
        exit(EXIT_FAILURE);
    }
    return bag;
}
Status DLL_CALL Add(PtrBag bag, cPtrElem elem)
{
    if (Existed(bag, elem)) {
        return EXISTED;
    }
    if (BagFull(bag)) {
        bag->capacity *= 2;
        bag->data = (PtrElem) realloc(bag->data, (bag->capacity + 1) * sizeof(ElemType));
        if (!bag->data) {
            exit(EXIT_FAILURE);
        }
    }
    CopyElems(&(bag->data[++bag->length]), elem);
    return SUCCESS;
}
bool DLL_CALL BagEmpty(cPtrBag bag)
{
    return Size(bag) == 0;
}
int DLL_CALL Size(cPtrBag bag)
{
    return bag->length;
}
void DLL_CALL DestroyBag(PtrBag bag)
{
    free(bag->data);
    free(bag);
}
Iterator DLL_CALL Begin(PtrBag bag)
{
    return &(bag->data[1]);
}
Iterator DLL_CALL End(PtrBag bag)
{
    return &(bag->data[bag->length + 1]);
}
Iterator DLL_CALL Next(Iterator pre)
{
    return pre + 1;
}
constIterator DLL_CALL cBegin(cPtrBag bag)
{
    return Begin((PtrBag) bag);
}
constIterator DLL_CALL cEnd(cPtrBag bag)
{
    return End((PtrBag) bag);
}
constIterator DLL_CALL cNext(constIterator pre)
{
    return Next((Iterator) pre);
}

// 局部函数定义
static bool Existed(cPtrBag bag, cPtrElem elem)
{
    return Find(bag, elem);
}
static int Find(cPtrBag bag, cPtrElem elem)
{
    CopyElems(&(bag->data[0]), elem);
    int i = bag->length;
    while (!EqualElems(&(bag->data[i]), elem)) {
        i--;
    }
    return i;
}
static bool BagFull(cPtrBag bag)
{
    return bag->length == bag->capacity;
}