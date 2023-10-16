#ifndef COORDS_H_
#define COORDS_H_

#include "Compatible.h"

// -------------------------------- 头文件 -------------------------------- //
#include <stdbool.h>
#include <stdio.h>

// -------------------------------- 接  口 -------------------------------- //
// 类型定义
typedef struct coords
{
    int x;
    int y;
}Coords, * PtrCoords;

// 函数接口
DLL_API PtrCoords CreateCoords(void);
DLL_API PtrCoords MakeCoords(int x, int y);
DLL_API void DestroyCoords(PtrCoords elem);
DLL_API void CopyCoords(PtrCoords elem, PtrCoords copied);
DLL_API bool EqualCoords(PtrCoords elem1, PtrCoords elem2);
DLL_API void PrintCoords(PtrCoords elem, FILE* out);
DLL_API bool ReadCoords(PtrCoords elem, FILE* in);

#endif