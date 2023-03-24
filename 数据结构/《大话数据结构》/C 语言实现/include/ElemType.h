/* 数据元素接口头文件 */
#ifndef ELEMTYPE_H_
#define ELEMTYPE_H_

/* 包含头文件 */
#include <stdbool.h>

/* 兼容配置 */
#ifdef _WIN32
#ifdef EXPORT
#define ET_API _declspec(dllexport)
#else
#define ET_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define  ET_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 数据元素类型定义 */
struct items
{
    int x;
    int y;
};
typedef struct items ElemType;
typedef ElemType *PtrElem;
typedef const ElemType *cPtrElem;

/* 数据元素函数接口 */

/*
** 操作：为数据元素赋值
** 参数：
** 1. 待赋值数据元素指针
** 2. 赋值数据元素指针
*/
ET_API void DLL_CALL AssignElem(PtrElem elem, cPtrElem data);

/*
** 操作：比较两个数据元素
** 参数：待比较的两个数据元素指针
** 返回值：
** 1. 若两个数据元素相同返回true
** 2. 否则返回false
*/
ET_API bool DLL_CALL CompareElems(cPtrElem elem1, cPtrElem elem2);

/*
** 操作：打印一个元素内容
** 参数：一个元素指针
*/
ET_API void DLL_CALL PrintElem(cPtrElem elem);

/*
** 操作：读取一个元素内容
** 参数：待读取的元素指针
** 返回值：
** 1. 若scanf返回值与待读取值个数相同返回true
** 2. 否则返回false
*/
ET_API bool DLL_CALL ReadElem(PtrElem elem);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif