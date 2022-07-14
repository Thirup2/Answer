/* 循环队列接口头文件CyQueue.h */
#ifndef _CYQUEUE_H_
#define _CYQUEUE_H_

#include <stdbool.h>
/* 数据结构定义 */
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} CyQueue;  // 空队列判断条件为front==rear, 满队列判断条件为(rear+1)%MAXSIZE==front

/* 函数接口原型 */

//操作: 初始化操作, 创建一个空队列
//前提条件: pqueue指向一个队列
//后置条件: front=rear=0;
void InitQueue(CyQueue *pqueue);

//操作: 若队列存在, 则销毁它
//前提条件: pqueue指向一个队列
//后置条件: front=rear=0;
void DestroyQueue(CyQueue *pqueue);

//操作: 将队列清空
//前提条件: pqueue指向一个队列
//后置条件: front=rear=0;
void ClearQueue(CyQueue *pqueue);

//操作: 若队列为空, 返回true, 否则返回false
//前提条件: queue是一个队列
bool QueueEmpty(CyQueue queue);

//操作: 若队列存在且非空, 用elem返回其队头元素
//前提条件: queue是一个队列
//后置条件: 若为空, 返回false, 否则执行操作并返回true
bool GetHead(CyQueue queue, ElemType *elem);

//操作: 若队列存在, 插入新元素elem到队尾
//前提条件: pqueue指向一个队列
//后置条件: 若已满, 返回false, 否则执行操作并返回true
bool EnQueue(CyQueue *pqueue, ElemType elem);

//操作: 删除队列中队头元素, 并用elem返回其值
//前提条件: pqueue指向一个队列
//后置条件: 若为空, 返回false, 否则执行操作并返回true
bool DeQueue(CyQueue *pqueue, ElemType *elem);

//操作: 返回队列中元素个数
//前提条件: queue是一个队列
int QueueLength(CyQueue queue);

#endif