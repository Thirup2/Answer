#ifndef TRIDIAMATRIX_H_
#define TRIDIAMATRIX_H_

#include "Compatible.h"
#include "ElemType.h"

// --------------------------------------- 头文件 --------------------------------------- //
#include "Status.h"

// --------------------------------------- 接 口 --------------------------------------- //
// 数据类型定义
typedef struct matrix
{
    PtrElem rows;
    int order;
    int n;
} Matrix, *PtrMatrix;

// 函数接口声明
DLL_API PtrMatrix InitMatrix(int order);
DLL_API bool ReadMatrix(PtrMatrix matrix, FILE *in);
DLL_API Status GetElem(PtrMatrix matrix, int i, int j, PtrElem elem);
DLL_API Status UpdateElem(PtrMatrix matrix, int i, int j, PtrElem elem);
DLL_API void DestroyMatrix(PtrMatrix matrix);
DLL_API void PrintMatrix(PtrMatrix matrix, FILE *out);

#endif