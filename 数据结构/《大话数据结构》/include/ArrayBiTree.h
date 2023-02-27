/* 顺序二叉树接口头文件 */
#ifndef ARRAYBITREE_H_
#define ARRAYBITREE_H_

/* 包含头文件 */
#include "ElemType.h"
#include "Status.h"
#include <stdbool.h>
#include <stddef.h>

/* 兼容配置 */
#ifdef _WIN32
#ifdef EXPORT
#define ABT_API _declspec(dllexport)
#else
#define ABT_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define ABT_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 顺序二叉树类型定义 */
struct node
{
    ElemType data;
    bool used;      // 标记该节点是否被使用
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct pos
{
    size_t level;       // 深度
    size_t order;       // 指定深度的位序
};
typedef struct pos Pos;
typedef Pos *PtrPos;
typedef const Pos *cPtrPos;

struct tree
{
    PtrNode root;
    size_t size;
};
typedef struct tree Tree;
typedef Tree *PtrTree;
typedef const Tree *cPtrTree;

enum travelway
{
    PreOrder,
    InOrder,
    PostOrder,
    LevelOrder
};
typedef enum travelway TravelWay;

/* 顺序二叉树函数接口 */

/*
 * 操作：构造空树
 * 参数：树的深度
 * 返回：空树的指针
*/
ABT_API PtrTree DLL_CALL InitTree(size_t depth);

/*
 * 操作：销毁树
 * 参数：待销毁的树
*/
ABT_API void DLL_CALL DestroyTree(PtrTree tree);

/*
 * 操作：按给出的定义构造树
 * 参数：
 * 1. 定义数组
 * 2. 数组大小
 * 返回：构造树的指针
*/
ABT_API PtrTree DLL_CALL CreateTree(cPtrNode definition, size_t size);

/*
 * 操作：清空树
 * 参数：待清空树
*/
ABT_API void DLL_CALL ClearTree(PtrTree tree);

/*
 * 操作：判断树是否为空
 * 参数：树
 * 返回值：
 * 1. 若为空返回 true
 * 2. 否则返回 false
*/
ABT_API bool DLL_CALL TreeEmpty(cPtrTree tree);

/*
 * 操作：返回树的深度
 * 参数：树
 * 返回值：树的深度
*/
ABT_API size_t DLL_CALL TreeDepth(cPtrTree tree);

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
ABT_API Status DLL_CALL Value(cPtrTree tree, cPtrPos cur_e, PtrElem elem);

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
ABT_API Status DLL_CALL Assign(PtrTree tree, cPtrPos cur_e, cPtrElem elem);

/*
 * 操作：返回树的根结点
 * 参数：树
 * 返回值：
 * 1. 若根结点存在返回根结点的位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL Root(cPtrTree tree);

/*
 * 操作：返回树中指定结点的双亲结点
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若双亲结点存在返回位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL Parent(cPtrTree tree, cPtrPos cur_e);

/*
 * 操作：返回树中指定结点的左孩子结点
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若左孩子存在返回位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL LeftChild(cPtrTree tree, cPtrPos cur_e);

/*
 * 操作：返回树中指定结点的右兄弟结点
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若右兄弟存在返回位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL RightSibling(cPtrTree tree, cPtrPos cur_e);

/*
 * 操作：打印树
 * 参数：
 * 1. 树
 * 2. 遍历方式
*/
ABT_API void DLL_CALL PrintTree(cPtrTree tree, TravelWay way);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif