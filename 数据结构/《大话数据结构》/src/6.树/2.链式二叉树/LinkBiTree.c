#define EXPORT

#include "LinkBiTree.h"
#include <stdlib.h>
#include <stdio.h>

/* 局部函数声明 */

/*
 * 操作：销毁结点
 * 参数：结点指针
*/
static void DestroyNode(PtrTree node);

/*
 * 操作：读取值并创建结点
 * 参数：
 * 1. 树
 * 2. 当前结点的指针
*/
static void CreateNode(PtrTree node);

/*
 * 操作：遍历创建
 * 参数：
 * 1. 树指针
 * 2. 结点处理函数
*/
static void CreateTraverse(PtoPTree tree);

/*
 * 操作：前序遍历
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PreOrderTraverse(PtrTree tree, void (*NodeManFun)(PtrTree));

/*
 * 操作：后序遍历
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PostOrderTraverse(PtrTree tree, void (*NodeManFun)(PtrTree));

/* 接口函数定义 */

/*
 * 操作：构造空树
 * 返回：空树指针
*/
PtoPTree DLL_CALL InitTree(void)
{
    PtoPTree tree = (PtoPTree) malloc(sizeof(PtrTree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    *tree = NULL;
    return tree;
}

/*
 * 操作：销毁树
 * 参数：待销毁树
*/
void DLL_CALL DestroyTree(PtoPTree tree)
{
    PostOrderTraverse(*tree, DestroyNode);
    free(tree);
}

/*
 * 操作：根据输入构造树
 * 返回：构造的树
*/
PtoPTree DLL_CALL CreateTree(void)
{
    PtoPTree tree = (PtoPTree) malloc(sizeof(PtrTree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    *tree = NULL;
    printf("接下来按照前序遍历的顺序进行输入，请按照\"x, y\"的格式进行输入，"
           "任何输入错误将结束当前分支的继续创建，将按照前序遍历的顺序切换到下一分支，"
           "当结束分支是最后一个分支时，整个二叉链表构造结束。\n"
           "接下来，请输入根结点的数据：");
    CreateTraverse(tree);
    return tree;
}

/*
 * 操作：清空树
 * 参数：待清空树
*/
void DLL_CALL ClearTree(PtrTree tree)
{
    PostOrderTraverse(tree, DestroyNode);
}

/*
 * 操作：判断树是否为空
 * 参数：待判断树
 * 返回：
 * 1. 若为空返回 true
 * 2. 否则返回 false
*/
bool DLL_CALL TreeEmpty(cPtrTree tree)
{
    if (tree == NULL) {
        return true;
    }
    return false;
}

/*
 * 操作：返回树的深度
 * 参数：待计算树
 * 返回：树的深度（0为空树）
*/
size_t DLL_CALL TreeDepth(cPtrTree tree);

/*
 * 操作：返回指定结点的值
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 用于返回值的元素
 * 返回：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若指定结点不存在返回 WRONGPOS
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL Value(cPtrTree tree, cPosition pos, PtrElem elem);

/*
 * 操作：修改某结点的值
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 用于赋值的元素
 * 返回：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若指定结点不存在返回 WRONGPOS
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL Assign(PtrTree tree, cPosition pos, cPtrElem elem);

/*
 * 操作：返回树的根结点位置
 * 参数：树
 * 返回：根结点位置，若为空返回 NULL
*/
Position DLL_CALL Root(cPtrTree tree);

/*
 * 操作：查找指定元素的位置
 * 参数：
 * 1. 树
 * 2. 指定元素
 * 返回：
 * 1. 若无该元素则返回 NULL
 * 2. 否则返回该元素的位置
*/
Position DLL_CALL FindElem(cPtrElem elem);

/*
 * 操作：返回指定结点的双亲位置
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若双亲不存在返回 NULL
 * 2. 否则返回双亲的位置
*/
Position DLL_CALL Parents(cPtrTree tree, cPosition pointed);

/*
 * 操作：返回指定结点的左孩子位置
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若左孩子不存在返回 NULL
 * 2. 否则返回左孩子的位置
*/
Position DLL_CALL LeftChild(cPtrTree tree, cPosition pointed);

/*
 * 操作：返回指定结点的右兄弟位置
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若右兄弟不存在返回 NULL
 * 2. 否则返回右兄弟的位置
*/
Position DLL_CALL RightSibling(cPtrTree tree, cPosition pointed);

/*
 * 操作：在指定结点的指定分支插入指定子树
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 指定分支
 * 4. 指定子树
 * 返回：
 * 1. 若指定结点不存在返回 WRONGPOS
 * 2. 若指定分支子树已存在返回 OVERFLOW
 * 3. 否则指定操作返回 SUCCESS
*/
Status DLL_CALL InsertChild(PtrTree tree, cPosition pointed, Branch branch, cPtrTree subtree);

/*
 * 操作：删除指定结点指定分支的子树并将其返回
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 指定分支
 * 4. 返回子树
 * 返回：
 * 1. 若指定结点不存在返回 WRONGPOS
 * 2. 若指定分支子树不存在返回 ISEMPTY
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL DeleteChild(PtrTree tree, cPosition pointed, Branch branch, PtrTree subtree);

/*
 * 操作：打印树
 * 参数：
 * 1. 树
 * 2. 遍历方式
*/
void DLL_CALL PrintTree(cPtrTree tree, TravelWay travelway);

/* 局部函数定义 */