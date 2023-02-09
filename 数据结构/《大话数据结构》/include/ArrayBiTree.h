/* 顺序二叉树接口头文件 */
#ifndef _ARRAYBITREE_H_
#define _ARRAYBITREE_H_

/* 包含头文件 */
#include "ElemType.h"
#include "Status.h"
#include <stddef.h>
#include <stdbool.h>

/* 兼容配置 */
#ifdef _WIN32
#ifdef EXPORT
#define ABT_API _declspec(dllexport)
#else
#define ABI_API _declspec(dllimport)
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
struct pos
{
    size_t level;       // 深度
    size_t order;       // 指定深度的位序
};
typedef struct pos Pos;
typedef Pos *PtrPos;
typedef const Pos *cPtrPos;

struct node
{
    ElemType data;
    bool used;      // 标志该结点是否被使用
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct tree
{
    PtrNode root;
    size_t size;
};
typedef struct tree Tree;
typedef Tree *PtrTree;
typedef const Tree *cPtrTree;

typedef int Branch;
#define RootBranch 0
#define LeftBranch 1
#define RightBranch 2

typedef int TravelWay;
#define PreOrder 3
#define InOrder 4
#define PostOrder 5

/* 函数接口 */

/*
 * 操作：构造空树
 * 参数：指定树的深度
 * 返回：构造的树
*/
ABT_API PtrTree DLL_CALL InitTree(size_t size);

/*
 * 操作：销毁树
 * 参数：待销毁树
*/
ABT_API void DLL_CALL DestroyTree(PtrTree tree);

/*
 * 操作：按照定义构造树
 * 参数：
 * 1. 结点类型的数组
 * 2. 数组的大小
 * 返回：构造的树
*/
ABT_API PtrTree DLL_CALL CreateTree(cPtrNode definition, size_t size);

/*
 * 操作：清空树
 * 参数：待清空树
*/
ABT_API void DLL_CALL ClearTree(PtrTree tree);

/*
 * 操作：判断树是否为空
 * 参数：待判断树
 * 返回：
 * 1. 若为空返回 true
 * 2. 否则返回 false
*/
ABT_API bool DLL_CALL TreeEmpty(cPtrTree tree);

/*
 * 操作：返回树的深度
 * 参数：树
 * 返回：树的深度
*/
ABT_API size_t DLL_CALL TreeDepth(cPtrTree tree);

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
ABT_API Status DLL_CALL Value(cPtrTree tree, cPtrPos pos, PtrElem elem);

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
ABT_API Status DLL_CALL Assign(PtrTree tree, cPtrPos pos, cPtrElem elem);

/*
 * 操作：返回树的根结点
 * 参数：树
 * 返回：根结点
*/
ABT_API PtrPos DLL_CALL Root(cPtrTree tree);

/*
 * 操作：返回指定结点的双亲
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若存在返回位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL Parent(cPtrTree tree, cPtrPos pos);

/*
 * 操作：返回指定结点的左孩子
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若存在则返回位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL LeftChild(cPtrTree tree, cPtrPos pos);

/*
 * 操作：返回指定结点的右兄弟
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若存在则返回位置
 * 2. 否则返回 NULL
*/
ABT_API PtrPos DLL_CALL RightSibling(cPtrTree tree, cPtrPos pos);

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
ABT_API Status DLL_CALL InsertChild(PtrTree tree, cPtrPos pos, Branch branch, cPtrTree subtree);

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
ABT_API Status DLL_CALL DeleteChild(PtrTree tree, cPtrPos pos, Branch branch, PtrTree subtree);

/*
 * 操作：打印树
 * 参数：
 * 1. 树
 * 2. 指定遍历方式
*/
ABT_API void DLL_CALL PrintTree(cPtrTree tree, TravelWay way);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif