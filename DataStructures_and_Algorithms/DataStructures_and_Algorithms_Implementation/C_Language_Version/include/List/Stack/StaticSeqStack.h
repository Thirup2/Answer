#ifndef STATICSEQSTACK_H_
#define STATICSEQSTACK_H_

#include "Compatible.h"
#include "ElemType.h"

// ----------------------------------- 头文件 ----------------------------------- //
#include "Status.h"

// ----------------------------------- 接  口 ----------------------------------- //
// 类型定义
#define MAXSIZE 10
typedef struct stack
{
    ElemType data[MAXSIZE];
    int top;
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