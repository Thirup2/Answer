#define EXPORT

#include "StaticSeqStack.h"
#include <stdlib.h>

// 局部函数声明
// 无

// 接口函数定义
DLL_API PtrStack InitStack(void)
{
    PtrStack stack = (PtrStack) malloc(sizeof(Stack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    return stack;
}
DLL_API bool StackEmpty(PtrStack stack)
{
    return Length(stack) == 0;
}
DLL_API Status Push(PtrStack stack, PtrElem elem)
{
    if (stack->top == MAXSIZE) {
        return ISFULL;
    }
    CopyElems(&(stack->data[stack->top]), elem);
    stack->top++;
    return SUCCESS;
}
DLL_API Status Pop(PtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    stack->top--;
    CopyElems(elem, &(stack->data[stack->top]));
    return SUCCESS;
}
DLL_API Status GetTop(PtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(stack->data[stack->top - 1]));
    return SUCCESS;
}
DLL_API void DestroyStack(PtrStack stack)
{
    free(stack);
}
DLL_API int Length(PtrStack stack)
{
    return stack->top;
}
DLL_API void PrintStack(PtrStack stack, FILE *out)
{
    int i = 0;
    if (i < stack->top) {
        PrintElem(&(stack->data[i]), out);
        i++;
        while(i<stack->top) {
            fprintf(out, " ");
            PrintElem(&(stack->data[i]), out);
            i++;
        }
    }
}

// 局部函数定义
// 无