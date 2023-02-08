/* 静态链表接口头文件 */
#ifndef _STATICLINKLIST_H_
#define _STATICLINKLIST_H_

/* 包含头文件 */
#include "Status.h"
#include "ElemType.h"
#include <stdbool.h>
#include <limits.h>

/* 兼容配置 */
#ifdef _WIN32
#ifdef EXPORT
#define SLL_API _declspec(dllexport)
#else
#define SLL_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define SLL_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 静态链表类型定义 */
#define STATIC_NULL                     0
// 根据后续定义的static_size_t的实际类型确定
#define MAXSIZE                         USHRT_MAX
// 使用时提供LinkList的实例作为参数
#define MEMORY_POOL(LinkList_Instance)  LinkList_Instance[0].cur            // 备用链表的第一个元素下标
#define HEAD(LinkList_Instance)         LinkList_Instance[MAXSIZE-1].cur    // 已用链表第一个元素下标

typedef unsigned short int static_size_t;

struct node
{
    ElemType data;
    static_size_t cur;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

typedef Node LinkList[MAXSIZE];
typedef Node *PtrLL;
typedef const Node *cPtrLL;

/* 静态链表函数接口 */

/*
** 操作：初始化链表
** 1. 将0-MAXSIZE-2的游标设置为下一个元素的下标，将MAXSIZE-1的游标设置为0
** 参数：链表
*/
SLL_API void DLL_CALL InitList(PtrLL list);

/*
** 操作：判断链表是否为空
** 参数：链表
** 返回值：true or false
*/
SLL_API bool DLL_CALL ListEmpty(cPtrLL list);

/*
** 操作：将链表清空
** 参数：链表
*/
SLL_API void DLL_CALL ClearList(PtrLL list);

/*
** 操作：访问链表
** 参数：
** 1. 链表
** 2. 访问位置
** 3. 用于返回的元素指针
** 返回值：
** 1. 若链表为空返回ISEMPTY
** 2. 若访问位置不对返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
SLL_API Status DLL_CALL GetElem(cPtrLL list, static_size_t position, PtrElem elem);

/*
** 操作：查找元素
** 参数：
** 1. 链表
** 2. 待查找的元素
** 返回值：
** 1. 若为找到，返回0
** 2. 否则返回元素的位序（注意不是下标）
*/
SLL_API static_size_t DLL_CALL LocateElem(cPtrLL list, cPtrElem elem);

/*
** 操作：插入元素
** 参数：
** 1. 链表
** 2. 待插入位序
** 3. 带插入的元素指针
** 返回值：
** 1. 若插入元素不正确返回WRONGPOS
** 2. 否则执行操作返回SUCCESS
*/
SLL_API Status DLL_CALL ListInsert(PtrLL list, static_size_t position, cPtrElem elem);

/*
** 操作：删除元素
** 参数：
** 1. 链表
** 2. 待删除位序
** 3. 返回被删除元素的指针
** 返回值：
** 1. 若链表为空返回ISEMPTY
** 2. 若删除位序不正确返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
SLL_API Status DLL_CALL ListDelete(PtrLL list, static_size_t position, PtrElem elem);

/*
** 操作：返回链表长度
** 参数：链表
** 返回值：链表长度
*/
SLL_API static_size_t DLL_CALL ListLength(cPtrLL list);

/*
** 操作：打印链表
** 参数：链表
*/
SLL_API void DLL_CALL PrintList(cPtrLL list);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif