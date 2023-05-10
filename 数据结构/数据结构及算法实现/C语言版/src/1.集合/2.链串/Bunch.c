#define EXPORT

#include "Bunch.h"
#include <stdlib.h>

// 局部函数声明
static bool Existed(cPtrBunch bunch, cPtrElem elem);
static int Find(cPtrBunch bunch, cPtrElem elem);

// 接口函数定义
PtrBunch DLL_CALL CreateBunch(void)
{
    PtrBunch bunch = (PtrBunch) malloc(sizeof(Bunch));
    if (!bunch) {
        exit(EXIT_FAILURE);
    }
    bunch->size = 0;
    bunch->head = NULL;
    return bunch;
}
Status DLL_CALL Add(PtrBunch bunch, cPtrElem elem)
{
    if (Existed(bunch, elem)) {
        return EXISTED;
    }
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    CopyElems(&node->data, elem);
    node->next = bunch->head;
    bunch->head = node;
    bunch->size++;
    return SUCCESS;
}
bool DLL_CALL BunchEmpty(cPtrBunch bunch)
{
    return Size(bunch) == 0;
}
int DLL_CALL Size(cPtrBunch bunch)
{
    return bunch->size;
}
void DLL_CALL DestroyBunch(PtrBunch bunch)
{
    PtrNode node = bunch->head;
    PtrNode del;
    while (node) {
        del = node;
        node = node->next;
        free(del);
    }
    free(bunch);
}
PtrElem DLL_CALL StarIter(Iterator iter)
{
    return &iter->data;
}
cPtrElem  DLL_CALL StarConstIter(constIterator iter)
{
    return StarIter((Iterator) iter);
}
Iterator DLL_CALL Begin(PtrBunch bunch)
{
    return bunch->head;
}
Iterator DLL_CALL End(PtrBunch bunch)
{
    return NULL;
}
Iterator DLL_CALL Next(Iterator pre)
{
    return pre->next;
}
constIterator DLL_CALL cBegin(cPtrBunch bunch)
{
    return Begin((PtrBunch) bunch);
}
constIterator DLL_CALL cEnd(cPtrBunch bunch)
{
    return End((PtrBunch) bunch);
}
constIterator DLL_CALL cNext(constIterator pre)
{
    return Next((Iterator) pre);
}

// 局部函数定义
static bool Existed(cPtrBunch bunch, cPtrElem elem)
{
    return Find(bunch, elem);
}
static int Find(cPtrBunch bunch, cPtrElem elem)
{
    constIterator beg = cBegin(bunch);
    constIterator end = cEnd(bunch);
    int i = bunch->size;
    while (beg != end && !EqualElems(StarConstIter(beg), elem)) {
        i--;
        beg = cNext(beg);
    }
    return i;
}