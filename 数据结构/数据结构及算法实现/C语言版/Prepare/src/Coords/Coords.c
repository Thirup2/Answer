#define EXPORT

#include "Coords.h"
#include <stdio.h>

// 局部函数声明

// 接口函数定义
void DLL_CALL CopyCoords(PtrCoords elem, cPtrCoords copied)
{
    elem->x = copied->x;
    elem->y = copied->y;
}
bool DLL_CALL EqualCoords(cPtrCoords elem1, cPtrCoords elem2)
{
    return elem1->x == elem2->x && elem1->y == elem2->y;
}
void DLL_CALL PrintCoords(cPtrCoords elem)
{
    printf("(%d, %d)", elem->x, elem->y);
}
bool DLL_CALL ReadCoords(PtrCoords elem)
{
    printf("请按照括号内的格式输入 (x, y)：");
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