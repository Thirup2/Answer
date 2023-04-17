#ifndef LIST_H_
#define LIST_H_

// --------------------------- 包含头文件 --------------------------- //
#include "Coordinate.h"
#include "Status.h"
#include <stddef.h>
#include <stdbool.h>

// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define LIST_API _declspec(dllexport)
#else
#define LIST_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define LIST_API
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
    struct node *pre;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct list
{
    PtrNode head;
    PtrNode last;
    size_t size;
};
typedef struct list List;
typedef List *PtrList;
typedef const List *cPtrList;

// 函数接口声明
// 构造链表
LIST_API PtrList DLL_CALL InitList(void);
LIST_API PtrList DLL_CALL CreateList(cPtrNode begin, cPtrNode end);
LIST_API PtrList DLL_CALL CopyList(cPtrList copied);
LIST_API PtrList DLL_CALL MakeList(size_t n, cPtrElem elem);
// 清空链表
LIST_API void DLL_CALL ClearList(PtrList list);
// 销毁链表
LIST_API void DLL_CALL DestroyList(PtrList list);
// 基本信息
LIST_API bool DLL_CALL ListEmpty(cPtrList list);
LIST_API size_t DLL_CALL ListLength(cPtrList list);
// 改变元素
LIST_API Status DLL_CALL PushBack(PtrList list, cPtrElem elem);
LIST_API Status DLL_CALL PopBack(PtrList list, PtrElem elem);
LIST_API Status DLL_CALL PushFront(PtrList list, cPtrElem elem);
LIST_API Status DLL_CALL PopFront(PtrList list, PtrElem elem);
LIST_API Status DLL_CALL PlaceInsert(PtrList list, PtrNode place, cPtrElem elem);
LIST_API Status DLL_CALL PlaceDelete(PtrList list, PtrNode place, PtrElem elem);
LIST_API Status DLL_CALL ListInsert(PtrList list, size_t i, cPtrElem elem);
LIST_API Status DLL_CALL ListDelete(PtrList list, size_t i, PtrElem elem);
// 遍历
LIST_API void DLL_CALL PrintList(cPtrList list);
// 迭代器操作
LIST_API PtrNode DLL_CALL Begin(PtrList list);
LIST_API PtrNode DLL_CALL End(PtrList list);
LIST_API PtrNode DLL_CALL Next(PtrNode now);
LIST_API cPtrNode DLL_CALL cBegin(cPtrList list);
LIST_API cPtrNode DLL_CALL cEnd(cPtrList list);
LIST_API cPtrNode DLL_CALL cNext(cPtrNode now);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif