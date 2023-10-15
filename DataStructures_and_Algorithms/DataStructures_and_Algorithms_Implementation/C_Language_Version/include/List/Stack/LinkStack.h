#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include "Compatible.h"
#include "ElemType.h"

// -------------------------------------- 头文件 -------------------------------------- //
#include "Status.h"

// -------------------------------------- 接  口 -------------------------------------- //
// 数据类型定义
typedef struct node
{
    ElemType data;
    struct node *toBottom;
} Node, *PtrNode;
typedef struct stack
{
    PtrNode top;
    int length;
} Stack, *PtrStack;

// 函数接口
DLL_API PtrStack InitStack(void);
DLL_API bool StackEmpty(PtrStack stack);
DLL_API Status Push(PtrStack stack, PtrElem elem);
DLL_API Status Pop(PtrStack stack, PtrElem elem);
DLL_API Status GetTop(PtrStack stack, PtrElem elem);
DLL_API void DestroyStack(PtrStack stack);
DLL_API int Length(PtrStack stack);
DLL_API void PrintStack(PtrStack stack, FILE *out);

#endif