/* 链队列接口头文件LinkQueue.h */
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 数据结构定义 */
struct items
{
    int x;
    int y;
};                              // 数据项结构
typedef struct items ElemType;  // 数据元素类型

struct node
{
    ElemType data;              // 数据域
    struct node *next;          // 指针域
};                              // 结点定义
typedef struct node Node;       // 结点类型
typedef Node *PNode;            // 结点指针

struct queue
{
    PNode front;                // 队头指针
    PNode rear;                 // 队尾指针
    int length;                 // 队列长度
};                              // 链队列定义
typedef struct queue LinkQueue; // 链队列类型

/* 数据元素处理函数原型 */

/*
** 操作: 更改数据元素的值
** 参数:
** 1. 待更改的数据元素指针
** 2. 用于更改的数据元素指针
*/
void ChangeElem(ElemType *elem, ElemType const *data);

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素指针
*/
void PrintElem(ElemType const *elem);

/* 链队列接口函数原型 */

/*
** 操作: 判断队列是否为空(不包含头结点)
** 参数: 一个队列指针
** 返回值:
** 1. 若队列已初始化且为空返回true
** 2. 若不为空返回false
*/
bool QueueEmpty(LinkQueue const *queue);

/*
** 操作: 返回队列的长度(不包含头结点)
** 参数: 一个队列指针
** 返回值:
** 1. 若队列未初始化则退出
** 2. 否则返回队列的长度
*/
int QueueLength(LinkQueue const *queue);

/*
** 操作: 打印整个队列的值(不包含头结点)
** 参数: 一个已初始化的队列指针
*/
void ShowQueue(LinkQueue const *queue);

/*
** 操作: 初始化链队列
** 1. 添加一个头结点
** 2. 使front和rear都指向头结点
** 3. length置为0
** 参数: 一个队列指针
*/
void InitQueue(LinkQueue *queue);

/*
** 操作: 插入元素到队尾
** 1. 添加一个结点
** 2. 更改rear的指向
** 3. length++
** 参数:
** 1. 队列指针
** 2. 待插入的元素指针
** 返回值:
** 1. 若队列已满则返回-1
** 2. 否则执行操作返回0
*/
int EnQueue(LinkQueue *queue, ElemType const *elem);

/*
** 操作: 删除队头元素
** 1. 将队头元素赋给返回指针
** 2. 更改front的指向
** 3. length--
** 4. 释放结点
** 参数:
** 1. 队列指针
** 2. 待返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int DeQueue(LinkQueue *queue, ElemType *elem);

/*
** 操作: 返回队头元素
** 参数:
** 1. 队列指针
** 2. 待返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int GetHead(LinkQueue const *queue, ElemType *elem);

/*
** 操作: 清空队列(保留头结点)
** 1. 释放所有结点(除了头结点)
** 2. 更改front和rear以及length
** 返回值:
*/
void ClearQueue(LinkQueue *queue);

/*
** 操作: 销毁队列(包括头结点)
** 1. 释放所有结点(包括头结点)
** 2. 更改front和rear以及length的值
** 参数: 队列指针
*/
void DestroyQueue(LinkQueue *queue);

#endif