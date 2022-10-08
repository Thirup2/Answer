/* 链栈接口头文件LinkStack.h */
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 数据结构定义 */
struct items
{
    int x;
    int y;
};                                      // 数据项结构
typedef struct items ElemType;          // 数据元素类型

struct node
{
    ElemType data;                      // 数据域
    struct node *next;                  // 指针域
};
typedef struct node Node;               // 结点类型
typedef Node *PNode;                    // 结点指针

struct stack
{
    PNode top;                          // 头指针兼栈顶指针
    int length;                         // 链栈长度
};
typedef struct stack LinkStack;         // 链栈类型

/* 元素处理函数原型 */

/*
** 操作: 更改数据元素的值
** 参数:
** 1. 待更改的元素指针
** 2. 用于更改的元素指针
*/
void ChangeElem(ElemType *elem, ElemType const *data);

/*
** 操作: 打印一个数据元素
** 参数: 待打印的数据元素
*/
void PrintElem(ElemType const *elem);

/* 链栈接口函数原型 */

/*
** 操作: 判断链栈是否为空
** 参数: 链栈指针
** 返回值:
** 1. 若链栈为空, 则返回true
** 2. 若链栈非空, 则返回false
*/
bool StackEmpty(LinkStack const *stack);

/*
** 操作: 获取链栈的元素个数
** 参数: 链栈指针
** 返回值: 链栈的元素个数
*/
int StackLength(LinkStack const *stack);

/*
** 操作: 打印链栈所有元素
** 参数: 链栈指针
*/
void ShowStack(LinkStack const *stack);

/*
** 操作: 初始化操作
** 1. 栈顶指针设置为空
** 2. 链栈长度设置为0
** 参数: 链栈指针
*/
void InitStack(LinkStack *stack);

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
int Push(LinkStack *stack, ElemType const *elem);

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
int Pop(LinkStack *stack, ElemType *elem);

/*
** 操作: 获取栈顶元素
** 参数:
** 1. 链栈指针
** 2. 用于返回的数据元素指针
** 返回值:
** 1. 若链栈为空返回-1
** 2. 返回成功返回0
*/
int GetTop(LinkStack const *stack, ElemType *elem);

/*
** 操作: 清空链栈
** 1. 将所有结点空间释放, 仅保留头结点(本例未设置头结点)
** 2. 栈顶指针指向头结点
** 3. 链栈长度设置为0
** 参数: 链栈指针
*/
void ClearStack(LinkStack *stack);

/*
** 操作: 销毁链栈
** 1. 将所有结点空间释放, 包括头结点
** 2. 栈顶指针指向NULL
** 3. 链栈长度设置为0
** 参数: 链栈指针
*/
void DestroyStack(LinkStack *stack);

# endif