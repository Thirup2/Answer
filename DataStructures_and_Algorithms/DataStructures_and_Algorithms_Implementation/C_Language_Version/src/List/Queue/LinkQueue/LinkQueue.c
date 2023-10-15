#define EXPORT

#include "LinkQueue.h"
#include <stdlib.h>

// 局部函数声明
static PtrNode AllocANode(PtrElem elem);

// 接口函数定义
DLL_API PtrQueue InitQueue(void)
{
    PtrQueue queue = (PtrQueue) malloc(sizeof(Queue));
    if (!queue) {
        exit(EXIT_FAILURE);
    }
    queue->front = queue->rear = NULL;
    queue->length = 0;
    return queue;
}
DLL_API bool QueueEmpty(PtrQueue queue)
{
    return queue->front == NULL;
}
DLL_API Status EnQueue(PtrQueue queue, PtrElem elem)
{
    PtrNode node = AllocANode(elem);
    if (QueueEmpty(queue)) {
        queue->front = queue->rear = node;
    } else {
        queue->rear->toRear = node;
        queue->rear = node;
    }
    queue->length++;
    return SUCCESS;
}
DLL_API Status DeQueue(PtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    if (elem) {
        CopyElems(elem, &(queue->front->data));
    }
    PtrNode del = queue->front;
    if (Length(queue) == 1) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->toRear;
    }
    free(del);
    queue->length--;
    return SUCCESS;
}
DLL_API Status GetHead(PtrQueue queue, PtrElem elem)
{
    if (QueueEmpty(queue)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(queue->front->data));
    return SUCCESS;
}
DLL_API void DestroyQueue(PtrQueue queue)
{
    while (!QueueEmpty(queue)) {
        DeQueue(queue, NULL);
    }
    free(queue);
}
DLL_API int Length(PtrQueue queue)
{
    return queue->length;
}
DLL_API void PrintQueue(PtrQueue queue, FILE *out)
{
    PtrNode travel = queue->front;
    if (travel) {
        PrintElem(&(travel->data), out);
        travel = travel->toRear;
        while (travel) {
            fprintf(out, " ");
            PrintElem(&(travel->data), out);
            travel = travel->toRear;
        }
    }
}

// 局部函数定义
static PtrNode AllocANode(PtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    node->toRear = NULL;
    return node;
}