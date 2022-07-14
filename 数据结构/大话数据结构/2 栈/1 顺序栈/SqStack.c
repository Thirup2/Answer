/* 顺序栈函数接口文件SqStack.c */
#include "SqStack.h"

/* 接口函数定义 */

//操作: 初始化操作, 建立一个空栈
void InitStack(SqStack *pstack)
{
    pstack->top = -1;
}

//操作: 若栈存在, 则销毁它
void DestroyStack(SqStack *pstack)
{
    (*pstack).top = -1;
}

//操作: 将栈清空
void ClearStack(SqStack *pstack)
{
    pstack->top = -1;
}

//操作: 若栈为空, 返回true, 否则返回false
bool StackEmpty(SqStack stack)
{
    if (stack.top == -1) {
        return true;
    } else {
        return false;
    }
}

//操作: 若栈存在且非空, 用elem返回stack的栈顶元素
bool GetTop(SqStack stack, ElemType *elem)
{
    if (StackEmpty(stack)) {
        return false;
    }
    *elem = stack.data[stack.top];
    return true;
}

//操作: 若栈存在, 插入新元素到栈中并成为栈顶元素
bool Push(SqStack *pstack, ElemType elem)
{
    if (pstack->top + 1 == MAXSIZE) {
        return false;
    }
    pstack->top++;
    pstack->data[pstack->top] = elem;
    return true;
}

//操作: 删除栈中栈顶元素, 并用elem返回其值
bool Pop(SqStack *pstack, ElemType *elem)
{
    if (pstack->top == -1) {
        return false;
    }
    *elem = pstack->data[pstack->top];
    pstack->top--;
    return true;
}

//操作: 返回栈的元素个数
int StackLength(SqStack stack)
{
    return stack.top + 1;
}