#define EXPORT

#include "DoubleCycleLinkList.h"
#include <stdlib.h>

// 局部函数声明
static PtrNode AllocNode(PtrElem elem);

// 接口函数定义
DLL_API PtrList InitList(void)
{
    PtrList list = (PtrList) malloc(sizeof(List));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->length = 0;
    list->head = AllocNode(NULL);
    list->last = AllocNode(NULL);
    list->head->next = list->last;
    list->last->pre = list->head;
    list->head->pre = list->last;
    list->last->next = list->head;
    return list;
}
DLL_API int Length(PtrList list)
{
    return list->length;
}
DLL_API int LocateElem(PtrList list, PtrElem elem)
{
    PtrNode node = list->head->next;
    int i = 0;
    while (node != list->last) {
        i++;
        if (EqualElems(elem, &(node->data))) {
            return i;
        }
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
    PtrNode node;
    int i;
    if (pos < Length(list) / 2) {
        node = list->head->next;
        i = 1;
        while (i < pos) {
            i++;
            node = node->next;
        }
    } else {
        node = list->last->pre;
        i = Length(list);
        while (i > pos) {
            i--;
            node = node->pre;
        }
    }
    CopyElems(elem, &(node->data));
    return SUCCESS;
}
DLL_API Status ListInsert(PtrList list, int pos, PtrElem elem)
{
    if (pos < 1 || pos > Length(list) + 1) {
        return WRONGPOS;
    }
    PtrNode node = AllocNode(elem);
    PtrNode pre;
    int now;
    if (pos < Length(list) / 2) {
        pre = list->head;
        now = 1;
        while (now < pos) {
            now++;
            pre = pre->next;
        }
        node->next = pre->next;
        node->pre = pre;
        pre->next = node;
        node->next->pre = node;
    } else {
        pre = list->last;
        now = Length(list) + 1;
        while (now > pos) {
            now--;
            pre = pre->pre;
        }
        node->next = pre;
        node->pre = pre->pre;
        pre->pre = node;
        node->pre->next = node;
    }
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
    PtrNode del;
    int now;
    if (pos < Length(list) / 2) {
        del = list->head->next;
        now = 1;
        while (now < pos) {
            now++;
            del = del->next;
        }
    } else {
        del = list->last->pre;
        now = Length(list);
        while (now > pos) {
            now--;
            del = del->pre;
        }
    }
    CopyElems(elem, &(del->data));
    PtrNode pre = del->pre;
    PtrNode next = del->next;
    pre->next = next;
    next->pre = pre;
    free(del);
    list->length--;
    return SUCCESS;
}
DLL_API void PrintList(PtrList list, FILE *out)
{
    PtrNode node = list->head->next;
    if (node != list->last) {
        PrintElem(&(node->data), out);
        node = node->next;
        while (node != list->last) {
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
    PtrNode node = list->head;
    PtrNode del;
    bool notEnd = true;
    while (notEnd) {
        if (node == list->last) {
            notEnd = false;
        }
        del = node;
        node = node->next;
        free(del);
    }
    free(list);
}

// 局部函数定义
static PtrNode AllocNode(PtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    node->next = node->pre = NULL;
    return node;
}