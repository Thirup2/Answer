#define EXPORT
#include "SeqStack.h"
#include <stdio.h>
#include <stdlib.h>

/* 接口实现 */

/*
** 操作：初始化顺序栈
** 参数：需要的栈长
** 返回值：初始化后的顺序栈指针
*/
PtrStack DLL_CALL InitStack(size_t size)
{
    PtrStack stack = (PtrStack) malloc(sizeof(Stack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->size = size;
    stack->data = (PtrElem) malloc(size * sizeof(ElemType));
    if (!stack->data) {
        exit(EXIT_FAILURE);
    }
    stack->top = 0;
    return stack;
}

/*
** 操作：销毁栈
** 参数：栈
*/
void DLL_CALL DestroyStack(PtrStack stack)
{
    free(stack->data);
    free(stack);
}

/*
** 操作：清空栈
** 参数：栈
*/
void DLL_CALL ClearStack(PtrStack stack)
{
    stack->top = 0;
}

/*
** 操作：判断栈是否为空
** 参数：栈
** 返回值：true or false
*/
bool DLL_CALL StackEmpty(cPtrStack stack)
{
    if (StackLenth(stack) == 0) {
        return true;
    }
    return false;
}

/*
** 操作：访问栈顶元素
** 参数：
** 1. 栈
** 2. 返回栈顶元素的指针
** 返回值：
** 1. 若栈为空，返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status DLL_CALL GetTop(cPtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    AssignElem(elem, &stack->data[stack->top - 1]);
    return SUCCESS;
}

/*
** 操作：压栈
** 参数：
** 1. 栈
** 2. 待压栈元素
** 返回值：
** 1. 若栈已满，返回ISFULL
** 2. 否则执行操作返回SUCCESS
*/
Status DLL_CALL Push(PtrStack stack, cPtrElem elem)
{
    if (StackLenth(stack) == stack->size) {
        return ISFULL;
    }
    AssignElem(&stack->data[stack->top++], elem);
    return SUCCESS;
}

/*
** 操作：弹栈
** 参数：
** 1. 栈
** 2. 被弹栈元素
** 返回值：
** 1. 若栈为空，返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
Status DLL_CALL Pop(PtrStack stack, PtrElem elem)
{
    if (StackEmpty(stack)) {
        return ISEMPTY;
    }
    AssignElem(elem, &stack->data[--stack->top]);
    return SUCCESS;
}

/*
** 操作：返回栈长
** 参数：栈
** 返回值：栈长
*/
size_t DLL_CALL StackLenth(cPtrStack stack)
{
    return stack->top;
}

/*
** 操作：从栈顶到栈底打印所有元素
** 参数：栈
*/
void DLL_CALL PrintStack(cPtrStack stack)
{
    for (size_t i = stack->top; i > 0; i--) {
        PrintElem(&stack->data[i - 1]);
    }
    printf("\n");
}