/* 二叉树接口头文件BiTree.h */
#ifndef _BITREE_H_
#define _BITREE_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 数据类型定义 */
struct items
{
    int x;
    int y;
};
typedef struct items ElemType;

struct position
{
    int level;  // 层数
    int order;  // 位置
};
typedef struct position Position;
typedef Position *PtrPosition;

struct node
{
    ElemType data;
    Position pos;
    struct node *lchild;
    struct node *rchild;
    struct node *parent;
    struct node *rbrother;
};
typedef struct node Node;
typedef Node *PtrNode;

struct tree
{
    PtrNode root;
    Position status;        // 保存深度与最大叶子位置
    int length;             // 有效元素的个数
};
typedef struct tree Tree;
typedef Tree *PtrTree;

/* 二叉树接口函数原型 */

/*
** 操作：构造空树
** 返回值：树指针
*/
PtrTree InitTree(void);

/*
** 操作：销毁树
** 参数：树指针
*/
void DestroyTree(PtrTree tree);

/*
** 操作：按definition给出的定义构造树
** 参数：树定义
** 返回值：树指针
*/
PtrTree CreatTree(PtrTree definition);

/*
** 操作：清空树
** 参数：树指针
*/
void ClearTree(PtrTree tree);

/*
** 操作：判断是否空树
** 参数：树指针
** 返回值：
** 1. 若为空树则返回true
** 2. 否则返回false
*/
bool TreeEmpty(PtrTree tree);

/*
** 操作：返回树的深度 */

#endif