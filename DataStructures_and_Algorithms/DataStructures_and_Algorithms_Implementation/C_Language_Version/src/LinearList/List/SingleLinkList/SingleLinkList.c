#define EXPORT

#include "SingleLinkList.h"
#include <stdlib.h>

// 局部函数声明
static PtrNode AllocNode(PtrElem elem);

// 接口函数定义
DLL_API PtrList InitList(void)
{
    PtrList list = AllocNode(NULL);
    return list;
}
DLL_API int Length(PtrList list)
{
    PtrNode node = list->next;
    int i = 0;
    while (node) {
        i++;
        node = node->next;
    }
    return i;
}
DLL_API int LocateElem(PtrList list, PtrElem elem)
{
    int pos = 1;
    PtrNode node = list->next;
    while (node) {
        if (EqualElems(elem, &(node->data))) {
            return pos;
        }
        pos++;
        node = node->next;
    }
    return 0;
}
DLL_API Status GetElem(PtrList list, int pos, PtrElem elem)
{
    if (Empty(list)) {
        return ISEMPTY;
    }
    if (pos < 1 || pos > Length(list)) {
        return WRONGPOS;
    }
    PtrNode node = list->next;
    int now = 1;
    while (now < pos) {
        now++;
        node = node->next;
    }
    CopyElems(elem, &(node->data));
    return SUCCESS;
}
DLL_API Status ListInsert(PtrList list, int pos, PtrElem elem)
{
    PtrNode node = AllocNode(elem);
    if (!node) {
        return ISFULL;
    }
    if (pos < 1 || pos > Length(list) + 1) {
        return WRONGPOS;
    }
    PtrNode pre = list;
    int now = 1;
    while (now < pos) {
        now++;
        pre = pre->next;
    }
    node->next = pre->next;
    pre->next = node;
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
    PtrNode pre = list;
    int now = 1;
    while (now < pos) {
        now++;
        pre = pre->next;
    }
    PtrNode del = pre->next;
    CopyElems(elem, &(del->data));
    pre->next = del->next;
    free(del);
    return SUCCESS;
}
DLL_API void PrintList(PtrList list, FILE *out)
{
    PtrNode node = list->next;
    if (node) {
        PrintElem(&(node->data), out);
        node = node->next;
        while (node) {
            fprintf(out, " ");
            PrintElem(&(node->data), out);
            node = node->next;
        }
    }
}
DLL_API bool Empty(PtrList list)
{
    return Length(list) == 0;
}
DLL_API void DestroyList(PtrList list)
{
    PtrNode node = list;
    PtrNode del;
    while (node) {
        del = node;
        node = node->next;
        free(del);
    }
}

// 局部函数定义
static PtrNode AllocNode(PtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    node->next = NULL;
    return node;
}