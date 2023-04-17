#ifndef VECTOR_H_
#define VECTOR_H_

// --------------------------- 包含头文件 --------------------------- //
#include "Coordinate.h"
#include "Status.h"
#include <stddef.h>
#include <stdbool.h>

// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define VECTOR_API _declspec(dllexport)
#else
#define VECTOR_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define VECTOR_API
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

// 类型定义
struct vector
{
    PtrElem data;
    size_t length;
    size_t capacity;
};
typedef struct vector Vector;
typedef Vector *PtrVector;
typedef const Vector *cPtrVector;

// 函数接口声明

// 构造数组
VECTOR_API PtrVector DLL_CALL InitVector(void);
VECTOR_API PtrVector DLL_CALL CreateVector(size_t size, cPtrElem elem);
VECTOR_API PtrVector DLL_CALL CopyVector(cPtrVector copied);

// 清空数组
VECTOR_API void DLL_CALL ClearVector(PtrVector vector);

// 销毁数组
VECTOR_API void DLL_CALL DestroyVector(PtrVector vector);

// 基本信息
VECTOR_API bool DLL_CALL VectorEmpty(cPtrVector vector);
VECTOR_API size_t DLL_CALL VectorLength(cPtrVector vector);

// 改变元素
VECTOR_API void DLL_CALL CopyAssign(PtrVector vector, cPtrVector copied);
VECTOR_API Status DLL_CALL PushBack(PtrVector vector, cPtrElem elem);
VECTOR_API Status DLL_CALL PopBack(PtrVector vector, PtrElem elem);
VECTOR_API Status DLL_CALL VectorInsert(PtrVector vector, size_t i, cPtrElem elem);
VECTOR_API Status DLL_CALL VectorDelete(PtrVector vector, size_t i, PtrElem elem);

// 访问
VECTOR_API Status DLL_CALL GetElem(cPtrVector vector, size_t i, PtrElem elem);
VECTOR_API void DLL_CALL PrintVector(cPtrVector vector);

// 迭代器操作
VECTOR_API PtrElem DLL_CALL Begin(PtrVector vector);
VECTOR_API PtrElem DLL_CALL End(PtrVector vector);
VECTOR_API PtrElem DLL_CALL Next(PtrElem now);
VECTOR_API cPtrElem DLL_CALL cBegin(cPtrVector vector);
VECTOR_API cPtrElem DLL_CALL cEnd(cPtrVector vector);
VECTOR_API cPtrElem DLL_CALL cNext(cPtrElem now);

// 算法
VECTOR_API void DLL_CALL SortVector(PtrVector vector);
VECTOR_API size_t DLL_CALL SearchElem(PtrVector vector, cPtrElem elem);
VECTOR_API void DLL_CALL DeleteRepeat(PtrVector vector);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif