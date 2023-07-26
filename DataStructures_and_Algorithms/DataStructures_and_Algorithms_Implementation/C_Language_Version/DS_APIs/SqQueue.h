#ifndef SQQUEUE_H_
#define SQQUEUE_H_
// ---------------------------  兼容配置  --------------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define SQQUEUE_API _declspec(dllexport)
#else
#define SQQUEUE_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define SQQUEUE_API
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
#define MAXSIZE 100
struct queue
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
};
typedef struct queue SqQueue;
typedef SqQueue *PtrSqQueue;
typedef const SqQueue *cPtrSqQueue;

// 函数接口
SQQUEUE_API PtrSqQueue DLL_CALL InitQueue(void);
SQQUEUE_API bool DLL_CALL QueueEmpty(cPtrSqQueue queue);
SQQUEUE_API Status DLL_CALL EnQueue(PtrSqQueue queue, cPtrElem elem);
SQQUEUE_API Status DLL_CALL DeQueue(PtrSqQueue queue, PtrElem elem);
SQQUEUE_API Status DLL_CALL GetHead(cPtrSqQueue queue, PtrElem elem);

// ---------------------------  兼容配置  --------------------------- //
#ifdef __cplusplus
}
#endif
#endif