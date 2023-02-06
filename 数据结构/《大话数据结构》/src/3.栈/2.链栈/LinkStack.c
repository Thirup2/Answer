#define EXPORT
#include "LinkStack.h"
#include <stdlib.h>
#include <stdio.h>

/* 接口实现 */

/*
** 操作：初始化顺序栈
** 返回值：初始化后的顺序栈指针
*/
PtrStack DLL_CALL InitStack(void)
{
    PtrStack stack = (PtrStack) malloc(sizeof(Stack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
}

/*
** 操作：销毁栈
** 参数：栈
*/
void DLL_CALL DestroyStack(PtrStack stack)
{
    ClearStack(stack);
    free(stack);
}

/*
** 操作：清空栈
** 参数：栈
*/
void DLL_CALL ClearStack(PtrStack stack)
{
    PtrNode p = stack->top;
    PtrNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    stack->top = NULL;
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
    AssignElem(elem, &stack->top->data);
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
    PtrNode now = (PtrNode) malloc(sizeof(Node));
    if (!now) {
        exit(EXIT_FAILURE);
    }
    AssignElem(&now->data, elem);
    now->next = stack->top;
    stack->top = now;
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
    AssignElem(elem, &stack->top->data);
    PtrNode p = stack->top;
    stack->top = p->next;
    free(p);
    return SUCCESS;
}

/*
** 操作：返回栈长
** 参数：栈
** 返回值：栈长
*/
size_t DLL_CALL StackLenth(cPtrStack stack)
{
    PtrNode p = stack->top;
    size_t i = 0;
    while (p) {
        i++;
        p = p->next;
    }
    return i;
}

/*
** 操作：从栈顶到栈底打印所有元素
** 参数：栈
*/
void DLL_CALL PrintStack(cPtrStack stack)
{
    PtrNode p = stack->top;
    while (p) {
        PrintElem(&p->data);
        p = p->next;
    }
    printf("\n");
}