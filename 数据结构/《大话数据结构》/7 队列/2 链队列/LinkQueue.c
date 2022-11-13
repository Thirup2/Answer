/* 链队列接口函数定义源文件LinkQueue.c */

/* 包含头文件 */
#include "LinkQueue.h"

/* 数据元素处理函数原型 */

/*
** 操作：复制元素
** 参数：
** 1. 复制到的元素
** 2. 被复制的元素
*/
void CopyElem(ElemType *elem, const ElemType *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作：打印单个元素
** 参数：待打印元素
*/
void PrintElem(const ElemType *elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 循环队列接口函数原型 */

/*
** 操作：创建一个新队列
** 参数：队列大小
** 返回值：创建的队列指针
*/
PtrQueue InitQueue(void)
{
    PtrQueue queue = (PtrQueue) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->last = NULL;
    queue->length = 0;
    return queue;
}

/*
** 操作：销毁队列
** 参数： 队列指针
*/
void DestroyQueue(PtrQueue queue)
{
    ClearQueue(queue);
    free(queue);
}

/*
** 操作：清空队列
** 参数： 队列指针
*/
void ClearQueue(PtrQueue queue)
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
    queue->length = 0;
}

/*
** 操作：判断队列是否为空
** 参数： 队列指针
** 返回值：
** 1. 若队列为空则返回true
** 2. 否则返回false
*/
bool QueueEmpty(PtrQueue queue)
{
    if (queue->length == 0 && queue->head == NULL && queue->last == NULL) {
        return true;
    }
    return false;
}

/*
** 操作：返回队列的长度
** 参数：队列指针
** 返回值：
** 1. 若队列为空返回0
** 2. 否则返回队列的长度
*/
int QueueLength(PtrQueue queue)
{
    return queue->length;
}

/*
** 操作：插入元素到队尾
** 参数：
** 1. 队列指针
** 2. 待插入元素
** 返回值：
** 1. 若队列已满返回-1
** 2. 否则执行操作返回0
*/
int EnQueue(PtrQueue queue, const ElemType *elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        return -1;
    }
    CopyElem(&(node->data), elem);
    if (queue->length == 0) {
        node->next = NULL;
        queue->head = node;
        queue->last = node;
    } else {
        node->next = queue->last->next;
        queue->last->next = node;
        queue->last = node;
    }
    queue->length++;
    return 0;
}

/*
** 操作：删除队头元素
** 参数：
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值：
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int DeQueue(PtrQueue queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return -1;
    }
    PtrNode p = queue->head;
    CopyElem(elem, &(p->data));
    if (queue->length == 1) {
        free(p);
        queue->head = NULL;
        queue->last = NULL;
    } else {
        queue->head = p->next;
        free(p);
    }
    queue->length--;
    return 0;
}

/*
** 操作：返回队头元素
** 参数：
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值：
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int GetHead(PtrQueue queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return -1;
    }
    CopyElem(elem, &(queue->head->data));
    return 0;
}

/*
** 操作：打印队列（从队头到队尾）
** 参数：队列指针
*/
void PrintQueue(PtrQueue queue)
{
    PtrNode p = queue->head;
    while (p) {
        PrintElem(&(p->data));
        p = p->next;
    }
    printf("\n");
}