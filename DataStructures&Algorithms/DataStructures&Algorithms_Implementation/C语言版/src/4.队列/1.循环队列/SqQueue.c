#define EXPORT

#include "SqQueue.h"
#include <stdlib.h>

// 接口函数定义
SQQUEUE_API PtrSqQueue InitQueue(void)
{
    PtrSqQueue queue = (PtrSqQueue) malloc(sizeof(SqQueue));
    if (!queue) {
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = 0;
    return queue;
}
SQQUEUE_API bool QueueEmpty(cPtrSqQueue queue)
{
    return queue->front == queue->rear;
}
SQQUEUE_API Status EnQueue(PtrSqQueue queue, cPtrElem elem)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front) {
        return ISFULL;
    }
    CopyElems(&(queue->data[queue->rear]), elem);
    queue->rear = (queue->rear + 1) % MAXSIZE;
    return SUCCESS;
}
SQQUEUE_API Status DeQueue(PtrSqQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(queue->data[queue->front]));
    queue->front = (queue->front + 1) % MAXSIZE;
    return SUCCESS;
}
SQQUEUE_API Status GetHead(cPtrSqQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(queue->data[queue->front]));
    return SUCCESS;
}