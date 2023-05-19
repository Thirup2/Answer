#define EXPORT

#include "SequenceStack.h"
#include <stdlib.h>

// 局部函数声明
static bool StackFull(cPtrShStack stack);

// 接口函数定义
SEQSTACK_API PtrShStack InitStack(void)
{
    PtrShStack stack = (PtrShStack) malloc(sizeof(SharedStack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->top1 = -1;
    stack->top2 = MAXSIZE;
    return stack;
}
SEQSTACK_API bool StackEmpty(cPtrShStack stack, Choice choice)
{
    if (choice == Stack2) {
        return stack->top2 == MAXSIZE;
    } else {
        return stack->top1 == -1;
    }
}
SEQSTACK_API Status Push(PtrShStack stack, cPtrElem elem, Choice choice)
{
    if (StackFull(stack)) {
        return ISFULL;
    }
    if (choice == Stack2) {
        CopyElems(&(stack->data[--stack->top2]), elem);
    } else {
        CopyElems(&(stack->data[++stack->top1]), elem);
    }
    return SUCCESS;
}
SEQSTACK_API Status Pop(PtrShStack stack, PtrElem elem, Choice choice)
{
    if (choice == Stack2) {
        if (StackEmpty(stack, choice)) {
            return ISEMPTY;
        }
        CopyElems(elem, &(stack->data[stack->top2++]));
    } else {
        if (StackEmpty(stack, Stack1)) {
            return ISEMPTY;
        }
        CopyElems(elem, &(stack->data[stack->top1--]));
    }
    return SUCCESS;
}
SEQSTACK_API Status GetTop(cPtrShStack stack, PtrElem elem, Choice choice)
{
    if (choice == Stack2) {
        if (StackEmpty(stack, choice)) {
            return ISEMPTY;
        }
        CopyElems(elem, &(stack->data[stack->top2]));
    } else {
        if (StackEmpty(stack, Stack1)) {
            return ISEMPTY;
        }
        CopyElems(elem, &(stack->data[stack->top1]));
    }
    return SUCCESS;
}
SEQSTACK_API void DestoryStack(PtrShStack stack)
{
    free(stack);
}

// 局部函数定义
static bool StackFull(cPtrShStack stack)
{
    return stack->top1 + 1 == stack->top2;
}