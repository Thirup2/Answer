/* 顺序栈接口头文件SqStack.h */
#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#include <stdbool.h>
/* 数据结构定义 */
#define MAXSIZE 20
typedef int ElemType;       // ElemType为一个数据元素, 包含一个数据项int
struct sqstack
{
    ElemType data[MAXSIZE];
    int top;
};
typedef struct sqstack SqStack;     // SqStack创建一个顺序栈

/* 接口函数原型 */

//操作: 初始化操作, 建立一个空栈
//前提条件: pstack是一个指向顺序栈的指针
//后置条件: top置为-1
void InitStack(SqStack *pstack);

//操作: 若栈存在, 则销毁它
//前提条件: pstack指向一个顺序栈
//后置条件: top置为-1
void DestroyStack(SqStack *pstack);

//操作: 将栈清空
//前提条件: pstack指向一个顺序栈
//后置条件: top置为-1
void ClearStack(SqStack *pstack);

//操作: 若栈为空, 返回true, 否则返回false
//前提条件: stack是一个顺序栈
bool StackEmpty(SqStack stack);

//操作: 若栈存在且非空, 用elem返回stack的栈顶元素
//前提条件: stack是一个顺序栈, elem是一个接收数据的指针
//后置条件: 若栈为空, 返回false, 否则返回true
bool GetTop(SqStack stack, ElemType *elem);

//操作: 若栈存在, 插入新元素elem到栈中并成为栈顶元素
//前提条件: pstack是一个指向顺序栈的指针, elem是一个数据元素
//后置条件: 若已满, 返回错误, 否则插入到栈顶, 长度加1
bool Push(SqStack *pstack, ElemType elem);

//操作: 删除栈中栈顶元素, 并用elem返回其值
//前提条件: pstack是一个指向顺序栈的指针, elem是一个接收数据的指针
//后置条件: 若栈为空, 返回错误, 否则删除栈顶元素, 长度减1
bool Pop(SqStack *pstack, ElemType *elem);

//操作: 返回栈的元素个数
//前提条件: stack是一个顺序栈
int StackLength(SqStack stack);

#endif