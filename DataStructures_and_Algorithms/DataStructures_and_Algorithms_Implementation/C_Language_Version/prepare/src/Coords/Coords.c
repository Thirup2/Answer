#include "Coords.h"
#include <stdio.h>
#include <stdlib.h>

// 局部函数声明
// 无

// 接口函数定义
PtrCoords CreateCoords(int x, int y)
{
    PtrCoords co = GetCoords();
    co->x = x;
    co->y = y;
    return co;
}
PtrCoords GetCoords(void)
{
    PtrCoords co = (PtrCoords) malloc(sizeof(Coords));
    if (!co) {
        printf("Faild to Alloc!\n");
        exit(EXIT_FAILURE);
    }
    return co;
}
void DestroyCoords(PtrCoords elem)
{
    free(elem);
}
void CopyCoords(PtrCoords elem, cPtrCoords copied)
{
    elem->x = copied->x;
    elem->y = copied->y;
}
bool EqualCoords(cPtrCoords elem1, cPtrCoords elem2)
{
    return elem1->x == elem2->x && elem1->y == elem2->y;
}
void PrintCoords(cPtrCoords elem)
{
    printf("(%d, %d)", elem->x, elem->y);
}
bool ReadCoords(PtrCoords elem)
{
    printf("Please input a coord like \"x, y\": ");
    int x = elem->x;
    int y = elem->y;
    if (scanf("%d, %d", &elem->x, &elem->y) == 2) {
        while (getchar() != '\n');
        return true;
    } else {
        while (getchar() != '\n');
        elem->x = x;
        elem->y = y;
        return false;
    }
}

// 局部函数定义
// 无