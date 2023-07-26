#define EXPORT

#include "LinkStack.h"
#include <stdlib.h>

// 接口函数定义
LINKSTACK_API LinkStack InitStack(void)
{
    LinkStack stack = (PtrNode) malloc(sizeof(Node));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->next = NULL;
    return stack;
}
LINKSTACK_API bool StackEmpty(LinkStack stack)
{
    return stack->next == NULL;
}
LINKSTACK_API Status Push(LinkStack stack, cPtrElem elem)
{
    PtrNode now = (PtrNode) malloc(sizeof(Node));
    if (!now) {
        exit(EXIT_FAILURE);
    }
    CopyElems(&(now->data), elem);
    now->next = stack->next;
    stack->next = now;
    return SUCCESS;
}
LINKSTACK_API Status Pop(LinkStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(stack->next->data));
    PtrNode del = stack->next;
    stack->next = del->next;
    free(del);
    return SUCCESS;
}
LINKSTACK_API Status GetTop(LinkStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    CopyElems(elem, &(stack->next->data));
    return SUCCESS;
}
LINKSTACK_API void DestroyStack(LinkStack stack)
{
    PtrNode now = stack;
    PtrNode del;
    while (now) {
        del = now;
        now = now->next;
        free(del);
    }
}