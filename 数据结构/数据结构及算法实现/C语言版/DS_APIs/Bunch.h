#ifndef BUNCH_H_
#define BUNCH_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define BUNCH_API _declspec(dllexport)
#else
#define BUNCH_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define BUNCH_API
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

struct bunch
{
    PtrNode head;
    int size;
};
typedef struct bunch Bunch;
typedef Bunch *PtrBunch;
typedef const Bunch *cPtrBunch;

// 函数接口
BUNCH_API PtrBunch DLL_CALL CreateBunch(void);
BUNCH_API Status DLL_CALL Add(PtrBunch bunch, cPtrElem elem);
BUNCH_API bool DLL_CALL BunchEmpty(cPtrBunch bunch);
BUNCH_API int DLL_CALL Size(cPtrBunch bunch);
BUNCH_API void DLL_CALL DestroyBunch(PtrBunch bunch);

// 迭代功能
typedef PtrNode Iterator;
typedef cPtrNode constIterator;
BUNCH_API PtrElem DLL_CALL StarIter(Iterator iter);
BUNCH_API cPtrElem DLL_CALL StarConstIter(constIterator iter);
BUNCH_API Iterator DLL_CALL Begin(PtrBunch bunch);
BUNCH_API Iterator DLL_CALL End(PtrBunch bunch);
BUNCH_API Iterator DLL_CALL Next(Iterator pre);
BUNCH_API constIterator DLL_CALL cBegin(cPtrBunch bunch);
BUNCH_API constIterator DLL_CALL cEnd(cPtrBunch bunch);
BUNCH_API constIterator DLL_CALL cNext(constIterator pre);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif