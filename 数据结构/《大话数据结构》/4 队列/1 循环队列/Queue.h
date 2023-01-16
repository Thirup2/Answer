/* 循环队列接口头文件 */
#ifndef _QUEUE_H_
#define _QUEUE_H_

/* 包含头文件 */
#include "../../0 Head/ElemType.h"
#include "../../0 Head/Status.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

/* 循环队列类型定义 */
struct queue
{
    PtrElem data;
    size_t size;
    size_t head;
    size_t last;
};
typedef struct queue Queue;
typedef Queue *PtrQueue;
typedef const Queue *cPtrQueue;

/* 循环队列函数接口 */

/*
** 操作：初始化操作
** 参数：新队列的大小
** 返回值：队列指针
*/
PtrQueue InitQueue(size_t size);

/*
** 操作：销毁队列
** 参数：队列
*/
void DestroyQueue(PtrQueue queue);

/*
** 操作：清空队列
** 参数：队列
*/
void ClearQueue(PtrQueue queue);

/*
** 操作：判断队列是否为空
** 参数：队列
** 返回值：true or false
*/
bool QueueEmpty(cPtrQueue queue);

/*
** 操作：返回队列的长度
** 参数：队列
** 返回值：队列长度
*/
size_t QueueLength(cPtrQueue queue);

/*
** 操作：插入元素到队尾
** 参数：
** 1. 队列
** 2. 插入元素
** 返回值：
** 1. 若队列已满，返回ISFULL
** 2. 否则执行操作返回SUCCESS
*/
Status EnQueue(PtrQueue queue, cPtrElem elem);

/*
** 操作：删除队头元素
** 参数：
** 1. 队列
** 2. 用于返回队头元素的指针
** 返回值：
** 1. 若队列为空返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status DeQueue(PtrQueue queue, PtrElem elem);

/*
** 操作：访问队头元素
** 参数：
** 1. 队列
** 2. 用于返回队头元素的指针
** 返回值：
** 1. 若队列为空返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status GetHead(cPtrQueue queue, PtrElem elem);

/*
** 操作：打印队列内容（从队头到队尾）
** 参数：队列
*/
void PrintQueue(cPtrQueue queue);

/* 接口实现 */

/*
** 操作：初始化操作
** 参数：新队列的大小
** 返回值：队列指针
*/
PtrQueue InitQueue(size_t size)
{
    PtrQueue queue = (PtrQueue) malloc(sizeof(Queue));
    if (!queue) {
        exit(EXIT_FAILURE);
    }
    queue->data = (PtrElem) malloc(size * sizeof(ElemType));
    if (!queue->data) {
        exit(EXIT_FAILURE);
    }
    queue->size = size;
    queue->head = 0;
    queue->last = 0;
    return queue;
}

/*
** 操作：销毁队列
** 参数：队列
*/
void DestroyQueue(PtrQueue queue)
{
    free(queue->data);
    free(queue);
}

/*
** 操作：清空队列
** 参数：队列
*/
void ClearQueue(PtrQueue queue)
{
    queue->head = 0;
    queue->last = 0;
}

/*
** 操作：判断队列是否为空
** 参数：队列
** 返回值：true or false
*/
bool QueueEmpty(cPtrQueue queue)
{
    if (QueueLength(queue) == 0) {
        return true;
    }
    return false;
}

/*
** 操作：返回队列的长度
** 参数：队列
** 返回值：队列长度
*/
size_t QueueLength(cPtrQueue queue)
{
    return (queue->last + queue->size - queue->head) % queue->size;
}

/*
** 操作：插入元素到队尾
** 参数：
** 1. 队列
** 2. 插入元素
** 返回值：
** 1. 若队列已满，返回ISFULL
** 2. 否则执行操作返回SUCCESS
*/
Status EnQueue(PtrQueue queue, cPtrElem elem)
{
    if ((queue->last + 1) % queue->size == queue->head) {
        return ISFULL;
    }
    AssignElem(&queue->data[queue->last], elem);
    queue->last = (queue->last + 1) % queue->size;
    return SUCCESS;
}

/*
** 操作：删除队头元素
** 参数：
** 1. 队列
** 2. 用于返回队头元素的指针
** 返回值：
** 1. 若队列为空返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status DeQueue(PtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    AssignElem(elem, &queue->data[queue->head]);
    queue->head = (queue->head + 1) % queue->size;
    return SUCCESS;
}

/*
** 操作：访问队头元素
** 参数：
** 1. 队列
** 2. 用于返回队头元素的指针
** 返回值：
** 1. 若队列为空返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status GetHead(cPtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    AssignElem(elem, &queue->data[queue->head]);
    return SUCCESS;
}

/*
** 操作：打印队列内容（从队头到队尾）
** 参数：队列
*/
void PrintQueue(cPtrQueue queue)
{
    size_t i = queue->head;
    while (i != queue->last) {
        PrintElem(&queue->data[i]);
        i = (i + 1) % queue->size;
    }
    printf("\n");
}

#endif