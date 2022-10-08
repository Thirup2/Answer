/* 循环队列接口函数文件SqQueue.c */

/* 包含头文件 */
#include "SqQueue.h"

/* 数据元素处理函数定义 */

/*
** 操作: 更改数据元素的值
** 参数:
** 1. 待更改的数据元素指针
** 2. 用于更改的数据元素指针
*/
void ChangeElem(ElemType *elem, ElemType const *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素指针
*/
void PrintElem(ElemType const *elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 循环队列接口函数定义 */

/*
** 操作: 判断队列是否为空
** 参数: 一个队列指针
** 返回值:
** 1. 若队列为空, 返回true
** 2. 若队列不为空, 返回false
*/
bool QueueEmpty(Queue const *queue)
{
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

/*
** 操作: 返回队列当前元素个数
** 参数: 一个队列指针
** 返回值: 队列的当前元素个数
*/
int QueueLength(Queue const *queue)
{
    return ((queue->rear - queue->front) + MAXSIZE) % MAXSIZE;
}

/*
** 操作: 打印队列元素(从队头开始)
** 参数: 一个队列指针
*/
void ShowQueue(Queue const *queue)
{
    for (int i = queue->front; i != queue->rear; i++) {
        PrintElem(&(queue->data[i]));
        i = (i + 1) % MAXSIZE;
    }
}

/*
** 操作: 队列初始化
** 1. front和rear指针都置为0
** 参数: 一个队列指针
*/
void InitQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

/*
** 操作: 入队列操作
** 1. 插入元素到队尾
** 2. 更改rear的值
** 参数:
** 1. 队列指针
** 2. 待插入元素指针
** 返回值:
** 1. 若队列已满返回-1
** 2. 否则执行操作返回0
*/
int EnQueue(Queue *queue, ElemType const *elem)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return -1;
    }
    ChangeElem(&(queue->data[queue->rear]), elem);
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return 0;
}

/*
** 操作: 出队列操作
** 1. 删除队头元素
** 2. 更改front的值
** 参数:
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int DeQueue(Queue *queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return -1;
    }
    ChangeElem(elem, &(queue->data[queue->front]));
    queue->front = (queue->front + 1) % MAXSIZE;
    return 0;
}

/*
** 操作: 返回队头元素
** 参数:
** 1. 队列指针
** 2. 用于返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int GetHead(Queue const *queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return -1;
    }
    ChangeElem(elem, &(queue->data[queue->front]));
    return 0;
}

/*
** 操作: 清空队列
** 1. 将front和rear指针置为0
** 参数:
** 1. 队列指针
*/
void ClearQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}

/*
** 操作: 销毁队列
** 1. 将front和rear指针置为0
** 参数: 队列指针
*/
void DestroyQueue(Queue *queue)
{
    queue->front = 0;
    queue->rear = 0;
}