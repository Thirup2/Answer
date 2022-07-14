/* 链栈接口头文件LinkStack.h */
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdbool.h>
/* 数据结构定义 */
typedef int ElemType;           // ElemType是数据元素类型, 包括一个数据项int
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;       // 一个结点包括数据域和指针域
struct linkstack
{
    Node *top;
    int count;
};
typedef struct linkstack LinkStack;   // 一个链栈包括一个头指针和链栈长度

/* 接口函数原型 */

//操作: 初始化操作, 建立一个空栈
//前提条件: pstack是一个指向链栈的指针
//后置条件: top指向NULL, count置为0
void InitStack(LinkStack *pstack);

//操作: 若栈存在, 则销毁它
//前提条件: pstack指向一个链栈
//后置条件: top指向NULL, count置为0, 释放内存
void DestroyStack(LinkStack *pstack);

//操作: 将栈清空
//前提条件: pstack指向一个链栈
//后置条件: top指向NULL, count置为0, 释放内存
void ClearStack(LinkStack *pstack);

//操作: 若栈为空, 返回true, 否则返回false
//前提条件: stack是一个链栈
bool StackEmpty(LinkStack stack);

//操作: 若栈存在且非空, 用elem返回stack的栈顶元素
//前提条件: stack是一个链栈, elem是一个接收数据的指针
//后置条件: 若栈为空, 返回false, 否则返回true
bool GetTop(LinkStack stack, ElemType *elem);

//操作: 若栈存在, 插入新元素elem到栈中并成为栈顶元素
//前提条件: pstack是一个指向链栈的指针, elem是一个数据元素
//后置条件: 若已满, 返回错误, 否则插入到栈顶, 长度加1
bool Push(LinkStack *pstack, ElemType elem);

//操作: 删除栈中栈顶元素, 并用elem返回其值
//前提条件: pstack是一个指向链栈的指针, elem是一个接收数据的指针
//后置条件: 若栈为空, 返回错误, 否则删除栈顶元素, 长度减1
bool Pop(LinkStack *pstack, ElemType *elem);

//操作: 返回栈的元素个数
//前提条件: stack是一个链栈
int StackLength(LinkStack stack);

#endif