#define EXPORT
// ----------------------包含头文件---------------------- //
#include "Coordinate.h"
#include <stdlib.h>
#include <stdio.h>

// ----------------------接口---------------------- //

// 局部函数声明
/*
 * 操作：整数转换为字符串
 * 参数：待转换整数
 * 返回：转换后的字符串
*/
static size_t bits(int i);

// 接口函数定义
PtrCoord DLL_CALL InitCoord(void)
{
    PtrCoord coord = (PtrCoord) malloc(sizeof(Coordinate));
    if (!coord) {
        exit(EXIT_FAILURE);
    }
    return coord;
}

PtrCoord DLL_CALL CreateCoord(int x, int y)
{
    PtrCoord coord = (PtrCoord) malloc(sizeof(Coordinate));
    if (!coord) {
        exit(EXIT_FAILURE);
    }
    coord->x = x;
    coord->y = y;
    return coord;
}

PtrCoord DLL_CALL CopyCoord(cPtrCoord coord)
{
    PtrCoord copycoord = (PtrCoord) malloc(sizeof(Coordinate));
    if (!copycoord) {
        exit(EXIT_FAILURE);
    }
    copycoord->x = coord->x;
    copycoord->y = coord->y;
    return copycoord;
}

void DLL_CALL DestroyCoord(PtrCoord coord)
{
    free(coord);
}

void DLL_CALL AssignCoordByValue(PtrCoord coord, int x, int y)
{
    coord->x = x;
    coord->y = y;
}

void DLL_CALL AssignCoordByCopy(PtrCoord coord, cPtrCoord copycoord)
{
    coord->x = copycoord->x;
    coord->y = copycoord->y;
}

const char *DLL_CALL CoordToString(cPtrCoord coord)
{
    size_t size = 5 + bits(coord->x) + bits(coord->y);
    char *str = (char *) malloc(size * sizeof(char));
    if (!str) {
        exit(EXIT_FAILURE);
    }
    sprintf(str, "(%d, %d)", coord->x, coord->y);
    return str;
}

bool DLL_CALL CompareCoords(cPtrCoord coord1, cPtrCoord coord2)
{
    if ((coord1->x == coord2->x) && (coord1->y == coord2->y)) {
        return true;
    }
    return false;
}

bool DLL_CALL ReadCoord(PtrCoord coord)
{
    int x, y;
    if (scanf("%d, %d", &x, &y) == 2) {
        AssignCoordByValue(coord, x, y);
        return true;
    }
    return false;
}

COORD_API void DLL_CALL PrintCoord(cPtrCoord coord)
{
    printf("%s", CoordToString(coord));
}

// 局部函数定义

static size_t bits(int i)
{
    if (i == 0) {
        return 1;
    }
    size_t bit = 0;
    while (i != 0) {
        bit++;
        i /= 10;
    }
    return bit;
}