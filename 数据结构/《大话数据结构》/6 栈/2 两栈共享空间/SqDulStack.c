/* 两栈共享空间接口函数文件SqDulStack.c */

/* 包含头文件 */
#include "SqDulStack.h"

/* 数据元素处理函数定义 */

/*
** 操作: 赋值元素到第一个参数
** 参数:
** 1. 待赋值的参数
** 2. 用于赋值的参数
*/
void CopyElem(ElemType *elem, ElemType *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/* 两栈共享空间函数定义 */

/*
** 操作: 初始化栈
** 参数: 栈大小
** 返回值: 栈指针
*/
PtrStack InitStack(int const size)
{
    PtrStack stack = (PtrStack) malloc(sizeof(Stack));
    if (!stack) {
        exit(EXIT_FAILURE);
    }
    stack->data = (ElemType *) malloc(size * sizeof(ElemType));
    if (!stack->data) {
        exit(EXIT_FAILURE);
    }
    stack->size = size;
    stack->top1 = -1;
    stack->top2 = size;
    return stack;
}

/*
** 操作: 销毁栈
** 参数: 栈指针
*/
void DestroyStack(PtrStack stack)
{
    free(stack->data);
    free(stack);
}

/*
** 操作: 清空某个栈
** 参数:
** 1. 栈指针
** 2. 选择栈
*/
void ClearStack(PtrStack stack, StackChoice choice)
{
    if (choice == STACK1) {
        stack->top1 = -1;
    }
    if (choice == STACK2) {
        stack->top2 = stack->size;
    }
}

/*
** 操作: 判断某个栈是否为空
** 参数:
** 1. 栈指针
** 2. 栈选择
** 返回值:
** 1. 若为空返回true
** 2. 否则返回false
*/
bool StackEmpty(PtrStack stack, StackChoice choice)
{
    if (choice == STACK1) {
        if (stack->top1 == -1) {
            return true;
        }
    } else if (choice == STACK2) {
        if (stack->top2 == stack->size) {
            return true;
        }
    }
    return false;
}

/*
** 操作: 返回某个栈栈顶元素
** 参数:
** 1. 栈指针
** 2. 栈选择
** 3. 用于返回的指针
** 返回值:
** 1. 若栈为空返回-1
** 2. 否则执行操作返回0
*/
int GetTop(PtrStack stack, StackChoice choice, ElemType *elem)
{
    if (StackEmpty(stack, choice)) {
        return -1;
    }
    if (choice == STACK1) {
        CopyElem(elem, &(stack->data[stack->top1]));
    } else if (choice == STACK2) {
        CopyElem(elem, &(stack->data[stack->top2]));
    }
    return 0;
}

/*
** 操作: 入栈操作
** 参数:
** 1. 栈指针
** 2. 栈选择
** 3. 用于插入的元素
** 返回值:
** 1. 若栈已满返回-1
** 2. 否则执行操作返回0
*/
int Push(PtrStack stack, StackChoice choice, ElemType *elem)
{
    if (stack->top1 + 1 == stack->top2) {
        return -1;
    }
    if (choice == STACK1) {
        CopyElem(&(stack->data[++stack->top1]), elem);
    } else if (choice == STACK2) {
        CopyElem(&(stack->data[--stack->top2]), elem);
    }
    return 0;
}

/*
** 操作: 出栈操作
** 参数:
** 1. 栈指针
** 2. 栈选择
** 3. 用于返回的元素
** 返回值:
** 1. 若栈为空返回-1
** 2. 否则执行操作返回0
*/
int Pop(PtrStack stack, StackChoice choice, ElemType *elem)
{
    if (StackEmpty(stack, choice)) {
        return -1;
    }
    if (choice == STACK1) {
        CopyElem(elem, &(stack->data[stack->top1--]));
    } else if (choice == STACK2) {
        CopyElem(elem, &(stack->data[stack->top2++]));
    }
    return 0;
}

/*
** 操作: 返回栈长
** 参数:
** 1. 栈指针
** 2. 栈选择
** 返回值:
** 1. 若栈为空返回0
** 2. 否则返回栈长
*/
int StackLength(PtrStack stack, StackChoice choice)
{
    if (choice == STACK1) {
        return stack->top1 + 1;
    } else if (choice == STACK2) {
        return stack->size - stack->top2;
    }
}

/*
** 操作: 打印栈内容
** 参数:
** 1. 栈指针
** 2. 栈选择
*/
void PrintStack(PtrStack stack, StackChoice choice)
{
    if (choice == STACK1) {
        for (int i = 0; i <= stack->top1; i++) {
            printf("(%d, %d) ", stack->data[i].x, stack->data[i].y);
        }
    } else if (choice == STACK2) {
        for (int i = stack->size - 1; i >= stack->top2; i--) {
            printf("(%d, %d) ", stack->data[i].x, stack->data[i].y);
        }
    }
    printf("\n");
}