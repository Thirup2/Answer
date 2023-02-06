#define EXPORT
#include "LinkQueue.h"
#include <stdlib.h>
#include <stdio.h>

/* 接口实现 */

/*
** 操作：初始化操作
** 参数：新队列的大小
** 返回值：队列指针
*/
PtrQueue DLL_CALL InitQueue(void)
{
    PtrQueue queue = (PtrQueue) malloc(sizeof(Queue));
    if (!queue) {
        exit(EXIT_FAILURE);
    }
    queue->head = NULL;
    queue->last = NULL;
    return queue;
}

/*
** 操作：销毁队列
** 参数：队列
*/
void DLL_CALL DestroyQueue(PtrQueue queue)
{
    ClearQueue(queue);
    free(queue);
}

/*
** 操作：清空队列
** 参数：队列
*/
void DLL_CALL ClearQueue(PtrQueue queue)
{
    PtrNode p = queue->head;
    PtrNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    queue->head = NULL;
    queue->last = NULL;
}

/*
** 操作：判断队列是否为空
** 参数：队列
** 返回值：true or false
*/
bool DLL_CALL QueueEmpty(cPtrQueue queue)
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
size_t DLL_CALL QueueLength(cPtrQueue queue)
{
    size_t i = 0;
    PtrNode p = queue->head;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
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
Status DLL_CALL EnQueue(PtrQueue queue, cPtrElem elem)
{
    PtrNode p = (PtrNode) malloc(sizeof(Node));
    if (!p) {
        exit(EXIT_FAILURE);
    }
    AssignElem(&p->data, elem);
    if (QueueEmpty(queue)) {
        p->next = NULL;
        p->pre = NULL;
        queue->head = p;
        queue->last = p;
    } else {
        p->next = queue->last->next;
        p->pre = queue->last;
        queue->last->next = p;
        queue->last = p;
    }
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
Status DLL_CALL DeQueue(PtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    if (QueueLength(queue) == 1) {
        AssignElem(elem, &queue->head->data);
        free(queue->head);
        queue->head = NULL;
        queue->last = NULL;
    } else {
        PtrNode p = queue->head;
        p->next->pre = p->pre;
        queue->head = p->next;
        AssignElem(elem, &p->data);
        free(p);
    }
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
Status DLL_CALL GetHead(cPtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    AssignElem(elem, &queue->head->data);
    return SUCCESS;
}

/*
** 操作：打印队列内容（从队头到队尾）
** 参数：队列
*/
void DLL_CALL PrintQueue(cPtrQueue queue)
{
    PtrNode p = queue->head;
    while (p) {
        PrintElem(&p->data);
        p = p->next;
    }
    printf("\n");
}