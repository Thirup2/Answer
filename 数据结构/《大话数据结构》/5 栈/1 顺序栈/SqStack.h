/* 顺序栈接口头文件SqStack.h */
#ifndef _SQSTACK_H_
#define _SQSTACK_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 数据类型定义 */
struct items
{
    int x;
    int y;
};
typedef struct items ElemType;
#define MAXSIZE 20
struct stack
{
    ElemType data[MAXSIZE];
    int top;
};
typedef struct stack SqStack;

/* 数据元素处理函数原型 */

/*
** 操作: 更改数据元素值
** 参数:
** 1. 待更改的数据元素;
** 2. 用于更改的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ChangeElem(ElemType *elem, ElemType const *data);

/*
** 操作: 打印一个数据元素
** 参数:
** 1. 一个即将打印的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void PrintElem(ElemType const *elem);

/* 顺序栈函数定义原型 */

/*
** 操作: 判断顺序栈是否为空
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 若为空则返回true
** 3. 否则返回false
*/
bool StackEmpty(SqStack const *stack);

/*
** 操作: 返回栈中元素个数
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 否则返回栈中元素个数
*/
int StackLength(SqStack const *stack);

/*
** 操作: 打印顺序栈的内容
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void PrintStack(SqStack const *stack);

/*
** 操作: 初始化顺序栈
** 1. top置为-1
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void InitStack(SqStack *stack);

/*
** 操作: 清空栈
** 1. 将top置为-1
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ClearStack(SqStack *stack);

/*
** 操作: 销毁栈
** 1. 将top置为-1
** 参数:
** 1. 一个顺序栈指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void DestroyStack(SqStack *stack);

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
int GetTop(SqStack const *stack, ElemType *elem);

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
int Push(SqStack *stack, ElemType const *elem);

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
int Pop(SqStack *stack, ElemType *elem);

#endif