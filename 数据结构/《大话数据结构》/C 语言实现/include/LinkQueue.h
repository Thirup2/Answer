/* 链队列接口头文件 */
#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

/* 包含头文件 */
#include "ElemType.h"
#include "Status.h"
#include <stdbool.h>
#include <stddef.h>

#ifdef _WIN32
#ifdef EXPORT
#define LQ_API _declspec(dllexport)
#else
#define LQ_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define LQ_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 链队列类型定义 */
struct node
{
    ElemType data;
    struct node *next;
    struct node *pre;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct queue
{
    PtrNode head;
    PtrNode last;
};
typedef struct queue Queue;
typedef Queue *PtrQueue;
typedef const Queue *cPtrQueue;

/* 链队列函数接口 */

/*
** 操作：初始化操作
** 参数：新队列的大小
** 返回值：队列指针
*/
LQ_API PtrQueue DLL_CALL InitQueue(void);

/*
** 操作：销毁队列
** 参数：队列
*/
LQ_API void DLL_CALL DestroyQueue(PtrQueue queue);

/*
** 操作：清空队列
** 参数：队列
*/
LQ_API void DLL_CALL ClearQueue(PtrQueue queue);

/*
** 操作：判断队列是否为空
** 参数：队列
** 返回值：true or false
*/
LQ_API bool DLL_CALL QueueEmpty(cPtrQueue queue);

/*
** 操作：返回队列的长度
** 参数：队列
** 返回值：队列长度
*/
LQ_API size_t DLL_CALL QueueLength(cPtrQueue queue);

/*
** 操作：插入元素到队尾
** 参数：
** 1. 队列
** 2. 插入元素
** 返回值：
** 1. 若队列已满，返回ISFULL
** 2. 否则执行操作返回SUCCESS
*/
LQ_API Status DLL_CALL EnQueue(PtrQueue queue, cPtrElem elem);

/*
** 操作：删除队头元素
** 参数：
** 1. 队列
** 2. 用于返回队头元素的指针
** 返回值：
** 1. 若队列为空返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
LQ_API Status DLL_CALL DeQueue(PtrQueue queue, PtrElem elem);

/*
** 操作：访问队头元素
** 参数：
** 1. 队列
** 2. 用于返回队头元素的指针
** 返回值：
** 1. 若队列为空返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
LQ_API Status DLL_CALL GetHead(cPtrQueue queue, PtrElem elem);

/*
** 操作：打印队列内容（从队头到队尾）
** 参数：队列
*/
LQ_API void DLL_CALL PrintQueue(cPtrQueue queue);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif