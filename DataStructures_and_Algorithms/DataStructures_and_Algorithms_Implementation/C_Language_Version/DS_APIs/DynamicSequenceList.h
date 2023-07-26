#ifndef DYNAMICSEQUENCELIST_H_
#define DYNAMICSEQUENCELIST_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define DSLIST_API _declspec(dllexport)
#else
#define DSLIST_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define DSLIST_API
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
struct dslist
{
    PtrElem data;
    int size;
    int length;
};
typedef struct dslist DSList;
typedef DSList *PtrDSList;
typedef const DSList *cPtrDSList;

// 函数接口
DSLIST_API PtrDSList DLL_CALL InitList(void);
DSLIST_API int DLL_CALL Length(cPtrDSList list);
DSLIST_API int DLL_CALL LocateElem(PtrDSList list, cPtrElem elem);
DSLIST_API PtrElem DLL_CALL GetElem(PtrDSList list, int i);
DSLIST_API Status DLL_CALL ListInsert(PtrDSList list, int i, cPtrElem elem);
DSLIST_API Status DLL_CALL ListDelete(PtrDSList list, int i, PtrElem elem);
DSLIST_API bool DLL_CALL Empty(cPtrDSList list);
DSLIST_API void DLL_CALL DestroyList(PtrDSList list);

// 迭代功能
typedef PtrElem Iterator;
typedef cPtrElem constIterator;
DSLIST_API Iterator DLL_CALL Begin(PtrDSList list);
DSLIST_API Iterator DLL_CALL End(PtrDSList list);
DSLIST_API Iterator DLL_CALL Next(Iterator pre);
DSLIST_API constIterator DLL_CALL cBegin(cPtrDSList list);
DSLIST_API constIterator DLL_CALL cEnd(cPtrDSList list);
DSLIST_API constIterator DLL_CALL cNext(constIterator pre);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif