#define EXPORT

#include "Bunch.h"
#include <stdlib.h>

// 局部函数声明
static bool Existed(cPtrBunch bunch, cPtrElem elem);
static int Find(cPtrBunch bunch, cPtrElem elem);

// 接口函数定义
BUNCH_API PtrBunch CreateBunch(void)
{
    PtrBunch bunch = (PtrBunch) malloc(sizeof(Bunch));
    if (!bunch) {
        exit(EXIT_FAILURE);
    }
    bunch->size = 0;
    bunch->head = NULL;
    return bunch;
}
BUNCH_API Status Add(PtrBunch bunch, cPtrElem elem)
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
BUNCH_API bool BunchEmpty(cPtrBunch bunch)
{
    return Size(bunch) == 0;
}
BUNCH_API int Size(cPtrBunch bunch)
{
    return bunch->size;
}
BUNCH_API void DestroyBunch(PtrBunch bunch)
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
BUNCH_API PtrElem StarIter(Iterator iter)
{
    return &iter->data;
}
BUNCH_API cPtrElem StarConstIter(constIterator iter)
{
    return StarIter((Iterator) iter);
}
BUNCH_API Iterator Begin(PtrBunch bunch)
{
    return bunch->head;
}
BUNCH_API Iterator End(PtrBunch bunch)
{
    return NULL;
}
BUNCH_API Iterator Next(Iterator pre)
{
    return pre->next;
}
BUNCH_API constIterator cBegin(cPtrBunch bunch)
{
    return Begin((PtrBunch) bunch);
}
BUNCH_API constIterator cEnd(cPtrBunch bunch)
{
    return End((PtrBunch) bunch);
}
BUNCH_API constIterator cNext(constIterator pre)
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