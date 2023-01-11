/* 双向循环链表类型头文件 */
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

/* 包含头文件 */
#include "../../0 Head/ElemType.h"
#include "../../0 Head/Status.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 双向循环链表类型定义 */
struct node
{
    ElemType data;
    struct node *next;
    struct node *pre;
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

/* 双向循环链表函数接口 */

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
    
}

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

#endif