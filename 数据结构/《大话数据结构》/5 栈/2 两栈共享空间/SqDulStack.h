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
#define MAXSIZE 40
struct stack
{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
};
typedef struct stack SqDulStack;
typedef int CHSTACK;
#define STACK1 1
#define STACK2 2

/* 数据元素处理函数原型 */

/*
** 操作: 更改一个数据元素的值
** 参数:
** 1. 待更改的数据元素指针
** 2. 用于更改的数据元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ChangeElem(ElemType *data, ElemType const *elem);

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素指针
** 返回值: 若参数指针错误则打印错误信息并退出
*/
void PrintElem(ElemType const *elem);

/* 两栈共享空间接口函数原型 */

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
bool StackEmpty(SqDulStack const *stack, CHSTACK choice);

/*
** 操作: 返回某栈的元素个数
** 参数:
** 1. 双栈的指针
** 2. 待查的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
** 2. 否则返回栈的元素个数
*/
int StackLength(SqDulStack const *stack, CHSTACK choice);

/*
** 操作: 打印某栈的数据元素
** 参数:
** 1. 双栈的指针
** 2. 待查的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ShowStack(SqDulStack const *stack, CHSTACK choice);

/*
** 操作: 初始化某栈
** 参数:
** 1. 双栈的指针
** 2. 待初始化的栈的序号
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void InitStack(SqDulStack *stack, CHSTACK choice);

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
int Push(SqDulStack *stack, ElemType const *elem, CHSTACK choice);

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
int Pop(SqDulStack *stack, ElemType *elem, CHSTACK choice);

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
int GetTop(SqDulStack const *stack, ElemType *elem, CHSTACK choice);

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
void ClearStack(SqDulStack *stack, CHSTACK choice);

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
void DestroyStack(SqDulStack *stack, CHSTACK choice);

#endif