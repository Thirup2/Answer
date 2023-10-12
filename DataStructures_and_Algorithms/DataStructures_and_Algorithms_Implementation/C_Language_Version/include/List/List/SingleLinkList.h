#ifndef SINGLELINKLIST_H_
#define SINGLELINKLIST_H_

#include "Compatible.h"

// ------------------------------ 头文件 ------------------------------ //
#include "Coords.h"
#include "Status.h"

// ------------------------------ 接  口 ------------------------------ //
// 数据元素接口
typedef Coords ElemType;
typedef PtrCoords PtrElem;
#define MakeElem MakeCoords
#define CreateElem CreateCoords
#define DestroyElem DestroyCoords
#define CopyElems CopyCoords
#define EqualElems EqualCoords
#define PrintElem PrintCoords
#define ReadElem ReadCoords

// 类型定义
typedef struct node
{
    ElemType data;
    struct node* next;
}Node, * PtrNode, * PtrList;

// 函数接口
DLL_API PtrList InitList(void);
DLL_API int Length(PtrList list);
DLL_API int LocateElem(PtrList list, PtrElem elem);
DLL_API Status GetElem(PtrList list, int pos, PtrElem elem);
DLL_API Status ListInsert(PtrList list, int pos, PtrElem elem);
DLL_API Status ListDelete(PtrList list, int pos, PtrElem elem);
DLL_API void PrintList(PtrList list, FILE* out);
DLL_API bool Empty(PtrList list);
DLL_API void DestroyList(PtrList list);

#endif // !SINGLELINKLIST_H_