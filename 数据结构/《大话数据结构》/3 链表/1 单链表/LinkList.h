/* 单链表接口头文件LinkList.h */
#ifndef _LINKLIST_H_
#define _LINKLIST_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>

/* 数据类型定义 */
struct items
{
    int x;
    int y;
};                              // 元素项
typedef struct items ElemType;  // 元素类型
struct node
{
    ElemType data;
    struct node *next;
};                              // 结点定义
typedef struct node Node;       // 结点类型
typedef Node *PNode;            // 结点指针
struct list
{
    PNode start;                // 头指针
    int length;                 // 链表长度
};                              // 链表定义
typedef struct list LinkList;   // 链表类型

/* 数据元素处理函数原型 */

/*
** 操作: 比较两个数据元素是否相同
** 参数: 两个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若两元素相同则返回1;
** 3. 若不同返回0
*/
int CompareElems(ElemType const *elem1, ElemType const *elem2);

/*
** 操作: 将一个数据元素赋值给另一个数组元素
** 参数: 第一个参数为被赋值的元素, 第二个参数为赋值的元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ChangeElem(ElemType *data, ElemType const *elem);

/*
** 操作: 打印一个数据元素的内容
** 参数: 一个待打印的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ShowElem(ElemType const *elem);

/*
** 操作: 获取一个元素
** 参数: 一个元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void GetElem(ElemType *elem);

/* 单链表接口函数元素 */

/*
** 操作: 判断一个链表是否为空
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空, 返回1;
** 3. 否则返回0
*/
int ListEmpty(LinkList const *list);

/*
** 操作: 返回链表的元素个数
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 否则返回链表元素个数
*/
int ListLength(LinkList const *list);

/*
** 操作: 打印链表所有元素的内容
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 链表未初始化返回-1;
** 3. 否则执行操作返回0
*/
int ListTraverse(LinkList const *list);

/*
** 操作: 初始化链表, 创建一个头结点并使头指针指向头结点, 表长设置为0
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 头结点创建失败返回-1;
** 3. 否则执行操作返回0
*/
int InitList(LinkList *list);

/*
** 操作: 清除链表内容, 只保留头结点, 表长置为0
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化则返回-1;
** 3. 否则执行操作返回0
*/
int ClearList(LinkList *list);

/*
** 操作: 插入元素, 表长加1
** 参数: 一个链表指针, 待插入的位序, 待插入的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 链表未初始化返回-1
** 3. 若插入位序不合理返回1;
** 4. 若链表已满返回-2;
** 5. 否则执行操作返回0
*/
int ListInsert(LinkList *list, int i, ElemType const *elem);

/*
** 操作: 删除元素, 表长减1, 并将被删除的元素赋值给第三参数
** 参数: 一个链表指针, 待删除的位序, 待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表无元素返回-2;
** 4. 若删除位序不合理返回1;
** 5. 否则执行操作返回0
*/
int ListDelete(LinkList *list, int i, ElemType *elem);

/*
** 操作: 修改元素内容, 并将被修改元素赋值给第四参数
** 参数: 一个链表指针, 待修改的位序, 用于修改的元素, 被修改的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表无元素返回-2;
** 4. 若位序不合理返回1;
** 5. 否则执行操作返回0
*/
int ListChange(LinkList *list, int i, ElemType const *data, ElemType *elem);

/*
** 操作: 定位某个元素在链表中的位序
** 参数: 一个链表指针, 待查找的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表无元素返回-2;
** 4. 若未找到该值, 返回0;
** 5. 否则返回该值的位序
*/
int LocateElem(LinkList const *list, ElemType const *elem);

/*
** 操作: 将链表中某个位序的元素返回给元素指针
** 参数: 一个链表指针, 待查找的位序, 待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表为空返回-2;
** 4. 若位序不合理返回1;
** 5. 否则执行操作返回0
*/
int ListSearch(LinkList const *list, int i, ElemType *elem);

/*
** 操作: 销毁链表, 包括头结点
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 否则执行操作返回0
*/
int DestroyList(LinkList *list);

#endif