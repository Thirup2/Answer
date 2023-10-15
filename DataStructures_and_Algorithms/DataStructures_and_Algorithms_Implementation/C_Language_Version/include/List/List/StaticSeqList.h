#ifndef STATICSEQLIST_H_
#define STATICSEQLIST_H_

#include "Compatible.h"
#include "ElemType.h"

// ----------------------------------- 头文件 ----------------------------------- //
#include "Status.h"

// ----------------------------------- 接  口 ----------------------------------- //
// 类型定义
#define MAXSIZE 10
typedef struct list
{
    ElemType data[MAXSIZE + 1];
    int length;
}List, * PtrList;

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

#endif