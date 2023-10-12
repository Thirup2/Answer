#define EXPORT

#include "CycleLinkList.h"
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
    list->last = NULL;        // 不需要尾结点和头结点
    list->length = 0;
    return list;
}
DLL_API int Length(PtrList list)
{
    return list->length;
}
DLL_API int LocateElem(PtrList list, PtrElem elem)
{
    if (Empty(list)) {
        return 0;
    }
    PtrNode node = list->last->next;        // 获取第一个元素
    int res = 1;
    while (res <= Length(list)) {
        if (EqualElems(elem, &(node->data))) {
            return res;
        }
        res++;
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
    PtrNode node = list->last;          // 从最后一个开始遍历
    int now = Length(list);
    while (now != pos) {                // 循环条件不能再是 < ，由于前面的条件判断现在可以确定 pos 在表内，所以用 != 没问题
        now = (now + 1) % Length(list); // 由于从最后一个开始，所以后续位置需要求模运算
        node = node->next;
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
    if (Length(list) == 0) {                // 插入第一个元素时
        list->last = node;
        node->next = node;
    } else if (pos == Length(list) + 1) {   // 插入到末尾时
        node->next = list->last->next;
        list->last->next = node;
        list->last = node;
    } else {                                // 其他情况
        PtrNode pre = list->last;
        int now = 1;
        while (now < pos) {
            now++;
            pre = pre->next;
        }
        node->next = pre->next;
        pre->next = node;
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
    if (Length(list) == 1) {            // 删除最后一个元素时
        CopyElems(elem, &(list->last->data));
        free(list->last);
        list->last = NULL;
    } else {                            // 一般情况
        PtrNode pre = list->last;
        int now = 1;
        while (now < pos) {
            now++;
            pre = pre->next;
        }
        PtrNode del;
        del = pre->next;
        pre->next = del->next;
        if (now == Length(list)) {      // 删除末尾元素时
            list->last = pre;
        }
        CopyElems(elem, &(del->data));
        free(del);
    }
    list->length--;
    return SUCCESS;
}
DLL_API void PrintList(PtrList list, FILE *out)
{
    if (Empty(list)) {
        return;
    }
    PtrNode node = list->last->next;
    int i = 0;
    if (i < Length(list)) {
        PrintElem(&(node->data), out);
        i++;
        node = node->next;
        while (i < Length(list)) {
            fprintf(out, " ");
            PrintElem(&(node->data), out);
            i++;
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
    if (!Empty(list)) {
        PtrNode node = list->last->next;
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
    node->next = NULL;
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    return node;
}