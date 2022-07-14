/* 顺序队列接口头文件SqQueue.h */
#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_

#include <stdbool.h>

/* 数据结构定义 */
#define MAXSIZE 20
typedef int ElemType;       // 一个数据元素, 包括一个数据项int
typedef struct
{
    ElemType data[MAXSIZE];
    int rear;
}SqQueue;

/* 接口函数原型 */

//操作: 初始化操作, 建立一个空队列
//前提条件: pqueue指向一个队列
//后置条件: rear置为-1;
void InitQueue(SqQueue *pqueue);

//操作: 若队列存在, 则销毁它
//前提条件: pqueue指向一个队列
//后置条件: rear置为-1
void DestroyQueue(SqQueue *pqueue);

//操作: 将队列清空
//前提条件: pqueue指向一个队列
//后置条件: rear置为-1
void ClearQueue(SqQueue *pqueue);

//操作: 若队列为空, 返回true, 否则返回false
//前提条件: queue为一个队列
bool QueueEmpty(SqQueue queue);

//操作: 若队列存在且非空, 用elem返回其队头元素
//前提条件: queue是一个队列
//后置条件: 若队列为空, 返回false, 否则返回true
bool GetHead(SqQueue queue, ElemType *elem);

//操作: 若队列存在, 插入新元素elem到队尾
//前提条件: pqueue指向一个队列
//后置条件: rear+1
bool EnQueue(SqQueue *pqueue, ElemType elem);

//操作: 删除队头元素, 并用elem返回其值
//前提条件: pqueue指向一个队列
//后置条件: rear-1
bool DeQueue(SqQueue *pqueue, ElemType *elem);

//操作: 返回队列元素个数
//前提条件: queue是一个队列
int QueueLength(SqQueue queue);

#endif