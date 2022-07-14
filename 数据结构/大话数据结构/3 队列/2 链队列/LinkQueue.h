/* 链队列接口头文件LinkQueue.h */
#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include <stdbool.h>
/* 数据结构定义 */
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
}Node;
typedef Node *pNode;

typedef struct
{
    pNode head;
    pNode back;
}LinkQueue;

/* 接口函数原型 */

// 操作: 初始化操作, 建立一个空队列
void InitQueue(LinkQueue *pqueue);

// 操作: 若队列存在, 则销毁它
bool DestroyQueue(LinkQueue *pqueue);

// 操作: 将队列清空
bool ClearQueue(LinkQueue *pqueue);

// 操作: 若队列为空, 返回true, 否则返回false
bool QueueEmpty(LinkQueue queue);

// 操作: 若队列存在且非空, 用elem返回队列的队头元素
bool GetHead(LinkQueue queue, ElemType *elem);

// 操作: 若队列存在, 插入新元素elem到队列中并成为队尾元素
bool EnQueue(LinkQueue *pqueue, ElemType elem);

// 操作: 删除队列中队头元素, 并用elem返回其值
bool DeQueue(LinkQueue *pqueue, ElemType *elem);

// 操作: 返回队列中的元素个数
int QueueLength(LinkQueue queue);

#endif