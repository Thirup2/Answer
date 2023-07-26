#define EXPORT

#include "Bag.h"
#include <stdlib.h>

// 局部函数声明
static bool Existed(cPtrBag bag, cPtrElem elem);
static int Find(cPtrBag bag, cPtrElem elem);
static bool BagFull(cPtrBag bag);

// 接口函数定义
BAG_API PtrBag CreateBag(void)
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
BAG_API Status Add(PtrBag bag, cPtrElem elem)
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
BAG_API bool BagEmpty(cPtrBag bag)
{
    return Size(bag) == 0;
}
BAG_API int Size(cPtrBag bag)
{
    return bag->length;
}
BAG_API void DestroyBag(PtrBag bag)
{
    free(bag->data);
    free(bag);
}
BAG_API Iterator Begin(PtrBag bag)
{
    return &(bag->data[1]);
}
BAG_API Iterator End(PtrBag bag)
{
    return &(bag->data[bag->length + 1]);
}
BAG_API Iterator Next(Iterator pre)
{
    return pre + 1;
}
BAG_API constIterator cBegin(cPtrBag bag)
{
    return Begin((PtrBag) bag);
}
BAG_API constIterator cEnd(cPtrBag bag)
{
    return End((PtrBag) bag);
}
BAG_API constIterator cNext(constIterator pre)
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