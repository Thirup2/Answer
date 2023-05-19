#ifndef SINGLELINKLIST_H_
#define SINGLELINKLIST_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define SINGLELLIST_API _declspec(dllexport)
#else
#define SINGLELLIST_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define SINGLELLIST_API
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
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct singlellist
{
    PtrNode head;
};
typedef struct singlellist SingleLList;

// 函数接口
SINGLELLIST_API SingleLList DLL_CALL InitList(void);
SINGLELLIST_API int DLL_CALL Length(SingleLList list);
SINGLELLIST_API int DLL_CALL LocateElem(SingleLList list, cPtrElem elem);
SINGLELLIST_API PtrElem DLL_CALL GetElem(SingleLList list, int i);
SINGLELLIST_API Status DLL_CALL ListInsert(SingleLList list, int i, cPtrElem elem);
SINGLELLIST_API Status DLL_CALL ListDelete(SingleLList list, int i, PtrElem elem);
SINGLELLIST_API bool DLL_CALL Empty(SingleLList list);
SINGLELLIST_API void DLL_CALL DestroyList(SingleLList list);

// 迭代功能
typedef PtrNode Iterator;
typedef cPtrNode constIterator;
SINGLELLIST_API PtrElem DLL_CALL StarIter(Iterator iter);
SINGLELLIST_API cPtrElem DLL_CALL StarConstIter(constIterator iter);
SINGLELLIST_API Iterator DLL_CALL Begin(SingleLList list);
SINGLELLIST_API Iterator DLL_CALL End(SingleLList list);
SINGLELLIST_API Iterator DLL_CALL Next(Iterator pre);
SINGLELLIST_API constIterator DLL_CALL cBegin(SingleLList list);
SINGLELLIST_API constIterator DLL_CALL cEnd(SingleLList list);
SINGLELLIST_API constIterator DLL_CALL cNext(constIterator pre);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif