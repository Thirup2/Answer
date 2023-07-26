#ifndef DOUBLELINKLIST_H_
#define DOUBLELINKLIST_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define DOUBLELLIST_API _declspec(dllexport)
#else
#define DOUBLELLIST_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define DOUBLELLIST_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

// --------------------------- 包含头文件 --------------------------- //
#include "Coords.h"
#include "Status.h"
#include <stdbool.h>

// ---------------------------    接口    --------------------------- //
// 元素类型接口
typedef Coords ElemType;
typedef PtrCoords PtrElem;
typedef cPtrCoords cPtrElem;
#define CopyElems CopyCoords
#define EqualElems EqualCoords
#define PrintElem PrintCoords
#define ReadElem ReadCoords

// 类型定义
struct node
{
    ElemType data;
    struct node *pre;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct doublellist
{
    PtrNode head;
    PtrNode last;
};
typedef struct doublellist DoubleLList;

// 函数接口
DOUBLELLIST_API DoubleLList DLL_CALL InitList(void);
DOUBLELLIST_API int DLL_CALL Length(DoubleLList list);
DOUBLELLIST_API int DLL_CALL LocateElem(DoubleLList list, cPtrElem elem);
DOUBLELLIST_API PtrElem DLL_CALL GetElem(DoubleLList list, int i);
DOUBLELLIST_API Status DLL_CALL ListInsert(DoubleLList list, int i, cPtrElem elem);
DOUBLELLIST_API Status DLL_CALL ListDelete(DoubleLList list, int i, PtrElem elem);
DOUBLELLIST_API bool DLL_CALL Empty(DoubleLList list);
DOUBLELLIST_API void DLL_CALL DestroyList(DoubleLList list);

// 迭代功能
typedef PtrNode Iterator, reverseIterator;
typedef cPtrNode constIterator, constReverseIterator;
DOUBLELLIST_API PtrElem DLL_CALL StarIter(Iterator iter);
DOUBLELLIST_API cPtrElem DLL_CALL StarConstIter(constIterator iter);
DOUBLELLIST_API Iterator DLL_CALL Begin(DoubleLList list);
DOUBLELLIST_API Iterator DLL_CALL End(DoubleLList list);
DOUBLELLIST_API Iterator DLL_CALL Next(Iterator pre);
DOUBLELLIST_API constIterator DLL_CALL cBegin(DoubleLList list);
DOUBLELLIST_API constIterator DLL_CALL cEnd(DoubleLList list);
DOUBLELLIST_API constIterator DLL_CALL cNext(constIterator pre);
DOUBLELLIST_API reverseIterator DLL_CALL rBegin(DoubleLList list);
DOUBLELLIST_API reverseIterator DLL_CALL rEnd(DoubleLList list);
DOUBLELLIST_API reverseIterator DLL_CALL rNext(reverseIterator pre);
DOUBLELLIST_API constReverseIterator DLL_CALL rcBegin(DoubleLList list);
DOUBLELLIST_API constReverseIterator DLL_CALL rcEnd(DoubleLList list);
DOUBLELLIST_API constReverseIterator DLL_CALL rcNext(constReverseIterator pre);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif