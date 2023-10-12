#define EXPORT

#include "LinkStack.h"
#include <stdlib.h>

// 局部函数声明
static PtrNode AllocNode(PtrElem elem);

// 接口函数定义
DLL_API PtrStack InitStack(void);
DLL_API bool StackEmpty(PtrStack stack);
DLL_API Status Push(PtrStack stack, PtrElem elem);
DLL_API Status Pop(PtrStack stack, PtrElem elem);
DLL_API Status GetTop(PtrStack stack, PtrElem elem);
DLL_API void DestroyStack(PtrStack stack);
DLL_API int Length(PtrStack stack);
DLL_API void PrintStack(PtrStack stack, FILE *out);

// 局部函数定义