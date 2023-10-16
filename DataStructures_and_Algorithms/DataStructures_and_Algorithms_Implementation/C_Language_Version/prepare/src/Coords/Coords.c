#define EXPORT
#include "Coords.h"
#include <stdlib.h>

// 局部函数声明
// 无

// 接口函数定义
DLL_API PtrCoords CreateCoords(void)
{
    PtrCoords co = (PtrCoords) malloc(sizeof(Coords));
    if (!co) {
        printf("Faild to Alloc!\n");
        exit(EXIT_FAILURE);
    }
    return co;
}
DLL_API void DestroyCoords(PtrCoords elem)
{
    free(elem);
}
DLL_API void CopyCoords(PtrCoords elem, PtrCoords copied)
{
    elem->x = copied->x;
    elem->y = copied->y;
}
DLL_API bool EqualCoords(PtrCoords elem1, PtrCoords elem2)
{
    return elem1->x == elem2->x && elem1->y == elem2->y;
}
DLL_API void PrintCoords(PtrCoords elem, FILE* out)
{
    fprintf(out, "(%d, %d)", elem->x, elem->y);
}
DLL_API bool ReadCoords(PtrCoords elem, FILE* in)
{
    return fscanf(in, "%d,%d", &elem->x, &elem->y);
}

// 局部函数定义
// 无