#ifndef CONSTANTVOLUMEARRAY_H_
#define CONSTANTVOLUMEARRAY_H_

// --------------------------- 包含头文件 --------------------------- //
#include "Coordinate.h"
#include "Status.h"
#include <stddef.h>
#include <stdbool.h>

// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define CONSTVA_API _declspec(dllexport)
#else
#define CONSTVA_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define CONSTVA_API
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
#define Less Less
#define Equal Equals
#define InitElem InitCoord
#define CreateElem CreateCoord
#define CopyElem CopyCoord
#define ReadElem ReadCoord

// 类型定义
struct constantvolumearray
{
    PtrElem data;
    size_t size;
    size_t length;
};
typedef struct constantvolumearray ConstantVolumeArray;
typedef ConstantVolumeArray *PtrConstVA;
typedef const ConstantVolumeArray *cPtrConstVA;

// 函数接口声明

// 构造数组
CONSTVA_API PtrConstVA DLL_CALL InitArray(size_t size);
CONSTVA_API PtrConstVA DLL_CALL CreateArray(size_t size, cPtrElem elem);
CONSTVA_API PtrConstVA DLL_CALL CopyArray(cPtrConstVA copied);

// 清空数组
CONSTVA_API void DLL_CALL ClearArray(PtrConstVA array);

// 销毁数组
CONSTVA_API void DLL_CALL DestroyArray(PtrConstVA array);

// 基本信息
CONSTVA_API bool DLL_CALL ArrayEmpty(cPtrConstVA array);
CONSTVA_API bool DLL_CALL ArrayFull(cPtrConstVA array);
CONSTVA_API size_t DLL_CALL ArrayLength(cPtrConstVA array);

// 改变元素
CONSTVA_API void DLL_CALL CopyAssign(PtrConstVA array, cPtrConstVA copied);
CONSTVA_API Status DLL_CALL PushBack(PtrConstVA array, cPtrElem elem);
CONSTVA_API Status DLL_CALL PopBack(PtrConstVA array, PtrElem elem);
CONSTVA_API Status DLL_CALL ArrayInsert(PtrConstVA array, size_t i, cPtrElem elem);
CONSTVA_API Status DLL_CALL ArrayDelete(PtrConstVA array, size_t i, PtrElem elem);

// 访问
CONSTVA_API Status DLL_CALL GetElem(cPtrConstVA array, size_t i, PtrElem elem);
CONSTVA_API void DLL_CALL PrintArray(cPtrConstVA array);

// 迭代器操作
CONSTVA_API PtrElem DLL_CALL Begin(PtrConstVA array);
CONSTVA_API PtrElem DLL_CALL End(PtrConstVA array);
CONSTVA_API PtrElem DLL_CALL Next(PtrElem elem);
CONSTVA_API cPtrElem DLL_CALL cBegin(cPtrConstVA array);
CONSTVA_API cPtrElem DLL_CALL cEnd(cPtrConstVA array);
CONSTVA_API cPtrElem DLL_CALL cNext(cPtrElem elem);

// 算法
CONSTVA_API void DLL_CALL SortArray(PtrConstVA array);
CONSTVA_API size_t DLL_CALL SearchElem(PtrConstVA array, cPtrElem elem);
CONSTVA_API void DLL_CALL DeleteRepeat(PtrConstVA array);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif