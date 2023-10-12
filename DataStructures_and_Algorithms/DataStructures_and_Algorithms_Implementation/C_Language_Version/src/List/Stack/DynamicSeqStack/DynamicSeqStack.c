#define EXPORT

#include "DynamicSeqStack.h"
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
    stack->capacity = INITSIZE;
    stack->data = (PtrElem) malloc(stack->capacity * sizeof(ElemType));
    if (!stack->data) {
        exit(EXIT_FAILURE);
    }
    return stack;
}
DLL_API bool StackEmpty(PtrStack stack)
{
    return Length(stack) == 0;
}
DLL_API Status Push(PtrStack stack, PtrElem elem)
{
    if (Length(stack) == stack->capacity) {
        stack->capacity *= 2;
        stack->data = (PtrElem) realloc(stack->data, stack->capacity * sizeof(ElemType));
        if (!stack->data) {
            exit(EXIT_FAILURE);
        }
    }
    CopyElems(&(stack->data[stack->top++]), elem);
    return SUCCESS;
}
DLL_API Status Pop(PtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(stack->data[--stack->top]));
    if (stack->top < stack->capacity / 2 && stack->capacity > INITSIZE) {
        stack->capacity /= 2;
        stack->data = (PtrElem) realloc(stack->data, stack->capacity * sizeof(ElemType));
        if (!stack->data) {
            exit(EXIT_FAILURE);
        }
    }
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
    free(stack->data);
    free(stack);
}
DLL_API int Length(PtrStack stack)
{
    return stack->top;
}
DLL_API void PrintStack(PtrStack stack, FILE *out)
{
    int i = 0;
    if (i < Length(stack)) {
        PrintElem(&(stack->data[i++]), out);
        while (i < Length(stack)) {
            fprintf(out, " ");
            PrintElem(&(stack->data[i++]), out);
        }
    }
}

// 局部函数定义
// 无