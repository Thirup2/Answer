#ifndef STATICSEQLIST_H_
#define STATICSEQLIST_H_

// ----------------------------------- 头文件 ----------------------------------- //
#include "Coords.h"
#include "Status.h"
#include <stdbool.h>

// ----------------------------------- 接  口 ----------------------------------- //
// 数据元素抽象
typedef Coords ElemType;
typedef PtrCoords PtrElem;
typedef cPtrCoords cPtrElem;
#define MakeElem CreateCoords
#define CreateElem GetCoords
#define DestroyElem DestroyCoords
#define CopyElems CopyCoords
#define EqualElems EqualCoords
#define PrintElem PrintCoords
#define ReadElem ReadCoords

// 类型定义
#define MAXSIZE 10
struct list
{
    ElemType data[MAXSIZE];
    int length;
};
typedef struct list StaticSeqList;
typedef StaticSeqList *PtrSSList;
typedef const StaticSeqList *cPtrSSList;

// 函数接口
void InitList(PtrSSList list);
int Length(cPtrSSList list);
int LocateElem(cPtrSSList list, cPtrElem elem);
Status GetElem(cPtrSSList list, int pos, PtrElem elem);
Status ListInsert(PtrSSList list, int pos, cPtrElem elem);
Status ListDelete(PtrSSList list, int pos, PtrElem elem);
void PrintList(cPtrSSList list);
bool Empty(cPtrSSList list);
void DestroyList(PtrSSList list);

#endif