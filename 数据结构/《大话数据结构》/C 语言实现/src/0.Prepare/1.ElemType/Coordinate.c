#define EXPORT

// ----------------------包含头文件---------------------- //
#include "Coordinate.h"
#include <stdlib.h>
#include <stdio.h>

// ----------------------接口实现---------------------- //

// 函数接口定义

PtrCoord DLL_CALL InitCoord(void)
{
    PtrCoord cor = (PtrCoord) malloc(sizeof(Coordinate));
    if (!cor) {
        exit(EXIT_FAILURE);
    }
    cor->x = 0;
    cor->y = 0;
    return cor;
}
PtrCoord DLL_CALL CreateCoord(int x, int y)
{
    PtrCoord cor = (PtrCoord) malloc(sizeof(Coordinate));
    if (!cor) {
        exit(EXIT_FAILURE);
    }
    cor->x = x;
    cor->y = y;
    return cor;
}
PtrCoord DLL_CALL CopyCoord(cPtrCoord coord)
{
    PtrCoord cor = (PtrCoord) malloc(sizeof(Coordinate));
    if (!cor) {
        exit(EXIT_FAILURE);
    }
    cor->x = coord->x;
    cor->y = coord->y;
    return cor;
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

bool DLL_CALL ReadCoord(PtrCoord coord)
{
    int x = coord->x;
    int y = coord->y;
    if (scanf("%d, %d", &coord->x, &coord->y) != 2) {
        coord->x = x;
        coord->y = y;
        return false;
    }
    return true;
}
void DLL_CALL PrintCoord(cPtrCoord coord)
{
    printf("(%d, %d)", coord->x, coord->y);
}

bool DLL_CALL Equals(cPtrCoord cor1, cPtrCoord cor2)
{
    return ((cor1->x == cor2->x) && (cor1->y == cor2->y));
}
bool DLL_CALL Nequal(cPtrCoord cor1, cPtrCoord cor2)
{
    return !Equals(cor1, cor2);
}

bool DLL_CALL Less(cPtrCoord cor1, cPtrCoord cor2)
{
    return ((cor1->x < cor2->x) || ((cor1->x == cor2->x) && (cor1->y < cor2->y)));
}
bool DLL_CALL Lequal(cPtrCoord cor1, cPtrCoord cor2)
{
    return (Less(cor1, cor2) || Equals(cor1, cor2));
}
bool DLL_CALL Greater(cPtrCoord cor1, cPtrCoord cor2)
{
    return !Lequal(cor1, cor2);
}
bool DLL_CALL Gequal(cPtrCoord cor1, cPtrCoord cor2)
{
    return !Less(cor1, cor2);
}