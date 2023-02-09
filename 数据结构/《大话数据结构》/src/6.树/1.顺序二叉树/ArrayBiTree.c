#define EXPORT

#include "ArrayBiTree.h"
#include <math.h>
#include <stdlib.h>

// 局部函数声明

// 接口定义

/*
 * 操作：构造空树
 * 参数：指定树的深度
 * 返回：构造的树
*/
ABT_API PtrTree DLL_CALL InitTree(size_t depth)
{
    size_t size = (size_t) (pow(2, (double) depth) - 1);
    PtrTree tree = (PtrTree) malloc(sizeof(Tree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    tree->size = size;
    tree->root = (PtrNode) malloc(size * sizeof(Node));
    if (!tree->root) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        tree->root[i].used = false;
    }
    return tree;
}

/*
 * 操作：销毁树
 * 参数：待销毁树
*/
void DLL_CALL DestroyTree(PtrTree tree)
{
    free(tree->root);
    free(tree);
}

/*
 * 操作：按照定义构造树
 * 参数：结点类型的数组
 * 返回：构造的树
*/
PtrTree DLL_CALL CreateTree(cPtrNode definition, size_t size)
{
    PtrTree tree = (PtrTree) malloc(sizeof(Tree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    tree->size = size;
    tree->root = (PtrNode) malloc(size * sizeof(Node));
    if (!tree->root) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < size; i++) {
        tree->root[i].used = definition[i].used;
        if (tree->root[i].used) {
            AssignElem(&(tree->root[i].data), &(definition[i].data));
        }
    }
    return tree;
}

/*
 * 操作：清空树
 * 参数：待清空树
*/
void DLL_CALL ClearTree(PtrTree tree)
{
    for (size_t i = 0; i < tree->size; i++) {
        tree->root[i].used = false;
    }
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
    if (tree->root[0].used) {
        return false;
    }
    return true;
}

/*
 * 操作：返回树的深度
 * 参数：树
 * 返回：树的深度
*/
size_t DLL_CALL TreeDepth(cPtrTree tree);

/*
 * 操作：返回某结点的值
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 返回值用指针
 * 返回：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若该结点不存在返回 WRONGPOS
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL Value(cPtrTree tree, cPtrPos pos, PtrElem elem);

/*
 * 操作：为树中某结点赋值
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 用于赋值的元素
 * 返回：
 * 1. 若该结点无双亲且非根结点返回 WRONGPOS
 * 2. 否则修改该结点的值并返回 SUCCESS
*/
Status DLL_CALL Assign(PtrTree tree, cPtrPos pos, cPtrElem elem);

/*
 * 操作：返回树的根结点
 * 参数：树
 * 返回：根结点
*/
PtrPos DLL_CALL Root(cPtrTree tree);

/*
 * 操作：返回指定结点的双亲
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若存在返回位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL Parent(cPtrTree tree, cPtrPos pos);

/*
 * 操作：返回指定结点的左孩子
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若存在则返回位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL LeftChild(cPtrTree tree, cPtrPos pos);

/*
 * 操作：返回指定结点的右兄弟
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若存在则返回位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL RightSibling(cPtrTree tree, cPtrPos pos);

/*
 * 操作：插入子树
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 指定分支
 * 4. 子树
 * 返回：
 * 1. 若插入后超过最大深度截断最大深度后的结点并返回 OVERFLOW
 * 2. 若指定结点不存在返回 WRONGPOS（忽略根结点）
 * 3. 若指定分支已存在返回 ISFULL
 * 4. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL InsertChild(PtrTree tree, cPtrPos pos, Branch branch, cPtrTree subtree);

/*
 * 操作：删除子树
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 指定分支
 * 4. 返回子树
 * 返回：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若指定结点的指定分支不存在返回 WRONGPOS
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL DeleteChild(PtrTree tree, cPtrPos pos, Branch branch, PtrTree subtree);

/*
 * 操作：打印树
 * 参数：
 * 1. 树
 * 2. 指定遍历方式
*/
void DLL_CALL PrintTree(cPtrTree tree, TravelWay way);

// 局部函数定义