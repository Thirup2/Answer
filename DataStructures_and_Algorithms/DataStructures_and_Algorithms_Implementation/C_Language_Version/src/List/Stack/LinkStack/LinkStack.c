#define EXPORT

#include "LinkStack.h"
#include <stdlib.h>

// 局部函数声明
static PtrNode AllocNode(PtrElem elem);

// 接口函数定义
DLL_API PtrStack InitStack(void)
{
    PtrStack stack = (PtrStack) malloc(sizeof(Stack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->length = 0;
    return stack;
}
DLL_API bool StackEmpty(PtrStack stack)
{
    return stack->top == NULL;
}
DLL_API Status Push(PtrStack stack, PtrElem elem)
{
    PtrNode node = AllocNode(elem);
    node->toBottom = stack->top;
    stack->top = node;
    stack->length++;
    return SUCCESS;
}
DLL_API Status Pop(PtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    if (elem) {
        CopyElems(elem, &(stack->top->data));
    }
    PtrNode del = stack->top;
    stack->top = del->toBottom;
    free(del);
    stack->length--;
    return SUCCESS;
}
DLL_API Status GetTop(PtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(stack->top->data));
    return SUCCESS;
}
DLL_API void DestroyStack(PtrStack stack)
{
    while (!StackEmpty(stack)) {
        Pop(stack, NULL);
    }
    free(stack);
}
DLL_API int Length(PtrStack stack)
{
    return stack->length;
}
DLL_API void PrintStack(PtrStack stack, FILE *out)
{
    PtrStack save = InitStack();
    ElemType elem;
    PtrNode travel = stack->top;
    while (travel) {
        CopyElems(&elem, &(travel->data));
        Push(save, &elem);
        travel = travel->toBottom;
    }
    travel = save->top;
    if (travel) {
        PrintElem(&(travel->data), out);
        travel = travel->toBottom;
        while (travel) {
            fprintf(out, " ");
            PrintElem(&(travel->data), out);
            travel = travel->toBottom;
        }
    }
    DestroyStack(save);
}

// 局部函数定义
static PtrNode AllocNode(PtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    node->toBottom = NULL;
    return node;
}