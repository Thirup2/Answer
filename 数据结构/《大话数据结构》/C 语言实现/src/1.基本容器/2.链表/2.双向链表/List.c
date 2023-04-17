#define EXPORT

// --------------------------- 包含头文件 --------------------------- //
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

// ---------------------------   接口    --------------------------- //

// 局部函数声明
// 构造一个带头结点的空表
static PtrList AllocList(void);
// 分配一个结点
static PtrNode AllocNode(cPtrElem elem);

// 函数接口声明
// 构造链表
PtrList DLL_CALL InitList(void)
{
    PtrList list = AllocList();
    return list;
}
PtrList DLL_CALL CreateList(cPtrNode begin, cPtrNode end)
{
    PtrList list = AllocList();
    while (begin != end) {
        PushBack(list, &(begin->elem));
        begin = cNext(begin);
    }
    return list;
}
PtrList DLL_CALL CopyList(cPtrList copied)
{
    PtrList list = AllocList();
    cPtrNode begin = cBegin(copied);
    cPtrNode end = cEnd(copied);
    while (begin != end) {
        PushBack(list, &(begin->elem));
        begin = cNext(begin);
    }
    return list;
}
PtrList DLL_CALL MakeList(size_t n, cPtrElem elem)
{
    PtrList list = AllocList();
    while (n > 0) {
        PushBack(list, elem);
        n--;
    }
    return list;
}
// 清空链表
void DLL_CALL ClearList(PtrList list)
{
    while (!ListEmpty(list)) {
        PopBack(list, NULL);
    }
}
// 销毁链表
void DLL_CALL DestroyList(PtrList list)
{
    ClearList(list);
    free(list->head);
    free(list);
}
// 基本信息
bool DLL_CALL ListEmpty(cPtrList list)
{
    return ListLength(list) == 0;
}
size_t DLL_CALL ListLength(cPtrList list)
{
    return list->size;
}
// 改变元素
Status DLL_CALL PushBack(PtrList list, cPtrElem elem)
{
    PtrNode node = AllocNode(elem);
    node->next = list->last->next;
    node->pre = list->last;
    list->last->next = node;
    list->last = node;
    list->size++;
    return SUCCESS;
}
Status DLL_CALL PopBack(PtrList list, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    PtrNode node = list->last;
    if (elem) {
        AssignElem(elem, &(node->elem));
    }
    PtrNode nodepre = node->pre;
    nodepre->next = node->next;
    free(node);
    list->last = nodepre;
    list->size--;
    return SUCCESS;
}
Status DLL_CALL PushFront(PtrList list, cPtrElem elem)
{
    if (ListEmpty(list)) {
        return PushBack(list, elem);
    }
    PtrNode node = AllocNode(elem);
    node->pre = list->head;
    node->next = list->head->next;
    list->head->next->pre = node;
    list->head->next = node;
    list->size++;
    return SUCCESS;
}
Status DLL_CALL PopFront(PtrList list, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (ListLength(list) == 1) {
        return PopBack(list, elem);
    }
    PtrNode node = list->head->next;
    PtrNode nodenext = node->next;
    if (elem) {
        AssignElem(elem, &(node->elem));
    }
    list->head->next = nodenext;
    nodenext->pre = list->head;
    free(node);
    list->size--;
    return SUCCESS;
}
Status DLL_CALL PlaceInsert(PtrList list, PtrNode place, cPtrElem elem)
{
    if (place == cBegin(list)) {
        return PushFront(list, elem);
    }
    if (place == cEnd(list)) {
        return PushBack(list, elem);
    }
    PtrNode pre = place->pre;
    PtrNode node = AllocNode(elem);
    node->next = place;
    node->pre = pre;
    pre->next = node;
    place->pre = node;
    list->size++;
    return SUCCESS;
}
Status DLL_CALL PlaceDelete(PtrList list, PtrNode place, PtrElem elem)
{
    if (place == cBegin(list)) {
        return PopFront(list, elem);
    }
    if (place == cEnd(list)) {
        return PopBack(list, elem);
    }
    PtrNode pre = place->pre;
    PtrNode next = place->next;
    pre->next = next;
    next->pre = pre;
    if (elem) {
        AssignElem(elem, &(place->elem));
    }
    list->size--;
    return SUCCESS;
}
Status DLL_CALL ListInsert(PtrList list, size_t i, cPtrElem elem)
{
    if (i < 1 || i > ListLength(list) + 1) {
        return WRONGPOS;
    }
    if (i == 1) {
        return PushFront(list, elem);
    }
    if (i == ListLength(list) + 1) {
        return PushBack(list, elem);
    }
    PtrNode inser = Begin(list);
    while (i > 1) {
        i--;
        inser = Next(inser);
    }
    return PlaceInsert(list, inser, elem);
}
Status DLL_CALL ListDelete(PtrList list, size_t i, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (i < 1 || i > ListLength(list)) {
        return WRONGPOS;
    }
    PtrNode inser = Begin(list);
    while (i > 1) {
        i--;
        inser = Next(inser);
    }
    return PlaceDelete(list, inser, elem);
}
// 遍历
void DLL_CALL PrintList(cPtrList list)
{
    cPtrNode beg = cBegin(list);
    cPtrNode end = cEnd(list);
    while (beg != end) {
        PrintElem(&(beg->elem));
        printf(" ");
        beg = cNext(beg);
    }
    printf("\n");
}
// 迭代器操作
PtrNode DLL_CALL Begin(PtrList list)
{
    return list->head->next;
}
PtrNode DLL_CALL End(PtrList list)
{
    return list->last->next;
}
PtrNode DLL_CALL Next(PtrNode now)
{
    return now->next;
}
cPtrNode DLL_CALL cBegin(cPtrList list)
{
    return Begin((PtrList) list);
}
cPtrNode DLL_CALL cEnd(cPtrList list)
{
    return End((PtrList) list);
}
cPtrNode DLL_CALL cNext(cPtrNode now)
{
    return Next((PtrNode) now);
}

// 局部函数定义
// 构造一个带头结点的空表
static PtrList AllocList(void)
{
    PtrList list = (PtrList) malloc(sizeof(List));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    PtrNode node = AllocNode(NULL);
    list->head = node;
    list->last = node;
    list->size = 0;
    return list;
}
// 分配一个结点
static PtrNode AllocNode(cPtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    node->next = NULL;
    node->pre = NULL;
    if (elem) {
        AssignElem(&(node->elem), elem);
    }
    return node;
}