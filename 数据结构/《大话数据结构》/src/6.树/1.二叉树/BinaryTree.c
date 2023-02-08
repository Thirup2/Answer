#define EXPORT

#include "BinaryTree.h"

// 局部函数声明

// 接口实现

/*
 * 操作：构造空树
 * 返回值：树的指针
*/
PtrTree DLL_CALL InitTree(void)
{
    return NULL;
}

/*
 * 操作：销毁树
 * 参数：待销毁的树
*/
void DLL_CALL DestroyTree(PtrTree tree)
{

}

/*
 * 操作：按 definition 给出的定义构造树
 * 参数：definition
 * 返回值：构造的树指针
*/
PtrTree DLL_CALL CreateTree(cPtrTree tree)
{

}

/*
 * 操作：清空树
 * 参数：树指针
*/
void DLL_CALL ClearTree(PtrTree tree)
{

}

/*
 * 操作：判断树是否为空
 * 参数：树指针
 * 返回值：true or false
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
 * 参数：树指针
 * 返回值：树的深度
*/
size_t DLL_CALL TreeDepth(cPtrTree tree)
{

}

/*
 * 操作：返回树的根结点
 * 参数：树指针
 * 返回值：树的根结点指针
*/
cPtrNode DLL_CALL Root(cPtrTree tree)
{
    return tree;
}

/*
 * 操作：返回树中指定结点的值
 * 参数：
 * 1. 树指针
 * 2. 指定位置
 * 3. 用于返回值的指针
 * 返回值：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若结点不存在返回 WRONGPOS
 * 3. 否则执行操作并返回 SUCCESS
*/
Status DLL_CALL Value(cPtrTree tree, cPtrPos position, PtrElem elem)
{

}

/*
 * 操作：为指定结点赋值
 * 参数：
 * 1. 树指针
 * 2. 指定位置
 * 3. 指定值
 * 返回值：
 * 1. 若结点没有双亲则返回 NOPARENT
 * 2. 若结点不存在则创建结点并赋值，若结点存在则修改值，返回 SUCCESS
*/
Status DLL_CALL Assign(PtrTree tree, cPtrPos position, cPtrElem elem)
{

}

/*
 * 操作：返回指定结点的双亲结点
 * 参数：
 * 1. 树指针
 * 2. 指定位置
 * 3. 用于返回值的指针
 * 返回值：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若结点双亲不存在返回 WRONGPOS
 * 3. 否则执行操作并返回 SUCCESS
*/
Status DLL_CALL Parent(cPtrTree tree, cPtrPos position, PtrElem elem)
{

}

/*
 * 操作：返回指定结点的左孩子结点
 * 参数：
 * 1. 树指针
 * 2. 指定位置
 * 3. 用于返回值的指针
 * 返回值：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若结点左孩子不存在返回 WRONGPOS
 * 3. 否则执行操作并返回 SUCCESS
*/
Status DLL_CALL LeftChild(cPtrTree tree, cPtrPos position, PtrElem elem)
{

}

/*
 * 操作：返回指定结点的右兄弟结点
 * 参数：
 * 1. 树指针
 * 2. 指定位置
 * 3. 用于返回值的指针
 * 返回值：
 * 1. 若树为空返回 ISEMPTY
 * 2. 若结点右兄弟不存在返回 WRONGPOS
 * 3. 否则执行操作并返回 SUCCESS
*/
Status DLL_CALL RightSibling(cPtrTree tree, cPtrPos position, PtrElem elem)
{

}

/*
 * 操作：插入子树到指定结点的指定分支
 * 参数：
 * 1. 树指针
 * 2. 指定结点
 * 3. 指定分支
 * 4. 指定子树
 * 返回值：
 * 1. 若指定位置不存在返回 WRONGPOS
 * 2. 若指定位置存在但指定分支已经有子树了返回 ISFULL
 * 3. 否则插入该子树该指定结点的指定分支并返回 SUCCESS
*/
Status DLL_CALL InsertChild(PtrTree tree, cPtrPos position, Branch branch, cPtrTree subtree)
{

}

/*
 * 操作：删除指定结点的指定分支的子树
 * 参数：
 * 1. 树指针
 * 2. 指定结点
 * 3. 指定分支
 * 4. 返回被删除子树的指针
 * 返回值：
 * 1. 若指定位置不存在返回 WRONGPOS
 * 2. 若指定位置的分支不存在返回 NOBRANCH
 * 3. 否则执行操作并返回 SUCCESS
*/
Status DLL_CALL DeleteChild(PtrTree tree, cPtrPos position, Branch branch, PtrTree subtree)
{

}

// 局部函数定义