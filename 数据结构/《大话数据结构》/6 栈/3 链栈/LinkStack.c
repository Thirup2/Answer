/* 链栈接口函数文件LinkStack.c */

/* 包含头文件 */
#include "LinkStack.h"

/* 数据元素处理函数原型 */

/*
** 操作: 赋值操作
** 参数:
** 1. 被赋值元素
** 2. 用于赋值的元素
*/
void CopyElem(ElemType *elem, ElemType *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素
** 参数: 待打印数据元素指针
*/
void PrintElem(ElemType *elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 栈接口函数原型 */

/*
** 操作: 初始化操作, 建立一个空栈
** 返回值: 一个栈指针
*/
PtrStack InitStack(void)
{
    PtrStack stack = (PtrStack) malloc(sizeof(Stack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    stack->length = 0;
    return stack;
}

/*
** 操作: 若栈存在, 则销毁它
** 参数: 栈指针
*/
void DestroyStack(PtrStack stack)
{
    PtrNode p = stack->top;
    PtrNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    free(stack);
}

/*
** 操作: 将栈清空
** 参数: 栈指针
*/
void ClearStack(PtrStack stack)
{
    PtrNode p = stack->top;
    PtrNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    stack->top = NULL;
    stack->length = 0;
}

/*
** 操作: 判断栈是否为空
** 参数: 栈指针
** 返回值:
** 1. 若栈为空, 返回true
** 2. 否则返回false
*/
bool StackEmpty(PtrStack stack)
{
    if (stack->length == 0 && stack->top == NULL) {
        return true;
    }
    return false;
}

/*
** 操作: 若栈存在且非空, 则返回栈顶元素
** 参数:
** 1. 栈指针
** 2. 用于返回元素的指针
** 返回值:
** 1. 若栈为空, 返回-1
** 2. 否则执行操作返回0
*/
int GetTop(PtrStack stack, ElemType *elem)
{
    if (StackEmpty(stack)) {
        return -1;
    }
    CopyElem(elem, &(stack->top->data));
    return 0;
}

/*
** 操作: 若栈存在, 则插入元素到栈顶
** 参数:
** 1. 栈指针
** 2. 用于插入的元素
** 返回值:
** 1. 若栈已满返回-1
** 2. 否则执行操作返回0
*/
int Push(PtrStack stack, ElemType *elem)
{
    PtrNode p = (PtrNode) malloc(sizeof(Node));
    if (!p) {
        return -1;
    }
    p->next = stack->top;
    stack->top = p;
    CopyElem(&(p->data), elem);
    stack->length++;
    return 0;
}

/*
** 操作: 删除栈顶元素并返回其值
** 参数:
** 1. 栈指针
** 2. 用于返回值的元素
** 返回值:
** 1. 若栈为空返回-1
** 2. 否则执行操作返回0
*/
int Pop(PtrStack stack, ElemType *elem)
{
    if (StackEmpty(stack)) {
        return -1;
    }
    CopyElem(elem, &(stack->top->data));
    PtrNode p = stack->top;
    stack->top = p->next;
    free(p);
    stack->length--;
    return 0;
}

/*
** 操作: 返回栈的元素个数
** 参数: 栈指针
** 返回值: 栈的元素个数
*/
int StackLength(PtrStack stack)
{
    return stack->length;
}

/*
** 操作: 打印栈内容
** 参数: 栈指针
*/
void PrintStack(PtrStack stack)
{
    PtrNode p = stack->top;
    while (p) {
        PrintElem(&(p->data));
        p = p->next;
    }
    printf("\n");
}