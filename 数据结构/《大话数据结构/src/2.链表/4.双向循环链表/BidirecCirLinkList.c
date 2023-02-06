#define EXPORT
#include "BidirecCirLinkList.h"
#include <stdio.h>
#include <stdlib.h>

/* 接口实现 */

/*
** 操作：创建并初始化链表
** 返回值：链表指针
*/
PtrLL DLL_CALL InitList(void)
{
    PtrLL list = (PtrLL) malloc(sizeof(LinkList));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    // 不设置头结点
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
bool DLL_CALL ListEmpty(cPtrLL list)
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
void DLL_CALL ClearList(PtrLL list)
{
    if (!ListEmpty(list)) {
        PtrNode p = list->head;
        PtrNode s;
        while (p != list->last) {
            s = p;
            p = p->next;
            free(s);
        }
        free(p);
    }
    list->head = NULL;
    list->last = NULL;
}

/*
** 操作：销毁链表
** 参数：链表指针
*/
void DLL_CALL DestroyList(PtrLL list)
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
Status DLL_CALL GetElem(cPtrLL list, size_t position, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (position < 1 || position > ListLength(list)) {
        return WRONGPOS;
    }
    PtrNode p = list->head;
    while (--position) {
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
size_t DLL_CALL LocateElem(cPtrLL list, cPtrElem elem)
{
    size_t i = 0;
    if (!ListEmpty(list)) {
        PtrNode p = list->head;
        i++;
        while (p != list->last) {
            if (CompareElems(elem, &p->data)) {
                return i;
            }
            i++;
            p = p->next;
        }
        if (CompareElems(elem, &p->data)) {
            return i;
        } else {
            return 0;
        }
    }
    return i;
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
Status DLL_CALL ListInsert(PtrLL list, size_t position, cPtrElem elem)
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
        now->next = now;
        now->pre = now;
    } else if (position == 1) {
        now->next = list->head;
        now->pre = list->last;
        list->last->next = now;
        list->head->pre = now;
        list->head = now;
    } else if (position == ListLength(list) + 1) {
        now->next = list->head;
        now->pre = list->last;
        list->last->next = now;
        list->head->pre = now;
        list->last = now;
    } else {
        PtrNode p = list->head;
        while (--position) {
            p = p->next;
        }
        now->next = p;
        now->pre = p->pre;
        p->pre->next = now;
        p->pre = now;
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
Status DLL_CALL ListDelete(PtrLL list, size_t position, PtrElem elem)
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
        AssignElem(elem, &list->head->data);
        PtrNode p = list->head;
        list->last->next = p->next;
        p->next->pre = list->last;
        list->head = p->next;
        free(p);
    } else if (position == ListLength(list)) {
        AssignElem(elem, &list->last->data);
        PtrNode p = list->last;
        list->head->pre = p->pre;
        p->pre->next = list->head;
        list->last = p->pre;
        free(p);
    } else {
        PtrNode p = list->head;
        while (--position) {
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
size_t DLL_CALL ListLength(cPtrLL list)
{
    size_t len = 0;
    PtrNode p = list->head;
    while (p && p != list->last) {
        len++;
        p = p->next;
    }
    if (p) {
        len++;
    }
    return len;
}

/*
** 操作：打印链表内容
** 参数：链表指针
*/
void DLL_CALL PrintList(cPtrLL list)
{
    PtrNode p = list->head;
    while (p && p != list->last) {
        PrintElem(&p->data);
        p = p->next;
    }
    if (p) {
        PrintElem(&p->data);
    }
    printf("\n");
}