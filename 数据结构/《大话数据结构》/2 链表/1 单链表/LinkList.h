/* 单链表类型接口实现 */
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

/* 包含头文件 */
#include "LinkList_head.h"

/* 接口实现 */

/*
** 操作：创建并初始化链表
** 返回值：链表指针
*/
PtrLL InitList(void)
{
    // 为链表结构分配空间
    PtrLL list = (PtrLL) malloc(sizeof(LinkList));
    if (!list) {
        exit(EXIT_FAILURE);
    }

    // 创建头结点并初始化
    list->head = (PtrNode) malloc(sizeof(Node));
    if (!list->head) {
        exit(EXIT_FAILURE);
    }

    // 初始化头结点
    list->head->next = NULL;

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
    if (ListLength(list)) {
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
    PtrNode p = list->head->next;
    PtrNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    list->head->next = NULL;
}

/*
** 操作：销毁链表
** 参数：链表指针
*/
void DestroyList(PtrLL list)
{
    ClearList(list);
    free(list->head);
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
    while (position != 0) {
        p = p->next;
        position--;
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
    size_t pos = 1;
    PtrNode ptn = list->head->next;
    while (ptn) {
        if (CompareElems(elem, &ptn->data)) {
            return pos;
        } else {
            pos++;
            ptn = ptn->next;
        }
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
    PtrNode newnode = (PtrNode) malloc(sizeof(Node));
    if (!newnode) {
        exit(EXIT_FAILURE);
    }
    PtrNode p = list->head;
    while (position != 1) {
        p = p->next;
        position--;
    }
    newnode->next = p->next;
    p->next = newnode;
    AssignElem(&newnode->data, elem);

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
    PtrNode pre = list->head;
    while (position != 1) {
        pre = pre->next;
        position--;
    }
    AssignElem(elem, &pre->next->data);
    PtrNode del = pre->next;
    pre->next = del->next;
    free(del);
    return SUCCESS;
}

/*
** 操作：返回链表表长
** 参数：链表指针
** 返回值：链表表长
*/
size_t ListLength(cPtrLL list)
{
    size_t len = 0;
    PtrNode beg = list->head->next;
    while (beg) {
        len++;
        beg = beg->next;
    }
    return len;
}

/*
** 操作：打印链表内容
** 参数：链表指针
*/
void PrintList(cPtrLL list)
{
    PtrNode node = list->head->next;
    while (node) {
        PrintElem(&node->data);
        node = node->next;
    }
    printf("\n");
}

#endif