#ifndef FORWARDLIST_H_
#define FORWARDLIST_H_

// --------------------------- 包含头文件 --------------------------- //
#include "Coordinate.h"
#include "Status.h"
#include <stddef.h>
#include <stdbool.h>

// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define FORWARDLIST_API _declspec(dllexport)
#else
#define FORWARDLIST_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define FORWARDLIST_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

// ---------------------------   接口    --------------------------- //

// 元素接口
typedef Coordinate ElemType;
typedef PtrCoord PtrElem;
typedef cPtrCoord cPtrElem;
#define AssignElem AssignCoordByCopy
#define PrintElem PrintCoord

// 类型定义
struct node
{
    ElemType elem;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct list
{
    PtrNode head;
    size_t length;
};
typedef struct list ForwardList;
typedef ForwardList *PtrFlist;
typedef const ForwardList *cPtrFlist;

// 函数接口声明
// 构造链表
FORWARDLIST_API PtrFlist DLL_CALL InitList(void);
FORWARDLIST_API PtrFlist DLL_CALL CreateFlist(cPtrNode begin, cPtrNode end);
FORWARDLIST_API PtrFlist DLL_CALL CopyFlist(cPtrFlist copied);
FORWARDLIST_API PtrFlist DLL_CALL MakeFlist(size_t n, cPtrElem elem);
// 清空链表
FORWARDLIST_API void DLL_CALL ClearList(PtrFlist list);
// 销毁链表
FORWARDLIST_API void DLL_CALL DestroyList(PtrFlist list);
// 基本信息
FORWARDLIST_API bool DLL_CALL ListEmpty(cPtrFlist list);
FORWARDLIST_API size_t DLL_CALL ListLength(cPtrFlist list);
// 改变元素
FORWARDLIST_API Status DLL_CALL PushFront(PtrFlist list, cPtrElem elem);
FORWARDLIST_API Status DLL_CALL PopFront(PtrFlist list, PtrElem elem);
FORWARDLIST_API Status DLL_CALL InsertAfter(PtrFlist list, PtrNode place, cPtrElem elem);
FORWARDLIST_API Status DLL_CALL DeleteAfter(PtrFlist list, PtrNode place, PtrElem elem);
FORWARDLIST_API Status DLL_CALL ListInsert(PtrFlist list, size_t i, cPtrElem elem);
FORWARDLIST_API Status DLL_CALL ListDelete(PtrFlist list, size_t i, PtrElem elem);
// 遍历
FORWARDLIST_API void DLL_CALL PrintList(cPtrFlist list);
// 迭代器操作
FORWARDLIST_API PtrNode DLL_CALL Begin(PtrFlist list);
FORWARDLIST_API PtrNode DLL_CALL End(PtrFlist list);
FORWARDLIST_API PtrNode DLL_CALL Next(PtrNode now);
FORWARDLIST_API cPtrNode DLL_CALL cBegin(cPtrFlist list);
FORWARDLIST_API cPtrNode DLL_CALL cEnd(cPtrFlist list);
FORWARDLIST_API cPtrNode DLL_CALL cNext(cPtrNode now);
FORWARDLIST_API PtrNode DLL_CALL FrontInserter(PtrFlist list);
FORWARDLIST_API PtrNode DLL_CALL InsertNext(PtrNode now);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif