/* 顺序队列函数接口文件SqQueue.c */
#include "SqQueue.h"

/* 接口函数定义 */

//操作: 初始化操作, 建立一个空队列
void InitQueue(SqQueue *pqueue)
{
    pqueue->rear = -1;
}

//操作: 若队列存在, 则销毁它
void DestroyQueue(SqQueue *pqueue)
{
    pqueue->rear = -1;
}

//操作: 将队列清空
void ClearQueue(SqQueue *pqueue)
{
    pqueue->rear = -1;
}

//操作: 若队列为空, 返回true, 否则返回false
bool QueueEmpty(SqQueue queue)
{
    if (queue.rear == -1) {
        return true;
    } else {
        return false;
    }
}

//操作: 若队列存在且非空, 用elem返回其队头元素
bool GetHead(SqQueue queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return false;
    }
    *elem = queue.data[queue.rear];
    return true;
}

//操作: 若队列存在, 插入新元素elem到队尾
bool EnQueue(SqQueue *pqueue, ElemType elem)
{
    if (pqueue->rear == MAXSIZE - 1) {
        return false;
    }
    pqueue->rear++;
    pqueue->data[pqueue->rear] = elem;
    return true;
}

//操作: 删除队头元素, 并用elem返回其值
bool DeQueue(SqQueue *pqueue, ElemType *elem)
{
    if (QueueEmpty(*pqueue)) {
        return false;
    }
    *elem = pqueue->data[pqueue->rear];
    if (pqueue->rear == 0) {
        pqueue->rear = -1;
    } else {
        for (int i = 0; i < pqueue->rear; i++) {
            pqueue->data[i] = pqueue->data[i + 1];
        }
        pqueue->rear--;
    }
    return true;
}

//操作: 返回队列元素个数
int QueueLength(SqQueue queue)
{
    return queue.rear + 1;
}