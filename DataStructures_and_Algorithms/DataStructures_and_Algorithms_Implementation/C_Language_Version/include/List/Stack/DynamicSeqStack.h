#ifndef DYNAMICSEQSTACK_H_
#define DYNAMICSEQSTACK_H_

#include "Compatible.h"

// ---------------------------------------- 头文件 ---------------------------------------- //
#include "Coords.h"
#include "Status.h"

// ---------------------------------------- 接  口 ---------------------------------------- //
// 数据元素类型
typedef Coords ElemType;
typedef PtrCoords PtrElem;
#define MakeElem MakeCoords
#define CreateElem CreateCoords
#define DestroyElem DestroyCoords
#define CopyElems CopyCoords
#define EqualElems EqualCoords
#define PrintElem PrintCoords
#define ReadElem ReadCoords

// 数据类型定义
#define INITSIZE 10
typedef struct stack
{
    PtrElem data;
    int top;
    int capacity;
}Stack, *PtrStack;

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