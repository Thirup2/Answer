/* 链栈函数接口文件LinkStack.c */
#include "LinkStack.h"
#include <stdlib.h>

/* 接口函数定义 */

//操作: 初始化操作, 建立一个空栈
void InitStack(LinkStack *pstack)
{
    pstack->top = NULL;
    pstack->count = 0;
}

//操作: 若栈存在, 则销毁它
void DestroyStack(LinkStack *pstack)
{
    Node *pnode;
    pnode = pstack->top;
    if (pstack->count > 0) {
        while (pnode != NULL) {
            pstack->top = pstack->top->next;
            free(pnode);
            pnode = pstack->top;
        }
        pstack->count = 0;
    }
}

//操作: 将栈清空
void ClearStack(LinkStack *pstack)
{
    Node *pnode;
    pnode = pstack->top;
    if (pstack->count > 0) {
        while (pnode != NULL) {
            pstack->top = pstack->top->next;
            free(pnode);
            pnode = pstack->top;
        }
        pstack->count = 0;
    }
}

//操作: 若栈为空, 返回true, 否则返回false
bool StackEmpty(LinkStack stack)
{
    if (stack.count == 0) {
        return true;
    } else {
        return false;
    }
}

//操作: 若栈存在且非空, 用elem返回stack的栈顶元素
bool GetTop(LinkStack stack, ElemType *elem)
{
    if (StackEmpty(stack)) {
        return false;
    }
    *elem = stack.top->data;
}

//操作: 若栈存在, 插入新元素elem到栈中并成为栈顶元素
bool Push(LinkStack *pstack, ElemType elem)
{
    Node *pnode;
    pnode = (Node *) malloc(sizeof(Node));
    if (pnode == NULL) {
        return false;
    }
    pnode->data = elem;
    pnode->next = pstack->top;
    pstack->top = pnode;
    pstack->count++;
    return true;
}

//操作: 删除栈中栈顶元素, 并用elem返回其值
bool Pop(LinkStack *pstack, ElemType *elem)
{
    if (StackEmpty(*pstack)) {
        return false;
    }
    *elem = pstack->top->data;
    Node *pnode;
    pnode = pstack->top;
    pstack->top = pstack->top->next;
    free(pnode);
    pstack->count--;
    return true;
}

//操作: 返回栈的元素个数
int StackLength(LinkStack stack)
{
    return stack.count;
}