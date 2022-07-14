/* 两栈共享空间函数接口文件SqDoubleStack.c */
#include "SqDoubleStack.h"

/* 接口函数定义 */

//操作: 初始化操作, 建立一个空栈
void InitStack(SqDoubleStack *pstack)
{
    pstack->top1 = -1;
    pstack->top2 = MAXSIZE;
}

//操作: 若栈存在, 则销毁它
void DestroyStack(SqDoubleStack *pstack)
{
    pstack->top1 = -1;
    pstack->top2 = MAXSIZE;
}

//操作: 将栈清空
void ClearStack(SqDoubleStack *pstack, int stackNum)
{
    if (stackNum == STACK_1) {
        pstack->top1 = -1;
    }
    if (stackNum == STACK_2) {
        pstack->top2 = MAXSIZE;
    }
}

//操作: 若栈为空, 返回true, 否则返回false
bool StackEmpty(SqDoubleStack stack, int stackNum)
{
    if (stackNum == STACK_1) {
        if (stack.top1 == -1) {
            return true;
        } else {
            return false;
        }
    }
    if (stackNum == STACK_2) {
        if (stack.top2 == MAXSIZE) {
            return true;
        } else {
            return false;
        }
    }
}

//操作: 若栈存在且非空, 用elem返回stack的栈顶元素
bool GetTop(SqDoubleStack stack, ElemType *elem, int stackNum)
{
    if (stackNum == STACK_1) {
        if (StackEmpty(stack, STACK_1)) {
            return false;
        }
        *elem = stack.data[stack.top1];
    }
    if (stackNum == STACK_2) {
        if (StackEmpty(stack, STACK_2)) {
            return false;
        }
        *elem = stack.data[stack.top2];
    }
    return true;
}

//操作:若栈存在, 插入新元素elem到栈中并成为栈顶元素
bool Push(SqDoubleStack *pstack, ElemType elem, int stackNum)
{
    if (pstack->top1 + 1 == pstack->top2) {
        return false;
    }
    if (stackNum == STACK_1) {
        pstack->top1++;
        pstack->data[pstack->top1] = elem;
    }
    if (stackNum == STACK_2) {
        pstack->top2--;
        pstack->data[pstack->top2] = elem;
    }
    return true;
}

//操作: 删除占中栈顶元素, 并用elem返回其值
bool Pop(SqDoubleStack *pstack, ElemType *elem, int stackNum)
{
    if (stackNum == STACK_1) {
        if (StackEmpty(*pstack, STACK_1)) {
            return false;
        }
        *elem = pstack->data[pstack->top1];
        pstack->top1--;
    }
    if (stackNum == STACK_2) {
        if (StackEmpty(*pstack, STACK_2)) {
            return false;
        }
        *elem = pstack->data[pstack->top2];
        pstack->top2++;
    }
    return true;
}

//操作: 返回栈的元素个数
int StackLength(SqDoubleStack stack, int stackNum)
{
    if (stackNum == STACK_1) {
        return stack.top1 + 1;
    }
    if (stackNum == STACK_2) {
        return MAXSIZE - stack.top2;
    }
}