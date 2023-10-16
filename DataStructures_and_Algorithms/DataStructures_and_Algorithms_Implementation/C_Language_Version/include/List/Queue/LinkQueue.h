#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

#include "Compatible.h"
#include "ElemType.h"

// --------------------------------------- 头文件 --------------------------------------- //
#include "Status.h"

// --------------------------------------- 接 口 --------------------------------------- //
// 数据类型定义
typedef struct node
{
    ElemType data;
    struct node *toRear;
} Node, *PtrNode;
typedef struct queue
{
    PtrNode front;
    PtrNode rear;
    int length;
} Queue, *PtrQueue;

// 函数接口
DLL_API PtrQueue InitQueue(void);
DLL_API bool QueueEmpty(PtrQueue queue);
DLL_API Status EnQueue(PtrQueue queue, PtrElem elem);
DLL_API Status DeQueue(PtrQueue queue, PtrElem elem);
DLL_API Status GetHead(PtrQueue queue, PtrElem elem);
DLL_API void DestroyQueue(PtrQueue queue);
DLL_API int Length(PtrQueue queue);
DLL_API void PrintQueue(PtrQueue queue, FILE *out);

#endif