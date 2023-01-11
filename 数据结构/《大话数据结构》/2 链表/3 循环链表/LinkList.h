/* 循环链表类型头文件 */
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

/* 包含头文件 */
#include "../../0 Head/ElemType.h"
#include "../../0 Head/Status.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 循环链表类型定义 */
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct list
{
    PtrNode head;
    PtrNode last;
};
typedef struct list LinkList;
typedef LinkList *PtrLL;
typedef const LinkList *cPtrLL;

/* 循环链表函数接口 */

/*
** 操作：创建并初始化链表
** 返回值：链表指针
*/
PtrLL InitList(void);

/*
** 操作：判断链表是否为空
** 参数：链表指针
** 返回值：
** 1. 若链表为空则返回true
** 2. 否则返回false
*/
bool ListEmpty(cPtrLL list);

/*
** 操作：清空链表
** 参数：链表指针
*/
void ClearList(PtrLL list);

/*
** 操作：销毁链表
** 参数：链表指针
*/
void DestroyList(PtrLL list);

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
Status GetElem(cPtrLL list, size_t position, PtrElem elem);

/*
** 操作：查找元素
** 参数：
** 1. 链表指针
** 2. 待查找元素
** 返回值：
** 1. 若未找到，返回位序
** 2. 否则返回0
*/
size_t LocateElem(cPtrLL list, cPtrElem elem);

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
Status ListInsert(PtrLL list, size_t position, cPtrElem elem);

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
Status ListDelete(PtrLL list, size_t position, PtrElem elem);

/*
** 操作：返回链表表长
** 参数：链表指针
** 返回值：链表表长
*/
size_t ListLength(cPtrLL list);

/*
** 操作：打印链表内容
** 参数：链表指针
*/
void PrintList(cPtrLL list);

/* 接口实现 */

/*
** 操作：创建并初始化链表
** 返回值：链表指针
*/
PtrLL InitList(void)
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
    if (!ListEmpty(list)) {
        PtrNode p = list->head;
        PtrNode s = p->next;
        p->next = NULL;
        p = s;
        while (p) {
            s = p;
            p = p->next;
            free(s);
        }
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
size_t LocateElem(cPtrLL list, cPtrElem elem)
{
    if (ListEmpty(list)) {
        return 0;
    }
    size_t i = 1;
    PtrNode p = list->head;
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
        now->next = NULL;
    } else if (position == 1) {
        now->next = list->head;
        list->head = now;
    } else if (position == ListLength(list) + 1) {
        now->next = list->last->next;
        list->last->next = now;
        list->last = now;
    } else {
        PtrNode p = list->head;
        size_t i = 2;
        while (i < position) {
            i++;
            p = p->next;
        }
        now->next = p->next;
        p->next = now;
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
    if (position == 1 && ListLength(list) == 1) {
        AssignElem(elem, &list->head->data);
        free(list->head);
        list->head = NULL;
        list->last = NULL;
    } else if (position == 1) {
        PtrNode p = list->head->next;
        AssignElem(elem, &list->head->data);
        free(list->head);
        list->head = p;
        list->last->next = p;
    } else if (position == ListLength(list)) {
        PtrNode p = list->head;
        while (p->next != list->last) {
            p = p->next;
        }
        AssignElem(elem, &list->last->data);
        p->next = list->last->next;
        free(list->last);
        list->last = p;
    } else {
        PtrNode p = list->head;
        size_t i = 2;
        while (i < position) {
            i++;
            p = p->next;
        }
        AssignElem(elem, &p->next->data);
        PtrNode s = p->next->next;
        free(p->next);
        p->next = s;
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
    size_t size = 0;
    PtrNode p = list->head;
    while (p != list->last) {
        size++;
        p = p->next;
    }
    if (!p) {
        return 0;
    } else {
        size++;
        return size;
    }
}

/*
** 操作：打印链表内容
** 参数：链表指针
*/
void PrintList(cPtrLL list)
{
    PtrNode p = list->head;
    while (p != list->last) {
        PrintElem(&p->data);
        p = p->next;
    }
    if (p) {
        PrintElem(&p->data);
    }
    printf("\n");
}

#endif