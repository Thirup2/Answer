#define EXPORT

#include "StaticSequenceList.h"
#include <stdlib.h>

// 局部函数声明
static PtrSSList AllocList(void);

// 接口函数定义
SSLIST_API PtrSSList InitList(void)
{
    PtrSSList list = AllocList();
    return list;
}
SSLIST_API int Length(cPtrSSList list)
{
    return list->length;
}
SSLIST_API int LocateElem(PtrSSList list, cPtrElem elem)
{
    CopyElems(&(list->data[0]), elem);
    int i;
    for (i = list->length; !EqualElems(&(list->data[i]), elem); i--);
    return i;
}
SSLIST_API PtrElem GetElem(PtrSSList list, int i)
{
    if (Empty(list) || (i < 1 || i > Length(list))) {
        return NULL;
    }
    return &(list->data[i]);
}
SSLIST_API Status ListInsert(PtrSSList list, int i, cPtrElem elem)
{
    if (list->length == MAXSIZE) {
        return ISFULL;
    }
    if (i < 1 || i > Length(list) + 1) {
        return WRONGPOS;
    }
    int p = list->length;
    while (p >= i) {
        CopyElems(&(list->data[p + 1]), &(list->data[p]));
        p--;
    }
    CopyElems(&(list->data[i]), elem);
    list->length++;
    return SUCCESS;
}
SSLIST_API Status ListDelete(PtrSSList list, int i, PtrElem elem)
{
    if (Empty(list)) {
        return ISEMPTY;
    }
    if (i < 1 || i > Length(list)) {
        return WRONGPOS;
    }
    CopyElems(elem, &(list->data[i]));
    while (i < Length(list)) {
        CopyElems(&(list->data[i]), &(list->data[i + 1]));
        i++;
    }
    list->length--;
    return SUCCESS;
}
SSLIST_API bool Empty(cPtrSSList list)
{
    return Length(list) == 0;
}
SSLIST_API void DestroyList(PtrSSList list)
{
    free(list);
}
SSLIST_API Iterator Begin(PtrSSList list)
{
    return &(list->data[1]);
}
SSLIST_API Iterator End(PtrSSList list)
{
    return &(list->data[list->length + 1]);
}
SSLIST_API Iterator Next(Iterator pre)
{
    return pre + 1;
}
SSLIST_API constIterator cBegin(cPtrSSList list)
{
    return Begin((PtrSSList) list);
}
SSLIST_API constIterator cEnd(cPtrSSList list)
{
    return End((PtrSSList) list);
}
SSLIST_API constIterator cNext(constIterator pre)
{
    return Next((Iterator) pre);
}

// 局部函数定义
static PtrSSList AllocList(void)
{
    PtrSSList list = (PtrSSList) malloc(sizeof(SSList));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->length = 0;
    return list;
}