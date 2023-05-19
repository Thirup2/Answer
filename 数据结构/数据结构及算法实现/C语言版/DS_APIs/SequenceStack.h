#ifndef SEQUENCESTACK_H_
#define SEQUENCESTACK_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define SEQSTACK_API _declspec(dllexport)
#else
#define SEQSTACK_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define SEQSTACK_API
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
#define MAXSIZE 50
enum choice
{
    Stack1,
    Stack2
};
typedef enum choice Choice;
struct stack
{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
};
typedef struct stack SharedStack;
typedef SharedStack *PtrShStack;
typedef const SharedStack *cPtrShStack;

// 函数接口
SEQSTACK_API PtrShStack DLL_CALL InitStack(void);
SEQSTACK_API bool DLL_CALL StackEmpty(cPtrShStack stack, Choice choice);
SEQSTACK_API Status DLL_CALL Push(PtrShStack stack, cPtrElem elem, Choice choice);
SEQSTACK_API Status DLL_CALL Pop(PtrShStack stack, PtrElem elem, Choice choice);
SEQSTACK_API Status DLL_CALL GetTop(cPtrShStack stack, PtrElem elem, Choice choice);
SEQSTACK_API void DLL_CALL DestoryStack(PtrShStack stack);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif

#endif