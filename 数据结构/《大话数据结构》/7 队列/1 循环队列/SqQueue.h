/* 循环队列接口头文件SqQueue.h */
#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 数据类型定义 */
struct items
{
    int x;
    int y;
};
typedef struct items ElemType;

struct queue
{
    ElemType *data;
    int size;
    int front;          // 队头
    int rear;           // 对尾
    int length;
};
typedef struct queue Queue;
typedef Queue *PtrQueue;

/* 数据元素处理函数原型 */

/*
** 操作：复制元素
** 参数：
** 1. 复制到的元素
** 2. 被复制的元素
*/
void CopyElem(ElemType *elem, const ElemType *data);

/*
** 操作：打印单个元素
** 参数：待打印元素
*/
void PrintElem(const ElemType *elem);

/* 循环队列接口函数原型 */

/*
** 操作：创建一个新队列
** 参数：队列大小
** 返回值：创建的队列指针
*/
PtrQueue InitQueue(int size);

/*
** 操作：销毁队列
** 参数： 队列指针
*/
void DestroyQueue(PtrQueue queue);

/*
** 操作：清空队列
** 参数： 队列指针
*/
void ClearQueue(PtrQueue queue);

/*
** 操作：判断队列是否为空
** 参数： 队列指针
** 返回值：
** 1. 若队列为空则返回true
** 2. 否则返回false
*/
bool QueueEmpty(PtrQueue queue);

/*
** 操作：返回队列的长度
** 参数：队列指针
** 返回值：
** 1. 若队列为空返回0
** 2. 否则返回队列的长度
*/
int QueueLength(PtrQueue queue);

/*
** 操作：插入元素到队尾
** 参数：
** 1. 队列指针
** 2. 待插入元素
** 返回值：
** 1. 若队列已满返回-1
** 2. 否则执行操作返回0
*/
int EnQueue(PtrQueue queue, const ElemType *elem);

/*
** 操作：删除队头元素
** 参数：
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值：
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int DeQueue(PtrQueue queue, ElemType *elem);

/*
** 操作：返回队头元素
** 参数：
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值：
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int GetHead(PtrQueue queue, ElemType *elem);

/*
** 操作：打印队列（从队头到队尾）
** 参数：队列指针
*/
void PrintQueue(PtrQueue queue);

#endif