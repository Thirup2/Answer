/* 双向循环链表接口头文件DulCyList.h */
#ifndef _DULCYLIST_H_
#define _DULCYLIST_H_

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
    struct node *pre;
    struct node *next;
};
typedef struct node Node;
typedef Node *PNode;
struct list
{
    PNode start;
    int length;
};
typedef struct list DulCyList;

/* 数据元素处理函数原型 */

/* 双向循环链表接口函数原型 */

#endif