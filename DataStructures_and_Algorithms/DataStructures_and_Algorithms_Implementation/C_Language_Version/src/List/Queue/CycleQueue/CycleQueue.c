#define EXPORT

#include "CycleQueue.h"
#include <stdlib.h>

// 局部函数声明
// 无

// 接口函数定义
DLL_API PtrQueue InitQueue(void)
{
    PtrQueue queue = (PtrQueue) malloc(sizeof(Queue));
    if (!queue) {
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = 0;
    return queue;
}
// 采用标识相同时队空，留一个位置判断队满的方式
DLL_API bool QueueFull(PtrQueue queue)
{
    return (queue->rear + 1) % MAXSIZE == queue->front;
}
DLL_API bool QueueEmpty(PtrQueue queue)
{
    return queue->rear == queue->front;
}
DLL_API Status EnQueue(PtrQueue queue, PtrElem elem)
{
    if (QueueFull(queue)) {
        return ISFULL;
    }
    CopyElems(&(queue->data[queue->rear]), elem);
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return SUCCESS;
}
DLL_API Status DeQueue(PtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(queue->data[queue->front]));
    queue->front = (queue->front + 1) % MAXSIZE;
    return SUCCESS;
}
DLL_API Status GetHead(PtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(queue->data[queue->front]));
    return SUCCESS;
}
DLL_API void DestroyQueue(PtrQueue queue)
{
    free(queue);
}
DLL_API int Length(PtrQueue queue)
{
    return (queue->rear + MAXSIZE - queue->front) % MAXSIZE;
}
DLL_API void PrintQueue(PtrQueue queue, FILE *out)
{
    int head = queue->front;
    int tail = queue->rear;
    if (!QueueEmpty(queue)) {
        PrintElem(&(queue->data[head]), out);
        head = (head + 1) % MAXSIZE;
        while (head != tail) {
            fprintf(out, " ");
            PrintElem(&(queue->data[head]), out);
            head = (head + 1) % MAXSIZE;
        }
    }
}

// 局部函数定义
// 无