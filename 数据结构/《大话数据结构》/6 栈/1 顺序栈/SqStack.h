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
    int length;
};
typedef struct stack Stack;
typedef Stack *PtrStack;

/* 数据元素处理函数原型 */

/*
** 操作: 赋值操作
** 参数:
** 1. 被赋值元素
** 2. 用于赋值的元素
*/
void CopyElem(ElemType *elem, ElemType *data);

/*
** 操作: 打印一个数据元素
** 参数: 待打印数据元素指针
*/
void PrintElem(ElemType *elem);

/* 栈接口函数原型 */

/*
** 操作: 初始化操作, 建立一个空栈
** 返回值: 一个栈指针
*/
PtrStack InitStack(void);

/*
** 操作: 若栈存在, 则销毁它
** 参数: 栈指针
*/
void DestroyStack(PtrStack stack);

/*
** 操作: 将栈清空
** 参数: 栈指针
*/
void ClearStack(PtrStack stack);

/*
** 操作: 判断栈是否为空
** 参数: 栈指针
** 返回值:
** 1. 若栈为空, 返回true
** 2. 否则返回false
*/
bool StackEmpty(PtrStack stack);

/*
** 操作: 若栈存在且非空, 则返回栈顶元素
** 参数:
** 1. 栈指针
** 2. 用于返回元素的指针
** 返回值:
** 1. 若栈为空, 返回-1
** 2. 否则执行操作返回0
*/
int GetTop(PtrStack stack, ElemType *elem);

/*
** 操作: 若栈存在, 则插入元素到栈顶
** 参数:
** 1. 栈指针
** 2. 用于插入的元素
** 返回值:
** 1. 若栈已满返回-1
** 2. 否则执行操作返回0
*/
int Push(PtrStack stack, ElemType *elem);

/*
** 操作: 删除栈顶元素并返回其值
** 参数:
** 1. 栈指针
** 2. 用于返回值的元素
** 返回值:
** 1. 若栈为空返回-1
** 2. 否则执行操作返回0
*/
int Pop(PtrStack stack, ElemType *elem);

/*
** 操作: 返回栈的元素个数
** 参数: 栈指针
** 返回值: 栈的元素个数
*/
int StackLength(PtrStack stack);

/*
** 操作: 打印栈内容
** 参数: 栈指针
*/
void PrintStack(PtrStack stack);

#endif