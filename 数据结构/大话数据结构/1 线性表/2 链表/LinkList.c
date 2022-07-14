/* 单链表接口函数定义LinkList.h */
#include "LinkList.h"
#include <stdio.h>

/* 接口函数定义 */

// 操作: 初始化一个链表
void InitList(LinkList *plist)
{
    *plist = NULL;
}

// 操作: 若链表为空, 返回true, 否则返回false
bool ListEmpty(const LinkList *plist)
{
    if (*plist == NULL) {
        return true;
    } else {
        return false;
    }
}

// 操作: 将链表清空
void ClearList(LinkList *plist)
{
    Node *psave;
    while (*plist != NULL) {
        psave = (*plist)->next;
        free(*plist);
        *plist = psave;
    }
}

// 操作: 将链表中第i个位置元素值返回给elem
bool GetElem(const LinkList *plist, int i, ElemType *elem)
{
    LinkList p;
    p = *plist;
    for (int j = 0; j < i; j++) {
        if (p == NULL) {
            printf("查找位置超过了结点数量\n");
            return false;
        }
        p = p->next;
    }
    *elem = p->data;
    return true;
}

// 操作: 在链表中查找与给定值相等的元素, 并返回位置
int LocateElem(const LinkList *plist, ElemType elem)
{
    LinkList p;
    int count = 0;
    p = *plist;
    while (p != NULL) {
        count++;
        if (p->data == elem) {
            return count;
        }
    }
    return -1;
}

// 操作: 在链表中的第i个位置插入新元素elem
int ListInsert(LinkList *plist, int i, ElemType elem)
{
    LinkList pnew;
    LinkList pold = *plist;
    pnew = (LinkList) malloc(sizeof(Node));
    if (pnew == NULL) {
        printf("链表已满\n");
        return -1;
    }
    for (int j = 0; j < i; j++) {
        if (pold == NULL) {
            printf("插入位置不合理\n");
            return -2;
        }
        pold = pold->next;
    }
    pnew->next = pold->next;
    pold->next = pnew;
    pnew->data = elem;
    return 0;
}

// 操作: 删除链表中第i个位置元素, 并用elem返回其值
int ListDelete(LinkList *plist, int i, ElemType *elem)
{
    LinkList de = *plist;
    LinkList p;
    for (int j = 0; j < i; j++) {
        if (de == NULL) {
            printf("删除位置不合理\n");
            return -1;
        }
        p = de;
        de = de->next;
    }
    *elem = de->data;
    p->next = de->next;
    free(de);
    return 0;
}

// 操作: 返回线性表的元素个数
int ListLength(const LinkList *plist)
{
    LinkList p;
    int count = 0;
    p = *plist;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}