/* 循环链表接口头文件CycleList.h */
#ifndef _CYCLELIST_H_
#define _CYCLELIST_H_

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
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PNode;
struct list
{
    PNode head;
    PNode last;
    int length;
};
typedef struct list CycleList;

/* 数据元素处理函数原型 */

/* 循环链表接口函数原型 */

#endif