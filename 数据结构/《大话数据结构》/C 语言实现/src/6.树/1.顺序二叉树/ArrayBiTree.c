#define EXPORT
#define RECURSION

#include "ArrayBiTree.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/* 局部函数声明 */

/*
 * 操作：根据深度计算当树为该深度时的满二叉树的最大结点编号
 * 参数：深度
 * 返回：最大结点
*/
static size_t DepthToSize(size_t depth);

/*
 * 操作：根据结点编号返回该结点所在的深度
 * 参数：按照满二叉树的结点编号
 * 返回：结点深度
*/
static size_t SizeToDepth(size_t size);

/*
 * 操作：为结点赋值
 * 参数：
 * 1. 被赋值结点
 * 2. 待赋值结点
*/
static void AssignNode(PtrNode node, cPtrNode data);

/*
 * 操作：将位置类型转换为数组下标+1
 * 参数：位置类型值
 * 返回：数组下标+1
*/
static size_t TranslatePos(cPtrPos pos);

/*
 * 操作：判断结点是否已使用
 * 参数：数组下标+1
 * 返回：true or false
*/
static bool NodeExist(cPtrNode node);

/*
 * 操作：根据数组下标加一创建并返回一个位置类型
 * 参数：数组下标 + 1
 * 返回：位置类型
*/
static PtrPos CreatePos(size_t size);

/*
 * 操作：返回双亲结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：双亲结点的数组下标 + 1
*/
static size_t ParentPos(size_t nodepos);

/*
 * 操作：返回左孩子结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：左孩子结点的数组下标 + 1
*/
static size_t LeftChildPos(size_t nodepos);

/*
 * 操作：返回右孩子结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：右孩子结点的数组下标 + 1
*/
static size_t RightChildPos(size_t nodepos);

/*
 * 操作：返回右兄弟结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：右兄弟结点的数组下标 + 1
*/
static size_t RightSiblingPos(size_t nodepos);

/*
 * 操作：前序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PreOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode));

/*
 * 操作：中序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void InOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode));

/*
 * 操作：后序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PostOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode));

/*
 * 操作：层序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void LevelOrderTraverse(cPtrTree tree, void (*NodeManFun)(cPtrNode));

/*
 * 操作：打印一个结点
 * 参数：结点指针
*/
static void PrintNode(cPtrNode node);

/* 接口函数定义 */

/*
 * 操作：构造空树
 * 参数：树的深度
 * 返回：空树的指针
*/
PtrTree DLL_CALL InitTree(size_t depth)
{
    PtrTree tree = (PtrTree) malloc(sizeof(Tree));
    if (!tree) {
        exit(EXIT_FAILURE);
    }
    size_t size = DepthToSize(depth);
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
 * 参数：待销毁的树
*/
void DLL_CALL DestroyTree(PtrTree tree)
{
    free(tree->root);
    free(tree);
}

/*
 * 操作：按给出的定义构造树
 * 参数：
 * 1. 定义数组
 * 2. 数组大小
 * 返回：构造树的指针
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
        AssignNode(&(tree->root[i]), &(definition[i]));
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
 * 参数：树
 * 返回值：
 * 1. 若为空返回 true
 * 2. 否则返回 false
*/
bool DLL_CALL TreeEmpty(cPtrTree tree)
{
    if (tree->root[0].used == false) {
        return true;
    }
    return false;
}

/*
 * 操作：返回树的深度
 * 参数：树
 * 返回值：树的深度
*/
size_t DLL_CALL TreeDepth(cPtrTree tree)
{
    return SizeToDepth(tree->size);
}

/*
 * 操作：返回结点的值
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 用于返回值的指针
 * 返回：
 * 1. 若结点不存在返回 WRONGPOS
 * 2. 若树为空返回 ISEMPTY
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL Value(cPtrTree tree, cPtrPos cur_e, PtrElem elem)
{
    size_t pos = TranslatePos(cur_e);
    if (pos < 1 || pos > tree->size) {
        return WRONGPOS;
    }
    if (!NodeExist(&(tree->root[pos - 1]))) {
        return WRONGPOS;
    }
    if (TreeEmpty(tree)) {
        return ISEMPTY;
    }
    AssignElem(elem, &(tree->root[pos - 1].data));
    return SUCCESS;
}

/*
 * 操作：为指定结点赋值
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 3. 赋值指针
 * 返回：
 * 1. 若结点无双亲结点且非根结点返回 WRONGPOS
 * 2. 若位置超过范围返回 WRONGPOS
 * 3. 否则执行操作返回 SUCCESS
*/
Status DLL_CALL Assign(PtrTree tree, cPtrPos cur_e, cPtrElem elem)
{
    size_t nodepos = TranslatePos(cur_e);
    size_t parentpos = ParentPos(nodepos);
    if (nodepos != 1 &&                                         // 非根结点 且
        ((parentpos < 1 || nodepos > tree->size)                // (位置错误 或
         || !NodeExist(&(tree->root[parentpos - 1])))) {  // 双亲不存在)
        return WRONGPOS;
    }
    AssignElem(&(tree->root[nodepos - 1].data), elem);
    tree->root[nodepos - 1].used = true;
    return SUCCESS;
}

/*
 * 操作：返回树的根结点
 * 参数：树
 * 返回值：
 * 1. 若根结点存在返回根结点的位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL Root(cPtrTree tree)
{
    size_t rootpos = 1;
    if (!NodeExist(&(tree->root[rootpos - 1]))) {
        return NULL;
    }
    PtrPos pos = CreatePos(rootpos);
    return pos;
}

/*
 * 操作：返回树中指定结点的双亲结点
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若双亲结点存在返回位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL Parent(cPtrTree tree, cPtrPos cur_e)
{
    size_t nodepos = TranslatePos(cur_e);
    size_t parentpos = ParentPos(nodepos);
    if (parentpos < 1 || nodepos > tree->size) {
        return NULL;
    }
    if (!NodeExist(&(tree->root[parentpos - 1]))) {
        return NULL;
    }
    PtrPos retpos = CreatePos(parentpos);
    return retpos;
}

/*
 * 操作：返回树中指定结点的左孩子结点
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若左孩子存在返回位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL LeftChild(cPtrTree tree, cPtrPos cur_e)
{
    size_t nodepos = TranslatePos(cur_e);
    size_t leftchildpos = LeftChildPos(nodepos);
    if (nodepos < 1 || leftchildpos > tree->size) {
        return NULL;
    }
    if (!NodeExist(&(tree->root[leftchildpos - 1]))) {
        return NULL;
    }
    PtrPos retpos = CreatePos(leftchildpos);
    return retpos;
}

/*
 * 操作：返回树中指定结点的右兄弟结点
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若右兄弟存在返回位置
 * 2. 否则返回 NULL
*/
PtrPos DLL_CALL RightSibling(cPtrTree tree, cPtrPos cur_e)
{
    size_t nodepos = TranslatePos(cur_e);
    size_t rightsiblingpos = RightSiblingPos(nodepos);
    if (nodepos < 1 || rightsiblingpos > tree->size) {
        return NULL;
    }
    if (!NodeExist(&(tree->root[rightsiblingpos - 1]))) {
        return NULL;
    }
    PtrPos retpos = CreatePos(rightsiblingpos);
    return retpos;
}

/*
 * 操作：打印树
 * 参数：
 * 1. 树
 * 2. 遍历方式
*/
void DLL_CALL PrintTree(cPtrTree tree, TravelWay way)
{
    size_t root = 1;
    if (way == PreOrder) {
        PreOrderTraverse(tree, root, PrintNode);
    } else if (way == InOrder) {
        InOrderTraverse(tree, root, PrintNode);
    } else if (way == PostOrder) {
        PostOrderTraverse(tree, root, PrintNode);
    } else if (way == LevelOrder) {
        LevelOrderTraverse(tree, PrintNode);
    } else {
        printf("无该选项！\n");
        exit(EXIT_FAILURE);
    }
    printf("\n");
}

/* 局部函数定义 */

/*
 * 操作：根据深度计算当树为该深度时的满二叉树的最大结点编号
 * 参数：深度
 * 返回：最大结点
*/
static size_t DepthToSize(size_t depth)
{
    return (size_t) pow(2, (double) depth) - 1;
}

/*
 * 操作：根据结点编号返回该结点所在的深度
 * 参数：按照满二叉树的结点编号
 * 返回：结点深度
*/
static size_t SizeToDepth(size_t size)
{
    return (size_t) log2((double) size) + 1;
}

/*
 * 操作：为结点赋值
 * 参数：
 * 1. 被赋值结点
 * 2. 待赋值结点
*/
static void AssignNode(PtrNode node, cPtrNode data)
{
    AssignElem(&(node->data), &(data->data));
    node->used = true;
}

/*
 * 操作：将位置类型转换为数组下标+1
 * 参数：位置类型值
 * 返回：数组下标+1
*/
static size_t TranslatePos(cPtrPos pos)
{
    return DepthToSize(pos->level - 1) + pos->order;
}

/*
 * 操作：判断结点是否已使用
 * 参数：数组下标+1
 * 返回：true or false
*/
static bool NodeExist(cPtrNode node)
{
    if (node->used) {
        return true;
    }
    return false;
}

/*
 * 操作：根据数组下标加一创建并返回一个位置类型
 * 参数：数组下标 + 1
 * 返回：位置类型
*/
static PtrPos CreatePos(size_t size)
{
    PtrPos pos = (PtrPos) malloc(sizeof(Pos));
    if (!pos) {
        exit(EXIT_FAILURE);
    }
    pos->level = SizeToDepth(size);
    pos->order = size - DepthToSize(pos->level - 1);
    return pos;
}

/*
 * 操作：返回双亲结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：双亲结点的数组下标 + 1
*/
static size_t ParentPos(size_t nodepos)
{
    return nodepos / 2;
}

/*
 * 操作：返回左孩子结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：左孩子结点的数组下标 + 1
*/
static size_t LeftChildPos(size_t nodepos)
{
    return 2 * nodepos;
}

/*
 * 操作：返回右孩子结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：右孩子结点的数组下标 + 1
*/
static size_t RightChildPos(size_t nodepos)
{
    return nodepos * 2 + 1;
}

/*
 * 操作：返回右兄弟结点的位置
 * 参数：查询结点的数组下标 + 1
 * 返回：右兄弟结点的数组下标 + 1
*/
static size_t RightSiblingPos(size_t nodepos)
{
    return nodepos + 1;
}

#ifdef RECURSION

/*
 * 操作：前序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PreOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode))
{
    size_t leftchild_pos = LeftChildPos(size);
    size_t rightchild_pos = RightChildPos(size);
    NodeManFun(&(tree->root[size - 1]));
    if (leftchild_pos < tree->size && NodeExist(&(tree->root[leftchild_pos - 1]))) {
        PreOrderTraverse(tree, leftchild_pos, NodeManFun);
    }
    if (rightchild_pos <= tree->size && NodeExist(&(tree->root[rightchild_pos - 1]))) {
        PreOrderTraverse(tree, rightchild_pos, NodeManFun);
    }
}

/*
 * 操作：中序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void InOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode))
{
    size_t leftchild_pos = LeftChildPos(size);
    size_t rightchild_pos = RightChildPos(size);
    if (leftchild_pos < tree->size && NodeExist(&(tree->root[leftchild_pos - 1]))) {
        InOrderTraverse(tree, leftchild_pos, NodeManFun);
    }
    NodeManFun(&(tree->root[size - 1]));
    if (rightchild_pos <= tree->size && NodeExist(&(tree->root[rightchild_pos - 1]))) {
        InOrderTraverse(tree, rightchild_pos, NodeManFun);
    }
}

/*
 * 操作：后序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PostOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode))
{
    size_t leftchild_pos = LeftChildPos(size);
    size_t rightchild_pos = RightChildPos(size);
    if (leftchild_pos < tree->size && NodeExist(&(tree->root[leftchild_pos - 1]))) {
        PostOrderTraverse(tree, leftchild_pos, NodeManFun);
    }
    if (rightchild_pos <= tree->size && NodeExist(&(tree->root[rightchild_pos - 1]))) {
        PostOrderTraverse(tree, rightchild_pos, NodeManFun);
    }
    NodeManFun(&(tree->root[size - 1]));
}

#else

/*
 * 操作：前序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PreOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode));

/*
 * 操作：中序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void InOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode));

/*
 * 操作：后序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void PostOrderTraverse(cPtrTree tree, size_t size, void (*NodeManFun)(cPtrNode));

#endif

/*
 * 操作：层序遍历二叉树
 * 参数：
 * 1. 树
 * 2. 结点处理函数
*/
static void LevelOrderTraverse(cPtrTree tree, void (*NodeManFun)(cPtrNode))
{
    for (size_t i = 0; i < tree->size; i++) {
        if (NodeExist(&(tree->root[i]))) {
            NodeManFun(&(tree->root[i]));
        }
    }
}

/*
 * 操作：打印一个结点
 * 参数：结点指针
*/
static void PrintNode(cPtrNode node)
{
    if (node->used) {
        PrintElem(&(node->data));
    }
}