/* 循环队列接口头文件SqQueue.h */
#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 数据类型定义 */
#define MAXSIZE 20
struct items
{
    int x;
    int y;
};                              // 数据项定义
typedef struct items ElemType;  // 数据元素类型

struct queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};                              // 数据类型定义
typedef struct queue Queue;     // 循环队列类型

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

/* 循环队列接口函数原型 */

/*
** 操作: 判断队列是否为空
** 参数: 一个队列指针
** 返回值:
** 1. 若队列为空, 返回true
** 2. 若队列不为空, 返回false
*/
bool QueueEmpty(Queue const *queue);

/*
** 操作: 返回队列当前元素个数
** 参数: 一个队列指针
** 返回值: 队列的当前元素个数
*/
int QueueLength(Queue const *queue);

/*
** 操作: 打印队列元素(从队头开始)
** 参数: 一个队列指针
*/
void ShowQueue(Queue const *queue);

/*
** 操作: 队列初始化
** 1. front和rear指针都置为0
** 参数: 一个队列指针
*/
void InitQueue(Queue *queue);

/*
** 操作: 入队列操作
** 1. 插入元素到队尾
** 2. 更改rear的值
** 参数:
** 1. 队列指针
** 2. 待插入元素指针
** 返回值:
** 1. 若队列已满返回-1
** 2. 否则执行操作返回0
*/
int EnQueue(Queue *queue, ElemType const *elem);

/*
** 操作: 出队列操作
** 1. 删除队头元素
** 2. 更改front的值
** 参数:
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int DeQueue(Queue *queue, ElemType *elem);

/*
** 操作: 返回队头元素
** 参数:
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int GetHead(Queue const *queue, ElemType *elem);

/*
** 操作: 清空队列
** 1. 将front和rear指针置为0
** 参数:
** 1. 队列指针
*/
void ClearQueue(Queue *queue);

/*
** 操作: 销毁队列
** 1. 将front和rear指针置为0
** 参数: 队列指针
*/
void DestroyQueue(Queue *queue);

#endif