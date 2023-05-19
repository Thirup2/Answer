#ifndef LINKSTACK_H_
#define LINKSTACK_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define LINKSTACK_API _declspec(dllexport)
#else
#define LINKSTACK_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define LINKSTACK_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

// --------------------------- 包含头文件 --------------------------- //
#include "Coords.h"
#include "Status.h"
#include <stdbool.h>

// ---------------------------    接口    --------------------------- //
// 元素类型接口
typedef Coords ElemType;
typedef PtrCoords PtrElem;
typedef cPtrCoords cPtrElem;
#define CopyElems CopyCoords
#define PrintElem PrintCoords
#define ReadElem ReadCoords

// 类型定义
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

typedef PtrNode LinkStack;

// 函数接口
LINKSTACK_API LinkStack DLL_CALL InitStack(void);
LINKSTACK_API bool DLL_CALL StackEmpty(LinkStack stack);
LINKSTACK_API Status DLL_CALL Push(LinkStack stack, cPtrElem elem);
LINKSTACK_API Status DLL_CALL Pop(LinkStack stack, PtrElem elem);
LINKSTACK_API Status DLL_CALL GetTop(LinkStack stack, PtrElem elem);
LINKSTACK_API void DLL_CALL DestroyStack(LinkStack stack);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif