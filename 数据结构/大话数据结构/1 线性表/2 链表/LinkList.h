/* 单链表接口头文件LinkList.h */
#ifndef _LINKLIST_
#define _LINKLIST_

#include <stdbool.h>

/* 数据结构定义 */
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
} Node;
typedef Node *LinkList;

/* 接口函数原型 */

// 操作: 初始化操作, 创建一个空的链表
// 前提条件: plist是一个链表的头指针
// 后置条件: 创建一个结点, 使头结点在其之前
void InitList(LinkList *plist);

// 操作: 若链表为空, 返回true, 否则返回false
// 前提条件: plist是一个已初始化的链表
bool ListEmpty(const LinkList *plist);

// 操作: 将链表清空
// 前提条件: plist是一个已初始化的链表
// 后置条件: 除头结点之外的所有结点释放内存, 并将头结点指针指向NULL
void ClearList(LinkList *plist);

// 操作: 将链表中第i个位置元素值返回给elem
// 前提条件: plist是一个已初始化的链表
bool GetElem(const LinkList *plist, int i, ElemType *elem);

// 操作: 在链表中查找与给定值相等的元素, 并返回位置
// 前提条件: plist是一个已初始化的链表
// 后置条件: 若查找成功, 则返回该元素在表中序号, 否则返回0
int LocateElem(const LinkList *plist, ElemType elem);

// 操作: 在链表中的第i个位置插入新元素elem
// 前提条件: plist是一个已初始化的链表
// 后置条件: 找到位置, 断链, 连接
int ListInsert(LinkList *plist, int i, ElemType elem);

// 操作: 删除链表中第i个位置元素, 并用elem返回其值
// 前提条件: plist是一个已初始化的链表
// 后置条件: 找到位置, 断链, 释放内存, 连接
int ListDelete(LinkList *plist, int i, ElemType *elem);

// 操作: 返回线性表的元素个数
// 前提条件: plist是一个已初始化的链表
int ListLength(const LinkList *plist);

#endif