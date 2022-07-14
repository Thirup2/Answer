/* 链队列接口函数文件LinkQueue.c */
#include "LinkQueue.h"
#include <stdlib.h>

/* 接口函数定义 */

// 操作: 初始化操作, 建立一个空队列
void InitQueue(LinkQueue *pqueue)
{
    pNode p;
    p = (pNode) malloc(sizeof(Node));
    p->next = NULL;
    pqueue->head = p;
    pqueue->back = p;
}

// 操作: 若队列存在, 则销毁它
bool DestroyQueue(LinkQueue *pqueue)
{
    if (pqueue->head == NULL) {
        return false;
    }
    pqueue->back = pqueue->back->next;
    pNode p;
    while (pqueue->head) {
        p = pqueue->head;
        pqueue->head = pqueue->head->next;
        free(p);
    }
    return true;
}

// 操作: 将队列清空
bool ClearQueue(LinkQueue *pqueue)
{
    if (QueueEmpty(*pqueue)) {
        return false;
    }
    pqueue->back = pqueue->head;
    pNode p, q;
    p = pqueue->head->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    pqueue->head->next = NULL;
    return true;
}

// 操作: 若队列为空, 返回true, 否则返回false
bool QueueEmpty(LinkQueue queue)
{
    if (queue.head == queue.back) {
        return true;
    } else {
        return false;
    }
}

// 操作: 若队列存在且非空, 用elem返回队列的队头元素
bool GetHead(LinkQueue queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return false;
    }
    *elem = queue.head->next->data;
    return true;
}

// 操作: 若队列存在, 插入新元素elem到队列中并成为队尾元素
bool EnQueue(LinkQueue *pqueue, ElemType elem)
{
    pNode p;
    p = (pNode) malloc(sizeof(Node));
    if (!p) {
        return false;
    }
    p->data = elem;
    p->next = NULL;
    pqueue->back->next = p;
    pqueue->back = p;
    return true;
}

// 操作: 删除队列中队头元素, 并用elem返回其值
bool DeQueue(LinkQueue *pqueue, ElemType *elem)
{
    if (QueueEmpty(*pqueue)) {
        return false;
    }
    *elem = pqueue->head->next->data;
    pNode p;
    p = pqueue->head->next;
    pqueue->head->next = p->next;
    if (pqueue->back == p) {
        pqueue->back = pqueue->head;
    }
    free(p);
    return true;
}

// 操作: 返回队列中的元素个数
int QueueLength(LinkQueue queue)
{
    pNode p;
    int count = 0;
    p = queue.head->next;
    while (!p) {
        count++;
        p = p->next;
    }
    return count;
}