/* 两栈共享空间接口函数文件SqDulStack.c */

/* 包含头文件 */
#include "SqDulStack.h"

/* 局部函数原型 */

/*
** 操作: 打印错误信息并退出
*/
void PrintError(void *ptr, char const *error);

/* 数据元素处理函数定义 */

/*
** 操作: 更改一个数据元素的值
** 参数:
** 1. 待更改的数据元素指针
** 2. 用于更改的数据元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ChangeElem(ElemType *data, ElemType const *elem)
{
    PrintError(data, "待更改");
    PrintError(elem, "用于更改的");
    data->x = elem->x;
    data->y = elem->y;
}

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素指针
** 返回值: 若参数指针错误则打印错误信息并退出
*/
void PrintElem(ElemType const *elem)
{
    PrintError(elem, "待打印");
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 两栈共享空间接口函数定义 */

/*
** 操作: 判断某栈是否为空
** 参数:
** 1. 双栈的指针
** 2. 待查的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若待查栈为空则返回true
** 3. 否则返回false
*/
bool StackEmpty(SqDulStack const *stack, CHSTACK choice)
{
    PrintError(stack, "双栈");
    if (choice == STACK1) {
        if (stack->top1 == -1) {
            return true;
        }
    } else if (choice == STACK2) {
        if (stack->top2 == MAXSIZE) {
            return true;
        }
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
    return false;
}

/*
** 操作: 返回某栈的元素个数
** 参数:
** 1. 双栈的指针
** 2. 待查的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 否则返回栈的元素个数
*/
int StackLength(SqDulStack const *stack, CHSTACK choice)
{
    PrintError(stack, "双栈");
    if (choice == STACK1) {
        return stack->top1 + 1;
    } else if (choice == STACK2) {
        return MAXSIZE - stack->top2;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
}

/*
** 操作: 打印某栈的数据元素
** 参数:
** 1. 双栈的指针
** 2. 待查的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ShowStack(SqDulStack const *stack, CHSTACK choice)
{
    PrintError(stack, "双栈");
    int end;
    int i;
    if (choice == STACK1) {
        i = 0;
        end = stack->top1;
    } else if (choice == STACK2) {
        i = MAXSIZE - 1;
        end = stack->top2;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
    while (i <= end) {
        PrintElem(&(stack->data[i]));
        i++;
    }
    printf("\n");
}

/*
** 操作: 初始化某栈
** 参数:
** 1. 双栈的指针
** 2. 待初始化的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void InitStack(SqDulStack *stack, CHSTACK choice)
{
    PrintError(stack, "双栈");
    if (choice == STACK1) {
        stack->top1 = -1;
    } else if (choice == STACK2) {
        stack->top2 = MAXSIZE;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
}

/*
** 操作:
** 1. 插入元素到某栈栈顶
** 2. 被插入栈更改栈顶指针
** 参数:
** 1. 双栈的指针
** 2. 待插入的数据元素指针
** 3. 待插入的栈序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若栈已满, 则返回-1
** 3. 若插入成功, 则返回0
*/
int Push(SqDulStack *stack, ElemType const *elem, CHSTACK choice)
{
    PrintError(stack, "双栈");
    PrintError(elem, "待插入元素");
    if (stack->top1 + 1 == stack->top2) {
        return -1;
    }
    if (choice == STACK1) {
        ChangeElem(&(stack->data[stack->top1 + 1]), elem);
        stack->top1++;
    } else if (choice == STACK2) {
        ChangeElem(&(stack->data[stack->top2 - 1]), elem);
        stack->top2--;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

/*
** 操作:
** 1. 删除栈顶元素
** 2. 用elem返回其值
** 3. 更改被删除栈的栈顶指针
** 参数:
** 1. 双栈的指针
** 2. 用于返回的数据元素指针
** 3. 待删除的栈序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若栈为空, 则返回-1
** 3. 若删除成功, 则返回0
*/
int Pop(SqDulStack *stack, ElemType *elem, CHSTACK choice)
{
    PrintError(stack, "双栈");
    PrintError(elem, "待返回元素");
    if (StackEmpty(stack, choice)) {
        return -1;
    }
    if (choice == STACK1) {
        ChangeElem(elem, &(stack->data[stack->top1]));
        stack->top1--;
    } else if (choice == STACK2) {
        ChangeElem(elem, &(stack->data[stack->top2]));
        stack->top2++;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

/*
** 操作: 用elem返回某栈的栈顶元素
** 参数:
** 1. 双栈的指针
** 2. 用于返回的数据元素指针
** 3. 待查找的栈序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若栈为空, 则返回-1
** 3. 若返回成功, 则返回0
*/
int GetTop(SqDulStack const *stack, ElemType *elem, CHSTACK choice)
{
    PrintError(stack, "双栈");
    PrintError(elem, "待返回的元素");
    if (StackEmpty(stack, choice)) {
        return -1;
    }
    if (choice == STACK1) {
        ChangeElem(elem, &(stack->data[stack->top1]));
    } else if (choice == STACK2) {
        ChangeElem(elem, &(stack->data[stack->top2]));
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
}

/*
** 操作:
** 1. 清空某栈
** 2. 更改该栈栈顶指针
** 参数:
** 1. 双栈的指针
** 2. 待清空的栈序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ClearStack(SqDulStack *stack, CHSTACK choice)
{
    PrintError(stack, "双栈");
    if (choice == STACK1) {
        stack->top1 = -1;
    } else if (choice == STACK2) {
        stack->top2 = MAXSIZE;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
}

/*
** 操作:
** 1. 销毁某栈
** 2. 更改该栈栈顶指针
** 参数:
** 1. 双栈的指针
** 2. 待销毁的栈序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void DestroyStack(SqDulStack *stack, CHSTACK choice)
{
    PrintError(stack, "双栈");
    if (choice == STACK1) {
        stack->top1 = -1;
    } else if (choice == STACK2) {
        stack->top2 = MAXSIZE;
    } else {
        printf("栈序号错误!\n");
        exit(EXIT_FAILURE);
    }
}

/* 局部函数定义 */

/*
** 操作: 打印错误信息并退出
*/
void PrintError(void *ptr, char const *error)
{
    if (!ptr) {
        printf("错误: %s指针错误!\n", error);
        exit(EXIT_FAILURE);
    }
}