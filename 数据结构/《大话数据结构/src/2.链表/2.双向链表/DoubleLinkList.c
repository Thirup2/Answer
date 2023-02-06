#define EXPORT
#include "DoubleLinkList.h"
#include <stdio.h>
#include <stdlib.h>

/* 接口实现 */

/*
** 操作：创建并初始化链表
** 返回值：链表指针
*/
PtrLL InitList(void)
{
    // 为List分配内存，不创建头结点
    PtrLL list = (PtrLL) malloc(sizeof(LinkList));
    if (!list) {
        exit(EXIT_FAILURE);
    }

    // 初始化list
    list->head = NULL;
    list->last = NULL;

    return list;
}

/*
** 操作：判断链表是否为空
** 参数：链表指针
** 返回值：
** 1. 若链表为空则返回true
** 2. 否则返回false
*/
bool ListEmpty(cPtrLL list)
{
    if (ListLength(list) == 0) {
        return true;
    }
    return false;
}

/*
** 操作：清空链表
** 参数：链表指针
*/
void ClearList(PtrLL list)
{
    PtrNode p = list->head;
    PtrNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    list->head = NULL;
    list->last = NULL;
}

/*
** 操作：销毁链表
** 参数：链表指针
*/
void DestroyList(PtrLL list)
{
    ClearList(list);
    free(list);
}

/*
** 操作：访问元素
** 参数：
** 1. 链表指针
** 2. 指定位置
** 3. 用于返回的数据元素指针
** 返回值：
** 1. 若链表为空返回ISEMPTY
** 2. 若指定位置不合理返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status GetElem(cPtrLL list, size_t position, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (position < 1 || position > ListLength(list)) {
        return WRONGPOS;
    }
    size_t i = 1;
    PtrNode p = list->head;
    while (i < position) {
        i++;
        p = p->next;
    }
    AssignElem(elem, &p->data);
    return SUCCESS;
}

/*
** 操作：查找元素
** 参数：
** 1. 链表指针
** 2. 待查找元素
** 返回值：
** 1. 若未找到，返回位序
** 2. 否则返回0
*/
size_t LocateElem(cPtrLL list, cPtrElem elem)
{
    size_t i = 0;
    PtrNode p = list->head;
    while (p) {
        i++;
        if (CompareElems(elem, &p->data)) {
            return i;
        }
        p = p->next;
    }
    return 0;
}

/*
** 操作：插入元素
** 参数：
** 1. 链表指针
** 2. 待插入位置
** 3. 待插入元素
** 返回值：
** 1. 若插入位置不合理返回WRONGPOS
** 2. 否则执行操作返回SUCCESS
*/
Status ListInsert(PtrLL list, size_t position, cPtrElem elem)
{
    if (position < 1 || position > ListLength(list) + 1) {
        return WRONGPOS;
    }
    PtrNode now = (PtrNode) malloc(sizeof(Node));
    if (!now) {
        exit(EXIT_FAILURE);
    }
    AssignElem(&now->data, elem);
    if (ListEmpty(list)) {
        list->head = now;
        list->last = now;
        now->pre = NULL;
        now->next = NULL;
    } else {
        PtrNode p = list->head;
        if (position == 1) {
            now->pre = p->pre;
            now->next = p;
            p->pre = now;
            list->head = now;
        } else if (position == ListLength(list) + 1) {
            p = list->last;
            now->next = p->next;
            now->pre = p;
            p->next = now;
            list->last = now;
        } else {
            size_t i = 2;
            while (i < position) {
                i++;
                p = p->next;
            }
            now->next = p->next;
            now->pre = p;
            p->next = now;
            now->next->pre = now;
        }
    }
    return SUCCESS;
}

/*
** 操作：删除元素
** 参数：
** 1. 链表指针
** 2. 待删除位置
** 3. 用于返回被删除元素的指针
** 返回值：
** 1. 若链表为空返回ISEMPTY
** 2. 若删除位置不合理返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status ListDelete(PtrLL list, size_t position, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (position < 1 || position > ListLength(list)) {
        return WRONGPOS;
    }
    if (ListLength(list) == 1) {
        AssignElem(elem, &list->head->data);
        free(list->head);
        list->head = NULL;
        list->last = NULL;
    } else if (position == 1) {
        PtrNode p = list->head;
        AssignElem(elem, &list->head->data);
        p->next->pre = NULL;
        list->head = p->next;
        free(p);
    } else if (position == ListLength(list)) {
        PtrNode p = list->last;
        AssignElem(elem, &list->last->data);
        p->pre->next = NULL;
        list->last = p->pre;
        free(p);
    } else {
        PtrNode p = list->head;
        size_t i = 1;
        while (i < position) {
            i++;
            p = p->next;
        }
        AssignElem(elem, &p->data);
        p->pre->next = p->next;
        p->next->pre = p->pre;
        free(p);
    }
    return SUCCESS;
}

/*
** 操作：返回链表表长
** 参数：链表指针
** 返回值：链表表长
*/
size_t ListLength(cPtrLL list)
{
    PtrNode p = list->head;
    size_t i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

/*
** 操作：打印链表内容
** 参数：链表指针
*/
void PrintList(cPtrLL list)
{
    PtrNode p = list->head;
    while (p) {
        PrintElem(&p->data);
        p = p->next;
    }
    printf("\n");
}