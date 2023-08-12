#define EXPORT
#include "DynamicSeqList.h"
#include <stdlib.h>

// 局部函数声明
// 无

// 接口函数定义
DLL_API PtrList InitList(void)
{
    PtrList list = (PtrList)malloc(sizeof(List));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->length = 0;
    list->capacity = INITSIZE + 1;
    list->data = (PtrElem)malloc(list->capacity * (sizeof(ElemType)));
    if (!list->data) {
        exit(EXIT_FAILURE);
    }
    return list;
}
DLL_API int Length(PtrList list)
{
    return list->length;
}
DLL_API int LocateElem(PtrList list, PtrElem elem)
{
    CopyElems(&(list->data[0]), elem);
    int i;
    for (i = Length(list); !EqualElems(&(list->data[i]), elem); i--);
    return i;
}
DLL_API Status GetElem(PtrList list, int pos, PtrElem elem)
{
    if (Empty(list)) {
        return ISEMPTY;
    }
    if (pos < 1 || pos > Length(list)) {
        return WRONGPOS;
    }
    CopyElems(elem, &(list->data[pos]));
    return SUCCESS;
}
DLL_API Status ListInsert(PtrList list, int pos, PtrElem elem)
{
    if (Length(list) == list->capacity - 1) {
        list->capacity = (list->capacity - 1) * 2 + 1;
        list->data = (PtrElem)realloc(list->data, list->capacity * (sizeof(ElemType)));
        if (!list->data) {
            exit(EXIT_FAILURE);
        }
    }
    if (pos < 1 || pos > Length(list) + 1) {
        return WRONGPOS;
    }
    for (int i = Length(list); i >= pos; i--) {
        CopyElems(&(list->data[i + 1]), &(list->data[i]));
    }
    CopyElems(&(list->data[pos]), elem);
    list->length++;
    return SUCCESS;
}
DLL_API Status ListDelete(PtrList list, int pos, PtrElem elem)
{
    if (Empty(list)) {
        return ISEMPTY;
    }
    if (pos < 1 || pos > Length(list)) {
        return WRONGPOS;
    }
    CopyElems(elem, &(list->data[pos]));
    for (int i = pos; i < Length(list); i++) {
        CopyElems(&(list->data[i]), &(list->data[i + 1]));
    }
    list->length--;
    if ((list->capacity > INITSIZE + 1) && (Length(list) < (list->capacity - 1) / 2)) {
        list->capacity = (list->capacity - 1) / 2 + 1;
        list->data = (PtrElem)realloc(list->data, list->capacity * (sizeof(ElemType)));
        if (!list->data) {
            exit(EXIT_FAILURE);
        }
    }
    return SUCCESS;
}
DLL_API void PrintList(PtrList list, FILE* out)
{
    int i = 1;
    if (!Empty(list)) {
        PrintElem(&(list->data[i++]), out);
        while (i <= Length(list)) {
            fprintf(out, " ");
            PrintElem(&(list->data[i]), out);
            ++i;
        }
    }
}
DLL_API bool Empty(PtrList list)
{
    return Length(list) == 0;
}
DLL_API void DestroyList(PtrList list)
{
    free(list->data);
    free(list);
}

// 局部函数定义
// 无