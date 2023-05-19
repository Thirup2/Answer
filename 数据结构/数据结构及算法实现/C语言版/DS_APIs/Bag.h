#ifndef BAG_H_
#define BAG_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define BAG_API _declspec(dllexport)
#else
#define BAG_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define BAG_API
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
struct bag
{
    PtrElem data;
    int capacity;
    int length;
};
typedef struct bag Bag;
typedef Bag *PtrBag;
typedef const Bag *cPtrBag;

// 函数接口
BAG_API PtrBag DLL_CALL CreateBag(void);                    // 创建空背包
BAG_API Status DLL_CALL Add(PtrBag bag, cPtrElem elem);     // 往背包添加元素
BAG_API bool DLL_CALL BagEmpty(cPtrBag bag);                // 判断背包是否为空
BAG_API int DLL_CALL Size(cPtrBag bag);                     // 返回背包的大小
BAG_API void DLL_CALL DestroyBag(PtrBag bag);               // 销毁背包

// 迭代功能
typedef PtrElem Iterator;
typedef cPtrElem constIterator;
BAG_API Iterator DLL_CALL Begin(PtrBag bag);
BAG_API Iterator DLL_CALL End(PtrBag bag);
BAG_API Iterator DLL_CALL Next(Iterator pre);
BAG_API constIterator DLL_CALL cBegin(cPtrBag bag);
BAG_API constIterator DLL_CALL cEnd(cPtrBag bag);
BAG_API constIterator DLL_CALL cNext(constIterator pre);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif