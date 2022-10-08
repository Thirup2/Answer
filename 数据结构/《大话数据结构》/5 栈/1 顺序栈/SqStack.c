/* 顺序栈接口函数文件SqStack.c */

/* 包含头文件 */
#include "SqStack.h"

/* 局部函数原型 */

/*
** 操作: 打印错误信息并退出
** 参数: 发生错误的指针的文本字符串
*/
void printerr(char const *);

/* 数据元素处理函数定义 */

/*
** 操作: 更改数据元素值
** 参数:
** 1. 待更改的数据元素;
** 2. 用于更改的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ChangeElem(ElemType *elem, ElemType const *data)
{
    if (!elem) {
        printerr("待更改元素");
    }
    if (!data) {
        printerr("用于更改的元素");
    }
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素
** 参数:
** 1. 一个即将打印的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void PrintElem(ElemType const *elem)
{
    if (!elem) {
        printerr("待打印元素");
    }
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 顺序栈接口函数定义 */

/*
** 操作: 判断顺序栈是否为空
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若为空则返回true
** 3. 否则返回false
*/
bool StackEmpty(SqStack const *stack)
{
    if (!stack) {
        printerr("顺序栈");
    }
    if (stack->top == -1) {
        return true;
    } else {
        return false;
    }
}

/*
** 操作: 返回栈中元素个数
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 否则返回栈中元素个数
*/
int StackLength(SqStack const *stack)
{
    if (!stack) {
        printerr("顺序栈");
    }
    return stack->top + 1;
}

/*
** 操作: 打印顺序栈的内容
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void PrintStack(SqStack const *stack)
{
    if (!stack) {
        printerr("顺序栈");
    }
    for (int i = 0; i < stack->top + 1; ++i) {
        PrintElem(&(stack->data[i]));
    }
}

/*
** 操作: 初始化顺序栈
** 1. top置为-1
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void InitStack(SqStack *stack)
{
    if (!stack) {
        printerr("顺序栈");
    }
    stack->top = -1;
}

/*
** 操作: 清空栈
** 1. 将top置为-1
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ClearStack(SqStack *stack)
{
    if (!stack) {
        printerr("顺序栈");
    }
    stack->top = -1;
}

/*
** 操作: 销毁栈
** 1. 将top置为-1
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void DestroyStack(SqStack *stack)
{
    if (!stack) {
        printerr("顺序栈");
    }
    stack->top = -1;
}

/*
** 操作: 获取栈顶元素
** 1. 若栈存在且非空, 用elem返回stack的栈顶元素
** 参数:
** 1. 一个顺序栈指针
** 2. 一个用于返回元素的数据元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若顺序栈为空, 返回-1
** 3. 否则执行操作返回0
*/
int GetTop(SqStack const *stack, ElemType *elem)
{
    if (!stack) {
        printerr("顺序栈");
    }
    if (!elem) {
        printerr("待返回数据元素");
    }
    if (StackEmpty(stack)) {
        return -1;
    }
    ChangeElem(elem, &(stack->data[stack->top]));
    return 0;
}

/*
** 操作: 插入元素
** 1. 若栈存在, 插入新元素elem到栈中并成为栈顶元素
** 2. top++
** 参数:
** 1. 一个顺序栈指针
** 2. 一个用于插入的数据元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若顺序栈已满, 返回-1
** 3. 否则执行操作返回0
*/
int Push(SqStack *stack, ElemType const *elem)
{
    if (!stack) {
        printerr("顺序栈");
    }
    if (!elem) {
        printerr("待插入数据元素");
    }
    if (stack->top == MAXSIZE - 1) {
        return -1;
    }
    stack->top++;
    ChangeElem(&(stack->data[stack->top]), elem);
    return 0;
}

/*
** 操作: 删除元素
** 1. 删除栈中栈顶元素, 并用elem返回其值
** 2. top--
** 参数:
** 1. 一个顺序栈指针
** 2. 用于返回值的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若顺序栈为空, 返回-1
** 3. 否则执行操作返回0
*/
int Pop(SqStack *stack, ElemType *elem)
{
    if (!stack) {
        printerr("顺序栈");
    }
    if (!elem) {
        printerr("待返回数据元素");
    }
    if (StackEmpty(stack)) {
        return -1;
    }
    ChangeElem(elem, &(stack->data[stack->top]));
    stack->top--;
    return 0;
}

/* 局部函数定义 */

/*
** 操作: 打印错误信息并退出
** 参数: 发生错误的指针的文本字符串
*/
void printerr(char const *str)
{
    printf("错误: %s指针错误!\n", str);
    exit(EXIT_FAILURE);
}