/* 循环队列接口函数文件SqQueue.c */

/* 包含头文件 */
#include "SqQueue.h"

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

/* 循环队列接口函数定义 */

/*
** 操作：创建一个新队列
** 参数：队列大小
** 返回值：创建的队列指针
*/
PtrQueue InitQueue(int size)
{
    PtrQueue queue = (PtrQueue) malloc(sizeof(Queue));
    if (!queue) {
        exit(EXIT_FAILURE);
    }
    queue->data = (ElemType *) malloc(size * sizeof(ElemType));
    if (!queue->data) {
        exit(EXIT_FAILURE);
    }
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;
    queue->length = 0;
    return queue;
}

/*
** 操作：销毁队列
** 参数： 队列指针
*/
void DestroyQueue(PtrQueue queue)
{
    free(queue->data);
    free(queue);
}

/*
** 操作：清空队列
** 参数： 队列指针
*/
void ClearQueue(PtrQueue queue)
{
    queue->front = 0;
    queue->rear = 0;
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
    if (queue->length == 0) {
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
    if (QueueLength(queue) == queue->size) {
        return -1;
    }
    if (queue->length == 0) {
        CopyElem(&(queue->data[queue->front]), elem);
    } else {
        CopyElem(&(queue->data[(++queue->rear)%(queue->size)]), elem);
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
    CopyElem(elem, &(queue->data[queue->front]));
    if (queue->length == 1) {
        queue->length = 0;
    } else {
        queue->front = (queue->front + 1) % queue->size;
        queue->length--;
    }
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
    CopyElem(elem, &(queue->data[queue->front]));
    return 0;
}

/*
** 操作：打印队列（从队头到队尾）
** 参数：队列指针
*/
void PrintQueue(PtrQueue queue)
{
    if (QueueEmpty(queue)) {
        printf("空队列\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i = (i + 1) % queue->size) {
        if (i == queue->rear) {
            PrintElem(&(queue->data[i]));
            break;
        }
        PrintElem(&(queue->data[i]));
    }
    printf("\n");
}