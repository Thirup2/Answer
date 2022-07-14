/* 循环队列接口函数文件CyQueue.c */
#include "CyQueue.h"

/* 接口函数定义 */

//操作: 初始化操作, 创建一个空队列
void InitQueue(CyQueue *pqueue)
{
    pqueue->front = 0;
    pqueue->rear = 0;
}

//操作: 若队列存在, 则销毁它
void DestroyQueue(CyQueue *pqueue)
{
    pqueue->front = 0;
    pqueue->rear = 0;
}

//操作: 将队列清空
void ClearQueue(CyQueue *pqueue)
{
    pqueue->front = 0;
    pqueue->rear = 0;
}

//操作: 若队伍为空, 返回true, 否则返回false
bool QueueEmpty(CyQueue queue)
{
    if (queue.front == queue.rear) {
        return true;
    } else {
        return false;
    }
}

//操作: 若队列存在且非空, 用elem返回其队头元素
bool GetHead(CyQueue queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return false;
    }
    *elem = queue.data[queue.front];
    return true;
}

//操作: 若队列存在, 插入新元素elem到队尾
bool EnQueue(CyQueue *pqueue, ElemType elem)
{
    if ((pqueue->rear + 1) % MAXSIZE == pqueue->front) {
        return false;
    }
    pqueue->data[pqueue->rear] = elem;
    pqueue->rear = (pqueue->rear + 1) % MAXSIZE;
    return true;
}

//操作: 删除队列中队头元素, 并用elem返回其值
bool DeQueue(CyQueue *pqueue, ElemType *elem)
{
    if (QueueEmpty(*pqueue)) {
        return false;
    }
    *elem = pqueue->data[pqueue->front];
    pqueue->front = (pqueue->front + 1) % MAXSIZE;
    return true;
}

//操作: 返回队列中元素个数
int QueueLength(CyQueue queue)
{
    return (queue.rear - queue.front + MAXSIZE) % MAXSIZE;
}