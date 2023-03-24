/* 链式二叉树接口头文件 */
#ifndef LINKBITREE_H_
#define LINKBITREE_H_

/* 包含头文件 */
#include "Status.h"
#include "ElemType.h"
#include <stdbool.h>
#include <stddef.h>

/* 兼容配置 */
#ifdef _WIN32
#ifdef EXPORT
#define LBT_API _declspec(dllexport)
#else
#define LBT_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define LBT_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 链式二叉树类型定义 */
struct tree
{
    ElemType root;
    struct tree *leftchild;
    struct tree *rightchild;
};
typedef struct tree Tree;
typedef Tree *PtrTree;
typedef const Tree *cPtrTree;
typedef PtrTree *PtoPTree;
typedef const PtrTree *cPtoPTree;

typedef PtrTree Position;
typedef cPtrTree cPosition;

enum travelway
{
    PreOrder,
    InOrder,
    PostOrder
};
typedef enum travelway TravelWay;

enum branch
{
    Left,
    Right
};
typedef enum branch Branch;

/* 链式二叉树函数接口 */

/*
 * 操作：构造空树
 * 返回：空树指针
*/
LBT_API PtoPTree DLL_CALL InitTree(void);

/*
 * 操作：销毁树
 * 参数：待销毁树
*/
LBT_API void DLL_CALL DestroyTree(PtoPTree tree);

/*
 * 操作：根据输入构造树
 * 返回：构造的树
*/
LBT_API PtoPTree DLL_CALL CreateTree(void);

/*
 * 操作：清空树
 * 参数：待清空树
*/
LBT_API void DLL_CALL ClearTree(PtrTree tree);

/*
 * 操作：判断树是否为空
 * 参数：待判断树
 * 返回：
 * 1. 若为空返回 true
 * 2. 否则返回 false
*/
LBT_API bool DLL_CALL TreeEmpty(cPtrTree tree);

/*
 * 操作：返回树的深度
 * 参数：待计算树
 * 返回：树的深度（0为空树）
*/
LBT_API size_t DLL_CALL TreeDepth(cPtrTree tree);

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
LBT_API Status DLL_CALL Value(cPtrTree tree, cPosition pos, PtrElem elem);

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
LBT_API Status DLL_CALL Assign(PtrTree tree, cPosition pos, cPtrElem elem);

/*
 * 操作：返回树的根结点位置
 * 参数：树
 * 返回：根结点位置，若为空返回 NULL
*/
LBT_API Position DLL_CALL Root(cPtrTree tree);

/*
 * 操作：查找指定元素的位置
 * 参数：
 * 1. 树
 * 2. 指定元素
 * 返回：
 * 1. 若无该元素则返回 NULL
 * 2. 否则返回该元素的位置
*/
LBT_API Position DLL_CALL FindElem(cPtrElem elem);

/*
 * 操作：返回指定结点的双亲位置
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若双亲不存在返回 NULL
 * 2. 否则返回双亲的位置
*/
LBT_API Position DLL_CALL Parents(cPtrTree tree, cPosition pointed);

/*
 * 操作：返回指定结点的左孩子位置
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若左孩子不存在返回 NULL
 * 2. 否则返回左孩子的位置
*/
LBT_API Position DLL_CALL LeftChild(cPtrTree tree, cPosition pointed);

/*
 * 操作：返回指定结点的右兄弟位置
 * 参数：
 * 1. 树
 * 2. 指定结点
 * 返回：
 * 1. 若右兄弟不存在返回 NULL
 * 2. 否则返回右兄弟的位置
*/
LBT_API Position DLL_CALL RightSibling(cPtrTree tree, cPosition pointed);

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
LBT_API Status DLL_CALL InsertChild(PtrTree tree, cPosition pointed, Branch branch, cPtrTree subtree);

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
LBT_API Status DLL_CALL DeleteChild(PtrTree tree, cPosition pointed, Branch branch, PtrTree subtree);

/*
 * 操作：打印树
 * 参数：
 * 1. 树
 * 2. 遍历方式
*/
LBT_API void DLL_CALL PrintTree(cPtrTree tree, TravelWay travelway);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif