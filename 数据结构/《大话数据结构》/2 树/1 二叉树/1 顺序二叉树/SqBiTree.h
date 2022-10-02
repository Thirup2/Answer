/* 顺序二叉树接口头文件SqBiTree.h */
#ifndef _SQBITREE_H_
#define _SQBITREE_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

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
    bool flag;                  // 当前位置是否有值, 有值为true, 否则为false
};
typedef struct node Node;
typedef Node *PNode;

struct tree
{
    PNode tree;                 // 动态数组, 暂时以指针存储
    int length;                 // 保存当前二叉树的结点个数, 包括无值的
};
typedef struct tree SqBiTree;

struct position
{
    int level;                  // 结点所在层数
    int order;                  // 结点在当前层数的位序
};                              // 定位类型定义, 按满二叉树编号
typedef struct position Pos;    // 定位类型, 用于指定插入、删除或查询的位置

/* 数据元素处理函数原型 */

/*
** 操作: 更改数据元素的值
** 参数:
** 1. 待更改的数据元素指针
** 2. 用于更改的数据元素指针
*/
void ChangeElem(ElemType *elem1, ElemType *elem2);

/*
** 操作: 比较两个数据元素是否相同
** 参数: 用于比较的两个数据元素指针
** 返回值:
** 1. 若相同则返回true
** 2. 不相同返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2);

/* 顺序二叉树接口函数原型 */

/*
** 操作: 构造空树
** 返回值: 一个空树的指针
*/
SqBiTree *InitTree(void);

/*
** 操作: 销毁树
** 参数: 待销毁的树指针
*/
void DestroyTree(SqBiTree *tree);

/*
** 操作: 按definition的定义构造树
** 参数:
** 1. 原树的指针
** 2. definition定义
** 返回值: 新树的指针
*/
SqBiTree *CreatTree(SqBiTree *tree, Pos *position);

/*
** 操作: 判断是否为空树
** 参数: 树指针
** 返回值:
** 1. 若为空返回true
** 2. 否则返回false
*/
bool TreeEmpty(SqBiTree *tree);

/*
** 操作: 返回树的深度
** 参数: 树指针
** 返回值:
** 1. 若树为空, 则返回0
** 2. 否则返回树的深度
*/
int TreeDepth(SqBiTree *tree);

/*
** 操作: 返回树的根节点
** 参数: 树指针
** 返回值:
** 1. 若根节点不存在或无值则返回空指针
** 2. 否则返回根节点的指针
*/
ElemType *Root(SqBiTree *tree);

/*
** 操作: 返回树中指定结点的元素值
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若结点存在且有值, 则返回结点指针
** 2. 否则返回空指针
*/
ElemType *Value(SqBiTree *tree, Pos *position);

/*
** 操作: 为树中指定结点赋值
** 参数:
** 1. 树指针
** 2. 结点位置
** 3. 待赋的值
** 返回值:
** 1. 若结点不存在则返回-1
** 2. 否则执行操作返回0
*/
int Assign(SqBiTree *tree, Pos *position, ElemType *elem);

/*
** 操作: 返回指定结点的双亲结点
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若指定结点非根节点且其双亲结点存在且有值, 则返回其双亲结点的值
** 2. 否则返回空指针
*/
ElemType *Parent(SqBiTree *tree, Pos *position);

/*
** 操作: 返回指定结点的左孩子结点
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若指定结点的左孩子结点存在且有值, 则返回其左孩子结点的值
** 2. 否则返回空指针
*/
ElemType *LeftChild(SqBiTree *tree, Pos *position);

/*
** 操作: 返回指定结点的右兄弟结点
** 参数:
** 1. 树指针
** 2. 结点位置
** 返回值:
** 1. 若指定结点的右兄弟结点存在且有值, 则返回其左孩子结点的值
** 2. 否则返回空指针
*/
ElemType *RightSibling(SqBiTree *tree, Pos *position);

/*
** 操作: 层序遍历顺序二叉树
** 参数: 树指针
*/
void TraverseTree(SqBiTree *tree, void (*ElemFun)(PNode elem));

#endif