/* 两栈共享空间接口头文件SqDulStack.h */
#ifndef _SQDULSTACK_H_
#define _SQDULSTACK_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 数据类型定义 */
struct items
{
    int x;
    int y;
};
typedef struct items ElemType;

struct stack
{
    ElemType *data;
    int size;
    int top1;
    int top2;
};
typedef struct stack Stack;
typedef Stack *PtrStack;

typedef int StackChoice;
#define STACK1 1
#define STACK2 2

/* 数据元素处理函数原型 */

/*
** 操作: 赋值元素到第一个参数
** 参数:
** 1. 待赋值的参数
** 2. 用于赋值的参数
*/
void CopyElem(ElemType *elem, ElemType *data);

/* 两站共享空间函数原型 */

/*
** 操作: 初始化栈
** 参数: 栈大小
** 返回值: 栈指针
*/
PtrStack InitStack(int const size);

/*
** 操作: 销毁栈
** 参数: 栈指针
*/
void DestroyStack(PtrStack stack);

/*
** 操作: 清空某个栈
** 参数:
** 1. 栈指针
** 2. 选择栈
*/
void ClearStack(PtrStack stack, StackChoice choice);

/*
** 操作: 判断某个栈是否为空
** 参数:
** 1. 栈指针
** 2. 栈选择
** 返回值:
** 1. 若为空返回true
** 2. 否则返回false
*/
bool StackEmpty(PtrStack stack, StackChoice choice);

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
int GetTop(PtrStack stack, StackChoice choice, ElemType *elem);

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
int Push(PtrStack stack, StackChoice choice, ElemType *elem);

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
int Pop(PtrStack stack, StackChoice choice, ElemType *elem);

/*
** 操作: 返回栈长
** 参数:
** 1. 栈指针
** 2. 栈选择
** 返回值:
** 1. 若栈为空返回0
** 2. 否则返回栈长
*/
int StackLength(PtrStack stack, StackChoice choice);

/*
** 操作: 打印栈内容
** 参数:
** 1. 栈指针
** 2. 栈选择
*/
void PrintStack(PtrStack stack, StackChoice choice);

#endif