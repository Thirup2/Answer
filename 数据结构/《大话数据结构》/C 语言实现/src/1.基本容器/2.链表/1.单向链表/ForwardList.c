#define EXPORT

// --------------------------- 包含头文件 --------------------------- //
#include "ForwardList.h"
#include <stdlib.h>
#include <stdio.h>

// ---------------------------   接口    --------------------------- //

// 局部函数声明
// 带头结点的空链表
PtrFlist AllocFlist(void);
// 指针指向空的结点
PtrNode AllocNode(cPtrElem elem);

// 函数接口定义
// 构造链表
PtrFlist DLL_CALL InitList(void)
{
    PtrFlist list = AllocFlist();
    return list;
}
PtrFlist DLL_CALL CreateFlist(cPtrNode begin, cPtrNode end)
{
    PtrFlist list = AllocFlist();
    PtrNode inser = FrontInserter(list);
    while (begin != end) {
        InsertAfter(list, inser, &(begin->elem));
        begin = cNext(begin);
        inser = InsertNext(inser);
    }
    return list;
}
PtrFlist DLL_CALL CopyFlist(cPtrFlist copied)
{
    PtrFlist list = AllocFlist();
    PtrNode before = FrontInserter(list);
    cPtrNode cbeg = cBegin(copied);
    cPtrNode cend = cEnd(copied);
    while (cbeg != cend) {
        InsertAfter(list, before, &(cbeg->elem));
        cbeg = cNext(cbeg);
        before = InsertNext(before);
    }
    return list;
}
PtrFlist DLL_CALL MakeFlist(size_t n, cPtrElem elem)
{
    PtrFlist list = AllocFlist();
    PtrNode before = FrontInserter(list);
    while (n > 0) {
        InsertAfter(list, before, elem);
        n--;
        before = InsertNext(before);
    }
    return list;
}
// 清空链表
void DLL_CALL ClearList(PtrFlist list)
{
    while (!ListEmpty(list)) {
        PopFront(list, NULL);
    }
}
// 销毁链表
void DLL_CALL DestroyList(PtrFlist list)
{
    ClearList(list);
    free(list->head);
    free(list);
}
// 基本信息
bool DLL_CALL ListEmpty(cPtrFlist list)
{
    return ListLength(list) == 0;
}
size_t DLL_CALL ListLength(cPtrFlist list)
{
    return list->length;
}
// 改变元素
Status DLL_CALL PushFront(PtrFlist list, cPtrElem elem)
{
    PtrNode node = AllocNode(elem);
    node->next = list->head->next;
    list->head->next = node;
    list->length++;
    return SUCCESS;
}
Status DLL_CALL PopFront(PtrFlist list, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    PtrNode node = list->head->next;
    if (elem) {
        AssignElem(elem, &(node->elem));
    }
    list->head->next = node->next;
    free(node);
    list->length--;
    return SUCCESS;
}
Status DLL_CALL InsertAfter(PtrFlist list, PtrNode place, cPtrElem elem)
{
    PtrNode node = AllocNode(elem);
    node->next = place->next;
    place->next = node;
    list->length++;
    return SUCCESS;
}
Status DLL_CALL DeleteAfter(PtrFlist list, PtrNode place, PtrElem elem)
{
    PtrNode node = place->next;
    place->next = node->next;
    if (elem) {
        AssignElem(elem, &(node->elem));
    }
    free(node);
    list->length--;
    return SUCCESS;
}
Status DLL_CALL ListInsert(PtrFlist list, size_t i, cPtrElem elem)
{
    if (i < 1 || i > ListLength(list) + 1) {
        return WRONGPOS;
    }
    if (i == 1) {
        return PushFront(list, elem);
    }
    PtrNode inser = FrontInserter(list);
    while (i > 1) {
        inser = InsertNext(inser);
        i--;
    }
    return InsertAfter(list, inser, elem);
}
Status DLL_CALL ListDelete(PtrFlist list, size_t i, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (i < 1 || i > ListLength(list)) {
        return WRONGPOS;
    }
    if (i == 1) {
        return PopFront(list, elem);
    }
    PtrNode dele = FrontInserter(list);
    while (i > 1) {
        dele = InsertNext(dele);
        --i;
    }
    return DeleteAfter(list, dele, elem);
}
// 遍历
void DLL_CALL PrintList(cPtrFlist list)
{
    cPtrNode cbeg = cBegin(list);
    cPtrNode cend = cEnd(list);
    while (cbeg != cend) {
        PrintElem(&(cbeg->elem));
        printf(" ");
        cbeg = cNext(cbeg);
    }
    printf("\n");
}
// 迭代器操作
PtrNode DLL_CALL Begin(PtrFlist list)
{
    return list->head->next;
}
PtrNode DLL_CALL End(PtrFlist list)
{
    return NULL;
}
PtrNode DLL_CALL Next(PtrNode now)
{
    return now->next;
}
cPtrNode DLL_CALL cBegin(cPtrFlist list)
{
    return Begin((PtrFlist) list);
}
cPtrNode DLL_CALL cEnd(cPtrFlist list)
{
    return End((PtrFlist) list);
}
cPtrNode DLL_CALL cNext(cPtrNode now)
{
    return Next((PtrNode) now);
}
PtrNode DLL_CALL FrontInserter(PtrFlist list)
{
    return list->head;
}
PtrNode DLL_CALL InsertNext(PtrNode now)
{
    return now->next;
}

// 局部函数定义
// 带头结点的空链表
PtrFlist AllocFlist(void)
{
    PtrFlist list = (PtrFlist) malloc(sizeof(ForwardList));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->length = 0;
    list->head = AllocNode(NULL);
    return list;
}
// 指针指向空的结点
PtrNode AllocNode(cPtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    if (elem) {
        AssignElem(&(node->elem), elem);
    }
    node->next = NULL;
    return node;
}