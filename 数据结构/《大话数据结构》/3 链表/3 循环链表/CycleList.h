/* 循环链表接口头文件CycleList.h */
#ifndef _CYCLELIST_H_
#define _CYCLELIST_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 数据类型定义 */
struct items
{
    int x;
    int y;
};
typedef struct items ElemType;

struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;

struct list
{
    PtrNode head;
    PtrNode last;
    int length;
};
typedef struct list LinkList;
typedef LinkList *List;

/* 数据元素处理函数原型 */

/*
** 操作: 比较两个数据元素
** 参数: 两个数据元素指针
** 返回值:
** 1. 若相同返回true
** 2. 否则返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2);

/*
** 操作: 给数据元素赋值
** 参数:
** 1. 被赋值的元素
** 2. 用于赋值的元素
*/
void CopyElem(ElemType *elem, ElemType *data);

/*
** 操作: 打印一个数据元素
** 参数: 一个数据元素
*/
void PrintElem(ElemType *elem);

/*
** 操作: 读取一个数据元素
** 参数: 一个元素指针
*/
void ScanElem(ElemType *elem);

/* 链表接口函数原型 */

/*
** 操作: 初始化操作, 建立一个空链表(包含一个头结点)
** 返回值: 链表指针类型
*/
List InitList(void);

/*
** 操作: 判断链表是否为空
** 参数: 链表指针
** 返回值:
** 1. 若链表为空返回true
** 2. 否则返回false
*/
bool ListEmpty(List list);

/*
** 操作: 将链表清空
** 参数: 链表指针
*/
void ClearList(List list);

/*
** 操作: 销毁链表
** 参数: 链表指针
*/
void DestroyList(List list);

/*
** 操作: 返回链表中第i个位置的元素
** 参数:
** 1. 链表指针
** 2. 位置i
** 3. 用于返回元素的指针
** 返回值:
** 1. 若链表为空, 返回-1
** 2. 若位置不合理, 返回1
** 3. 否则执行操作返回0
*/
int GetElem(List list, int i, ElemType *elem);

/*
** 操作: 定位元素在链表中的位置
** 参数:
** 1. 链表指针
** 2. 待定位的元素指针
** 返回值:
** 1. 若链表为空则返回-1
** 2. 若无该元素返回0
** 3. 否则返回该元素的位序
*/
int LocateElem(List list, ElemType *elem);

/*
** 操作: 插入元素到链表
** 参数:
** 1. 链表指针
** 2. 插入位序
** 3. 插入元素
** 返回值:
** 1. 若链表已满返回-1
** 2. 若插入位序不合理返回1
** 3. 否则执行操作返回0
*/
int ListInsert(List list, int i, ElemType *elem);

/*
** 操作: 删除链表中第i个位置的元素
** 参数:
** 1. 链表指针
** 2. 删除位序
** 3. 用于返回的元素
** 返回值:
** 1. 若链表为空返回-1
** 2. 若删除位序不合理返回1
** 3. 否则执行操作返回0
*/
int ListDelete(List list, int i, ElemType *elem);

/*
** 操作: 返回链表的元素个数
** 参数: 链表指针
** 返回值: 链表元素个数
*/
int ListLength(List list);

/*
** 操作: 打印链表元素
** 参数: 链表指针
*/
void PrintList(List list);

#endif