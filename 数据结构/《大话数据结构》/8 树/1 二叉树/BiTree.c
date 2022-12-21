/* 二叉树接口函数文件BiTree.c */

/* 包含头文件 */
#include "BiTree.h"

/* 二叉树接口函数定义 */

/*
** 操作：构造空树
** 返回值：树指针
*/
PtrTree InitTree(void)
{
    PtrTree tree = (PtrTree) malloc(sizeof(Tree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    tree->root = NULL;
    tree->status.level = 0;
    tree->status.order = 0;
    tree->length = 0;
    return  tree;
}

/*
** 操作：销毁树
** 参数：树指针
*/
void DestroyTree(PtrTree tree)
{
    ClearTree(tree);
    free(tree);
}

/*
** 操作：按definition给出的定义构造树
** 参数：树定义
** 返回值：树指针
*/
PtrTree CreatTree(PtrTree definition)
{
    if (TreeEmpty(definition) == false) {
        return NULL;
    }
    PtrTree tree = (PtrTree) malloc(sizeof(Tree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    tree->length = definition->length;
    tree->status.level = definition->status.level;
    tree->status.order = definition->status.order;
    // 复制每一个结点的所有内容（其中指针要相对转移为指向当前树对应位置的指针）
}

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
bool TreeEmpty(PtrTree tree)
{
    if (tree->length == 0) {
        return true;
    }
    return false;
}

/*
** 操作：返回树的深度
** 参数：树指针
** 返回值：数的深度
*/
int TreeDepth(PtrTree tree)
{
    return tree->status.level;
}

/*
** 操作：返回树的根节点
** 参数：树指针
** 返回值：
** 1. 若根节点不存在返回NULL
** 2. 否则返回根节点指针
*/
PtrNode Root(PtrTree tree);

/*
** 操作：返回指定结点的值
** 参数：
** 1. 树指针
** 2. 指定结点
** 返回值：
** 1. 若结点存在则返回该结点的数据元素
** 2. 否则返回NULL
*/
ElemType *Value(PtrTree tree, PtrPosition position);

/*
** 操作：给指定结点赋值
** 参数：
** 1. 树指针
** 2. 指定结点
** 3. 赋值元素
** 返回值：
** 1. 若指定结点无法创建则返回-1
** 2. 否则更改或创建指定结点并用赋值元素进行赋值，并返回0
*/
int Assign(PtrTree tree, PtrPosition position, ElemType *elem);

/*
** 操作：返回指定结点的双亲结点
** 参数：
** 1. 树指针
** 2. 指定结点
** 返回值：
** 1. 若指定结点没有双亲结点返回NULL
** 2. 否则返回双亲结点
*/
PtrNode Parent(PtrTree tree, PtrPosition position);

/*
** 操作：返回指定结点的左孩子结点
** 参数：
** 1. 树指针
** 2. 指定结点
** 返回值：
** 1. 若指定结点没有左孩子结点返回NULL
** 2. 否则返回左孩子结点
*/
PtrNode LeftChild(PtrTree tree, PtrPosition position);

/*
** 操作：返回指定结点的右兄弟结点
** 参数：
** 1. 树指针
** 2. 指定结点
** 返回值：
** 1. 若指定结点没有右兄弟结点返回NULL
** 2. 否则返回右兄弟结点
*/
PtrNode RightSibling(PtrTree tree, PtrPosition position);

/*
** 操作：向指定结点指定叶子插入指定子树
** 参数：
** 1. 树指针
** 2. 指定结点
** 3. 指定叶子
** 4. 指定子树
** 返回值：
** 1. 若指定结点该指定叶子不存在，则返回-1
** 2. 否则在指定结点指定叶子插入指定子树并返回0
*/
int InsertChild(PtrTree tree, PtrPosition position, Leaf leaf, PtrTree subtree);

/*
** 操作：删除指定结点指定叶子的子树
** 参数：
** 1. 树指针
** 2. 指定结点
** 3. 指定叶子
** 返回值：
** 1. 若指定结点指定叶子不存在子树，则返回-1
** 2. 否则删除该子树并返回0
*/
int DeleteChild(PtrTree tree, PtrPosition position, Leaf leaf);