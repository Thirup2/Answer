/* 二叉树接口函数文件BiTree.c */

/* 包含头文件 */
#include "BiTree.h"

/* 二叉树局部函数原型 */

/*
** 操作: 打印一个数据元素
** 参数: 一个数据元素指针
*/
void PrintElem(PNode node);

/*
** 操作: 释放一个结点
** 参数: 一个结点指针
*/
void DeleteNode(PNode node);

/*
** 操作: 在指定结点下指定分支创建一个结点
** 参数:
** 1. 结点指针
** 2. 待插入元素指针
*/
void InsertNode(PNode node, ElemType *elem);

/* 数据元素处理函数定义 */

/*
** 操作: 修改结点数据的值
** 参数:
** 1. 待修改的元素指针
** 2. 用于修改的元素指针
*/
void ChangeElem(ElemType *elem1, ElemType *elem2)
{
    elem1->x = elem2->x;
    elem2->y = elem2->y;
}

/*
** 操作: 比较两个结点的元素值
** 参数: 两个用于比较的元素指针
** 返回值:
** 1. 若两元素相等, 返回true
** 2. 否则返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2)
{
    if (elem1->x == elem2->x && elem1->y == elem2->y) {
        return true;
    }
    return false;
}

/* 二叉树接口函数定义 */

/*
** 操作: 构造空树
** 返回值: 返回一个空树的指针
*/
PtrBiTree InitTree(void)
{
    PtrBiTree tree = (PtrBiTree) malloc(sizeof(BiTree));
    tree->length = 0;
    tree->root = NULL;
    return tree;
}

/*
** 操作: 销毁树
** 参数: 待销毁的树
*/
void DestroyTree(PtrBiTree tree)
{
    PostOrderTraverse(tree, DeleteNode);
    free(tree);
}

/*
** 操作: 按definition给出的定义构造树
** 参数: 一个树模板definition
** 返回值: 一个构造完成的树指针
*/
PtrBiTree CreatTree(PtrBiTree definition)
{
    
}

/*
** 操作: 清空树
** 参数: 树指针
*/
void ClearTree(PtrBiTree tree)
{
    PostOrderTraverse(tree, DeleteNode);
    free(tree);
}

/*
** 操作: 判断树是否为空
** 参数: 树指针
** 返回值:
** 1. 若树为空, 返回true
** 2. 否则返回false
*/
bool TreeEmpty(PtrBiTree tree)
{
    if (tree->length == 0) {
        return true;
    }
    return false;
}

/*
** 操作: 返回树的深度
** 参数: 树指针
** 返回值: 树的深度
*/
int TreeDepth(PtrBiTree tree)
{
    
}

/*
** 操作: 返回树的根结点
** 参数: 树指针
** 返回值:
** 1. 若树为空, 返回NULL
** 2. 否则返回树的根结点数据指针
*/
ElemType *Root(PtrBiTree tree)
{
    return &(tree->root->data.elem);
}

/*
** 操作: 返回指定结点的值
** 参数:
** 1. 树指针
** 2. 指定结点
** 返回值:
** 1. 若该结点不存在, 返回NULL
** 2. 返回该结点的数据指针
*/
ElemType *Value(PtrBiTree tree, Pos position)
{
    
}

/*
** 操作: 给指定结点赋值
** 1. 若该结点存在, 则改变原有值
** 2. 若该结点不存在, 若该结点允许创建, 则创建结点, 并赋值
** 参数:
** 1. 树指针
** 2. 指定结点指针
** 3. 元素指针
** 返回值:
** 1. 若该结点不允许创建, 返回-1
** 2. 否则创建结点并赋值或直接赋值返回0
*/
int Assign(PtrBiTree tree, Pos position, ElemType *elem)
{
    
}

/*
** 操作: 返回指定结点的双亲结点的元素值
** 参数:
** 1. 树指针
** 2. 指定结点位置
** 返回值:
** 1. 若指定结点为根结点或指定结点不存在, 返回NULL
** 2. 否则返回指定结点双亲元素指针
*/
ElemType *Parent(PtrBiTree tree, Pos position)
{
    
}

/*
** 操作: 返回指定结点的左孩子结点元素
** 参数:
** 1. 树指针
** 2. 指定结点位置
** 返回值:
** 1. 若指定结点或指定结点的左孩子结点不存在, 返回NULL
** 2. 否则返回指定结点左孩子元素指针
*/
ElemType *LeftChild(PtrBiTree tree, Pos position)
{
    
}

/*
** 操作: 返回指定结点右兄弟结点元素
** 参数:
** 1. 树指针
** 2. 指定结点位置
** 返回值:
** 1. 若指定结点或指定结点的右兄弟结点不存在, 返回NULL
** 2. 否则返回指定结点右兄弟元素指针
*/
ElemType *RightBrother(PtrBiTree tree, Pos position)
{
    
}

/*
** 操作: 在树中指定结点的指定分支插入指定子树
** 参数:
** 1. 树指针
** 2. 指定结点
** 3. 指定分支
** 4. 指定子树
** 返回值:
** 1. 若指定结点不存在, 返回-1
** 2. 若指定结点的指定分支已有值, 返回-2
** 3. 否则执行操作返回0
*/
int InsertChild(PtrBiTree tree, Pos position, BRANCH branch, PtrBiTree subtree)
{
    
}

/*
** 操作: 删除树中指定结点的指定分支的子树
** 参数:
** 1. 树指针
** 2. 指定结点
** 3. 指定分支
** 4. 用于返回分支子树的指针
** 返回值:
** 1. 若指定结点不存在, 返回-1
** 2. 若指定结点的指定分支不存在, 返回-2
** 3. 否则执行操作返回0
*/
int DeleteChild(PtrBiTree tree, Pos position, BRANCH branch, PtrBiTree subtree)
{
    
}

/*
** 操作: 前序遍历树
** 参数:
** 1. 树指针
** 2. 数据处理函数
*/
void PreOrderTraverse(PtrBiTree tree, void (*function)(PNode node, ElemType *elem))
{
    
}

/*
** 操作: 中序遍历树
** 参数:
** 1. 树指针
** 2. 数据处理函数
*/
void InOrderTraverse(PtrBiTree tree, void (*function)(PNode node))
{
    
}

/*
** 操作: 后序遍历树
** 参数:
** 1. 树指针
** 2. 数据处理函数
*/
void PostOrderTraverse(PtrBiTree tree, void (*function)(PNode node))
{
    
}

/* 局部函数定义 */

/*
** 操作: 打印一个数据元素
** 参数: 一个数据元素指针
*/
void PrintElem(PNode node)
{
    printf("[%d, %d: (%d, %d)] ", node->data.position.level, node->data.position.order, node->data.elem.x, node->data.elem.y);
}

/*
** 操作: 释放一个结点
** 参数: 一个结点指针
*/
void DeleteNode(PNode node)
{
    free(node);
}

/*
** 操作: 在指定结点下指定分支创建一个结点
** 参数:
** 1. 结点指针
** 2. 待插入元素指针
*/
void InsertNode(PNode node, ElemType *elem)
{
    
}