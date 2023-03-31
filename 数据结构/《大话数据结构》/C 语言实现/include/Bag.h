#ifndef BAG_H_
#define BAG_H_

// ----------------------包含头文件---------------------- //
#include "Coordinate.h"
#include "Status.h"
#include <stddef.h>
#include <stdbool.h>

// ----------------------兼容配置---------------------- //
#ifdef _WIN32
#ifdef EXPORT
#define BAG_API _declspec(dllexport)
#else
#define BAG_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define BAG_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

// ----------------------接口---------------------- //

// 数据类型定义
struct bag
{
    PtrCoord data;
    size_t size;
};
typedef struct bag Bag;
typedef Bag *PtrBag;
typedef const Bag *cPtrBag;

// 背包类型函数接口

/*
 * 操作：创建一个背包
 * 返回：背包指针
*/
BAG_API PtrBag DLL_CALL InitBag(void);

/*
 * 操作：判断背包是否为空
 * 参数：背包指针
 * 返回：
 * 1. 若为空返回 true
 * 2. 否则返回 false
*/
BAG_API bool DLL_CALL EmptyBag(cPtrBag bag);

/*
 * 操作：清空背包
 * 参数：背包指针
*/
BAG_API void DLL_CALL ClearBag(PtrBag bag);

/*
 * 操作：销毁背包
 * 参数：背包指针
*/
BAG_API void DLL_CALL DestroyBag(PtrBag bag);

/*
 * 操作：查找值的位置
 * 参数：
 * 1. 背包指针
 * 2. 待查找的值
 * 返回：
 * 1. 若找到返回位置
 * 2. 否则返回 0
*/
BAG_API size_t DLL_CALL SearchData(cPtrBag bag, cPtrCoord coord);

/*
 * 操作：插入元素
 * 参数：
 * 1. 背包指针
 * 2. 待插入的值
 * 返回：
 * 1. 若背包已满返回 ISFULL
 * 2. 如果元素已存在返回 ISIN
 * 2. 否则执行操作返回 SUCCESS
*/
BAG_API Status DLL_CALL InsertElem(PtrBag bag, cPtrCoord coord);

/*
 * 操作：返回元素个数
 * 参数：背包指针
 * 返回：元素个数
*/
BAG_API size_t DLL_CALL BagSize(cPtrBag bag);

/*
 * 操作：返回起始迭代器
 * 参数：背包指针
 * 返回：背包的起始迭代器
*/
BAG_API PtrCoord DLL_CALL Begin(PtrBag bag);

/*
 * 操作：返回尾后迭代器
 * 参数：背包指针
 * 返回：背包的尾后迭代器
*/
BAG_API PtrCoord DLL_CALL End(PtrBag bag);

/*
 * 操作：返回下一个迭代器
 * 参数：
 * 1. 背包指针
 * 2. 当前迭代器
*/
BAG_API PtrCoord DLL_CALL Next(PtrCoord now);

// ----------------------兼容配置---------------------- //
#ifdef __cplusplus
}
#endif

#endif