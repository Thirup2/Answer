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

/* 数据元素处理函数原型 */

/* 两栈共享空间接口函数原型 */

#endif