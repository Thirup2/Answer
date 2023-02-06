/* 链栈接口头文件 */
#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

/* 包含头文件 */
#include "ElemType.h"
#include "Status.h"
#include <stdbool.h>
#include <stddef.h>

/* 兼容配置 */
#ifdef WIN32
#ifdef EXPORT
#define LS_API _declspec(dllexport)
#else
#define LS_API _declspec(dllimport)
#endif
#define DLL_CALL __stdcall
#elif __linux__
#define LS_API
#define DLL_CALL
#endif
#ifdef __cplusplus
extern "C" {
#endif

/* 链栈类型定义 */
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PtrNode;
typedef const Node *cPtrNode;

struct stack
{
    PtrNode top;
};
typedef struct stack Stack;
typedef Stack *PtrStack;
typedef const Stack *cPtrStack;

/* 链栈函数接口 */

/*
** 操作：初始化顺序栈
** 返回值：初始化后的顺序栈指针
*/
LS_API PtrStack DLL_CALL InitStack(void);

/*
** 操作：销毁栈
** 参数：栈
*/
LS_API void DLL_CALL DestroyStack(PtrStack stack);

/*
** 操作：清空栈
** 参数：栈
*/
LS_API void DLL_CALL ClearStack(PtrStack stack);

/*
** 操作：判断栈是否为空
** 参数：栈
** 返回值：true or false
*/
LS_API bool DLL_CALL StackEmpty(cPtrStack stack);

/*
** 操作：访问栈顶元素
** 参数：
** 1. 栈
** 2. 返回栈顶元素的指针
** 返回值：
** 1. 若栈为空，返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
LS_API Status DLL_CALL GetTop(cPtrStack stack, PtrElem elem);

/*
** 操作：压栈
** 参数：
** 1. 栈
** 2. 待压栈元素
** 返回值：
** 1. 若栈已满，返回ISFULL
** 2. 否则执行操作返回SUCCESS
*/
LS_API Status DLL_CALL Push(PtrStack stack, cPtrElem elem);

/*
** 操作：弹栈
** 参数：
** 1. 栈
** 2. 被弹栈元素
** 返回值：
** 1. 若栈为空，返回ISEMPTY
** 2. 否则执行操作返回SUCCESS
*/
LS_API Status DLL_CALL Pop(PtrStack stack, PtrElem elem);

/*
** 操作：返回栈长
** 参数：栈
** 返回值：栈长
*/
LS_API size_t DLL_CALL StackLenth(cPtrStack stack);

/*
** 操作：从栈顶到栈底打印所有元素
** 参数：栈
*/
LS_API void DLL_CALL PrintStack(cPtrStack stack);

/* 兼容配置 */
#ifdef __cplusplus
}
#endif

#endif