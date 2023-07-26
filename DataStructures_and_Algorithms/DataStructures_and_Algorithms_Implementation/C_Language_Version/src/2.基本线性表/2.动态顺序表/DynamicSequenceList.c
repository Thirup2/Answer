#define EXPORT

#include "DynamicSequenceList.h"
#include <stdlib.h>

// 局部函数声明
#define INITSIZE 10
static PtrDSList AllocList(void);
static bool Full(cPtrDSList list);
static void Expend(PtrDSList list);
static bool ShrinkTime(cPtrDSList list);
static void Shrink(PtrDSList list);

// 接口函数定义
DSLIST_API PtrDSList InitList(void)
{
    PtrDSList list = AllocList();
    return list;
}
DSLIST_API int Length(cPtrDSList list)
{
    return list->length;
}
DSLIST_API int LocateElem(PtrDSList list, cPtrElem elem)
{
    CopyElems(&(list->data[0]), elem);
    int i;
    for (i = list->length; !EqualElems(&(list->data[i]), elem); i--);
    return i;
}
DSLIST_API PtrElem GetElem(PtrDSList list, int i)
{
    if (Empty(list) || (i < 1 || i > Length(list))) {
        return NULL;
    }
    return &(list->data[i]);
}
DSLIST_API Status ListInsert(PtrDSList list, int i, cPtrElem elem)
{
    if (i < 1 || i > Length(list) + 1) {
        return WRONGPOS;
    }
    if (Full(list)) {
        Expend(list);
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
DSLIST_API Status ListDelete(PtrDSList list, int i, PtrElem elem)
{
    if (Empty(list)) {
        return ISEMPTY;
    }
    if (i < 1 || i > Length(list)) {
        return WRONGPOS;
    }
    int p = i;
    CopyElems(elem, &(list->data[i]));
    while (p < Length(list)) {
        CopyElems(&(list->data[p]), &(list->data[p + 1]));
    }
    list->length--;
    if (ShrinkTime(list)) {
        Shrink(list);
    }
    return SUCCESS;
}
DSLIST_API bool Empty(cPtrDSList list)
{
    return Length(list) == 0;
}
DSLIST_API void DestroyList(PtrDSList list)
{
    free(list->data);
    free(list);
}
DSLIST_API Iterator Begin(PtrDSList list)
{
    return &(list->data[1]);
}
DSLIST_API Iterator End(PtrDSList list)
{
    return &(list->data[list->length + 1]);
}
DSLIST_API Iterator Next(Iterator pre)
{
    return pre + 1;
}
DSLIST_API constIterator cBegin(cPtrDSList list)
{
    return Begin((PtrDSList) list);
}
DSLIST_API constIterator cEnd(cPtrDSList list)
{
    return End((PtrDSList) list);
}
DSLIST_API constIterator cNext(constIterator pre)
{
    return Next((Iterator) pre);
}

// 局部函数定义
static PtrDSList AllocList(void)
{
    PtrDSList list = (PtrDSList) malloc(sizeof(DSList));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->size = INITSIZE;
    list->length = 0;
    list->data = (PtrElem) malloc((list->size + 1) * sizeof(ElemType));
    if (!list->data) {
        exit(EXIT_FAILURE);
    }
    return list;
}
static bool Full(cPtrDSList list)
{
    return Length(list) == list->size;
}
static void Expend(PtrDSList list)
{
    list->size *= 2;
    list->data = (PtrElem) realloc(list, (list->size + 1) * sizeof(ElemType));
    if (!list->data) {
        exit(EXIT_FAILURE);
    }
}
static bool ShrinkTime(cPtrDSList list)
{
    return list->length < (list->size / 2);
}
static void Shrink(PtrDSList list)
{
    list->size /= 2;
    list->data = (PtrElem) realloc(list, (list->size + 1) * sizeof(ElemType));
    if (!list->data) {
        exit(EXIT_FAILURE);
    }
}