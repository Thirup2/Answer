/* 链栈接口函数文件LinkStack.c */

/* 包含头文件 */
#include "LinkStack.h"

/* 元素处理函数定义 */

/*
** 操作: 更改数据元素的值
** 参数:
** 1. 待更改的元素指针
** 2. 用于更改的元素指针
*/
void ChangeElem(ElemType *elem, ElemType const *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素
*/
void PrintElem(ElemType const *elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 链栈接口函数定义 */

/*
** 操作: 判断链栈是否为空
** 参数: 链栈指针
** 返回值:
** 1. 若链栈为空, 则返回true
** 2. 若链栈非空, 则返回false
*/
bool StackEmpty(LinkStack const *stack)
{
    if (stack->top == NULL && stack->length == 0) {
        return true;
    }
    return false;
}

/*
** 操作: 获取链栈的元素个数
** 参数: 链栈指针
** 返回值: 链栈的元素个数
*/
int StackLength(LinkStack const *stack)
{
    return stack->length;
}

/*
** 操作: 打印链栈所有元素
** 参数: 链栈指针
*/
void ShowStack(LinkStack const *stack)
{
    PNode p = stack->top;
    while (p) {
        PrintElem(&(p->data));
    }
}

/*
** 操作: 初始化操作
** 1. 栈顶指针设置为空
** 2. 链栈长度设置为0
** 参数: 链栈指针
*/
void InitStack(LinkStack *stack)
{
    stack->top = NULL;
    stack->length = 0;
}

/*
** 操作: 插入新元素到栈顶
** 1. 新建结点: 数据域用参数二填充, 指针域指向上一个栈顶
** 2. 栈顶指针指向新结点
** 3. 链栈长度加1
** 参数:
** 1. 链栈指针
** 2. 用于插入的数据元素指针
** 返回值:
** 1. 若链栈已满返回-1
** 2. 若插入成功返回0
*/
int Push(LinkStack *stack, ElemType const *elem)
{
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        return -1;
    }
    ChangeElem(&(p->data), elem);
    p->next = stack->top;
    stack->top = p;
    stack->length++;
    return 0;
}

/*
** 操作: 删除栈顶元素
** 1. 将栈顶元素交给用于返回的元素指针
** 2. 栈顶指针指向后一个结点
** 3. 链栈长度减1
** 4. 释放被删除结点
** 参数:
** 1. 链栈指针
** 2. 用于返回的数据元素指针
** 返回值:
** 1. 若链栈为空返回-1
** 2. 若删除成功返回0
*/
int Pop(LinkStack *stack, ElemType *elem)
{
    if (StackEmpty(stack)) {
        return -1;
    }
    PNode p = stack->top;
    ChangeElem(elem, &(p->data));
    stack->top = p->next;
    stack->length--;
    free(p);
    return 0;
}

/*
** 操作: 获取栈顶元素
** 参数:
** 1. 链栈指针
** 2. 用于返回的数据元素指针
** 返回值:
** 1. 若链栈为空返回-1
** 2. 返回成功返回0
*/
int GetTop(LinkStack const *stack, ElemType *elem)
{
    if (StackEmpty(stack)) {
        return -1;
    }
    ChangeElem(elem, &(stack->top->data));
    return 0;
}

/*
** 操作: 清空链栈
** 1. 将所有结点空间释放, 仅保留头结点(本例未设置头结点)
** 2. 栈顶指针指向头结点
** 3. 链栈长度设置为0
** 参数: 链栈指针
*/
void ClearStack(LinkStack *stack)
{
    PNode p = stack->top;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    stack->top = NULL;
    stack->length = 0;
}

/*
** 操作: 销毁链栈
** 1. 将所有结点空间释放, 包括头结点
** 2. 栈顶指针指向NULL
** 3. 链栈长度设置为0
** 参数: 链栈指针
*/
void DestroyStack(LinkStack *stack)
{
    PNode p = stack->top;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    stack->top = NULL;
    stack->length = 0;
}