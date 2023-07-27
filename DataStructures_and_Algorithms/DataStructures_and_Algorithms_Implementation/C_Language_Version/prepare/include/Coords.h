#ifndef COORDS_H_
#define COORDS_H_

// -------------------------------- 头文件 -------------------------------- //
#include <stdbool.h>

// -------------------------------- 接  口 -------------------------------- //
// 类型定义
struct coords
{
    int x;
    int y;
};
typedef struct coords Coords;
typedef Coords *PtrCoords;
typedef const Coords *cPtrCoords;

// 函数接口
PtrCoords CreateCoords(int x, int y);
PtrCoords GetCoords(void);
void DestroyCoords(PtrCoords elem);
void CopyCoords(PtrCoords elem, cPtrCoords copied);
bool EqualCoords(cPtrCoords elem1, cPtrCoords elem2);
void PrintCoords(cPtrCoords elem);
bool ReadCoords(PtrCoords elem);

#endif