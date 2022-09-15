/* 链队列接口函数定义源文件LinkQueue.c */

/* 包含头文件 */
#include "LinkQueue.h"

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

/* 链队列接口函数定义 */

/*
** 操作: 判断队列是否为空(不包含头结点)
** 参数: 一个队列指针
** 返回值:
** 1. 若队列已初始化且为空返回true
** 2. 若不为空返回false
*/
bool QueueEmpty(LinkQueue const *queue)
{
    if (queue->front == queue->rear) {
        return true;
    }
    return false;
}

/*
** 操作: 返回队列的长度(不包含头结点)
** 参数: 一个队列指针
** 返回值:
** 1. 若队列未初始化则退出
** 2. 否则返回队列的长度
*/
int QueueLength(LinkQueue const *queue)
{
    return queue->length;
}

/*
** 操作: 打印整个队列的值(不包含头结点)
** 参数: 一个已初始化的队列指针
*/
void ShowQueue(LinkQueue const *queue)
{
    PNode p = queue->front->next;
    while (p) {
        PrintElem(&(p->data));
        p = p->next;
    }
}

/*
** 操作: 初始化链队列
** 1. 添加一个头结点
** 2. 使front和rear都指向头结点
** 3. length置为0
** 参数: 一个队列指针
*/
void InitQueue(LinkQueue *queue)
{
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        exit(EXIT_FAILURE);
    }
    p->next = NULL;
    queue->front = p;
    queue->rear = p;
    queue->length = 0;
}

/*
** 操作: 插入元素到队尾
** 1. 添加一个结点
** 2. 更改rear的指向
** 3. length++
** 参数:
** 1. 队列指针
** 2. 待插入的元素指针
** 返回值:
** 1. 若队列已满则返回-1
** 2. 否则执行操作返回0
*/
int EnQueue(LinkQueue *queue, ElemType const *elem)
{
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        return -1;
    }
    p->next = NULL;
    ChangeElem(&(p->data), elem);
    queue->rear->next = p;
    queue->rear = p;
    queue->length++;
    return 0;
}

/*
** 操作: 删除队头元素
** 1. 将队头元素赋给返回指针
** 2. 更改front的指向
** 3. length--
** 4. 释放结点
** 参数:
** 1. 队列指针
** 2. 待返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int DeQueue(LinkQueue *queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return -1;
    }
    PNode p = queue->front->next;
    ChangeElem(elem, &(p->data));
    queue->front = p->next;
    free(p);
    queue->length--;
    return 0;
}

/*
** 操作: 返回队头元素
** 参数:
** 1. 队列指针
** 2. 待返回的元素指针
** 返回值:
** 1. 若队列为空返回-1
** 2. 否则执行操作返回0
*/
int GetHead(LinkQueue const *queue, ElemType *elem)
{
    if (QueueEmpty(queue)) {
        return -1;
    }
    ChangeElem(elem, &(queue->front->next->data));
    return 0;
}

/*
** 操作: 清空队列(保留头结点)
** 1. 释放所有结点(除了头结点)
** 2. 更改front和rear以及length
** 返回值:
*/
void ClearQueue(LinkQueue *queue)
{
    PNode p = queue->front->next;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    queue->front->next = NULL;
    queue->rear = queue->front;
    queue->length = 0;
}

/*
** 操作: 销毁队列(包括头结点)
** 1. 释放所有结点(包括头结点)
** 2. 更改front和rear以及length的值
** 参数: 队列指针
*/
void DestroyQueue(LinkQueue *queue)
{
    PNode p = queue->front;
    Pnode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    queue->front = NULL;
    queue->rear = NULL;
    queue->length = -1;
}