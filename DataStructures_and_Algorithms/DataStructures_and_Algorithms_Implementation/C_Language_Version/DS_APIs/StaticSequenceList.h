#ifndef STATICSEQUENCELIST_H_
#define STATICSEQUENCELIST_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define SSLIST_API _declspec(dllexport)
#else
#define SSLIST_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define SSLIST_API
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
#define MAXSIZE 10
struct sslist
{
    ElemType data[MAXSIZE + 1];
    int length;
};
typedef struct sslist SSList;
typedef SSList *PtrSSList;
typedef const SSList *cPtrSSList;

// 函数接口
SSLIST_API PtrSSList DLL_CALL InitList(void);
SSLIST_API int DLL_CALL Length(cPtrSSList list);
SSLIST_API int DLL_CALL LocateElem(PtrSSList list, cPtrElem elem);
SSLIST_API PtrElem DLL_CALL GetElem(PtrSSList list, int i);
SSLIST_API Status DLL_CALL ListInsert(PtrSSList list, int i, cPtrElem elem);
SSLIST_API Status DLL_CALL ListDelete(PtrSSList list, int i, PtrElem elem);
SSLIST_API bool DLL_CALL Empty(cPtrSSList list);
SSLIST_API void DLL_CALL DestroyList(PtrSSList list);

// 迭代功能
typedef PtrElem Iterator;
typedef cPtrElem constIterator;
SSLIST_API Iterator DLL_CALL Begin(PtrSSList list);
SSLIST_API Iterator DLL_CALL End(PtrSSList list);
SSLIST_API Iterator DLL_CALL Next(Iterator pre);
SSLIST_API constIterator DLL_CALL cBegin(cPtrSSList list);
SSLIST_API constIterator DLL_CALL cEnd(cPtrSSList list);
SSLIST_API constIterator DLL_CALL cNext(constIterator pre);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif


#endif