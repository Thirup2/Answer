#define EXPORT

#include "StaticLinkList.h"
#include <stdlib.h>
#include <stdio.h>

/* 局部函数 */

/*
** 操作：模拟分配内存
** 参数：链表
** 返回值：
** 1. 若链表已满返回0
** 2. 否则返回被分配的内存的下标
*/
static static_size_t DLL_CALL Static_Malloc(PtrLL list);

/*
** 操作：模拟释放内存
** 参数：
** 1. 链表
** 2. 要释放的内存下标
*/
static void DLL_CALL Static_Free(PtrLL list, static_size_t i);

/* 接口实现 */

/*
** 操作：初始化链表
** 1. 将0-MAXSIZE-2的游标设置为下一个元素的下标，将MAXSIZE-1的游标设置为0
** 参数：链表
*/
void DLL_CALL InitList(PtrLL list)
{
    for (static_size_t i = 0; (int) i < MAXSIZE - 2; i++) {
        list[i].cur = i + 1;
    }
    list[MAXSIZE - 2].cur = STATIC_NULL;
    HEAD(list) = STATIC_NULL;
}

/*
** 操作：判断链表是否为空
** 参数：链表
** 返回值：true or false
*/
bool DLL_CALL ListEmpty(cPtrLL list)
{
    if (ListLength(list) == 0) {
        return true;
    }
    return false;
}

/*
** 操作：将链表清空
** 参数：链表
*/
void DLL_CALL ClearList(PtrLL list)
{
    for (static_size_t i = 0; (int) i < MAXSIZE - 2; i++) {
        list[i].cur = i + 1;
    }
    list[MAXSIZE - 2].cur = STATIC_NULL;
    HEAD(list) = STATIC_NULL;
}

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
Status DLL_CALL GetElem(cPtrLL list, static_size_t position, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (position < 1 || position > ListLength(list)) {
        return WRONGPOS;
    }
    static_size_t i = HEAD(list);
    while (--position) {
        i = list[i].cur;
    }
    AssignElem(elem, &list[i].data);
    return SUCCESS;
}

/*
** 操作：查找元素
** 参数：
** 1. 链表
** 2. 待查找的元素
** 返回值：
** 1. 若为找到，返回0
** 2. 否则返回元素的位序（注意不是下标）
*/
static_size_t DLL_CALL LocateElem(cPtrLL list, cPtrElem elem)
{
    static_size_t pos = 1;
    static_size_t i = HEAD(list);
    while (i != STATIC_NULL) {
        if (CompareElems(elem, &list[i].data)) {
            return pos;
        }
        pos++;
        i = list[i].cur;
    }
    return 0;
}

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
Status DLL_CALL ListInsert(PtrLL list, static_size_t position, cPtrElem elem)
{
    if (position < 1 || position > ListLength(list) + 1) {
        return WRONGPOS;
    }
    static_size_t p = Static_Malloc(list);
    if (p == STATIC_NULL) {
        exit(EXIT_FAILURE);
    }
    AssignElem(&list[p].data, elem);
    static_size_t i = MAXSIZE - 1;
    while (--position) {
        i = list[i].cur;
    }
    list[p].cur = list[i].cur;
    list[i].cur = p;
    return SUCCESS;
}

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
Status DLL_CALL ListDelete(PtrLL list, static_size_t position, PtrElem elem)
{
    if (ListEmpty(list)) {
        return ISEMPTY;
    }
    if (position < 1 || position > ListLength(list)) {
        return WRONGPOS;
    }
    static_size_t i = HEAD(list);
    static_size_t s = MAXSIZE - 1;
    while (--position) {
        s = i;
        i = list[i].cur;
    }
    list[s].cur = list[i].cur;
    AssignElem(elem, &list[i].data);
    Static_Free(list, i);
    return SUCCESS;
}

/*
** 操作：返回链表长度
** 参数：链表
** 返回值：链表长度
*/
static_size_t DLL_CALL ListLength(cPtrLL list)
{
    static_size_t i = 0;
    static_size_t p = HEAD(list);
    while (p != STATIC_NULL) {
        i++;
        p = list[p].cur;
    }
    return i;
}

/*
** 操作：打印链表
** 参数：链表
*/
void DLL_CALL PrintList(cPtrLL list)
{
    static_size_t p = HEAD(list);
    while (p != STATIC_NULL) {
        PrintElem(&list[p].data);
        p = list[p].cur;
    }
    printf("\n");
}

/* 局部函数定义 */

/*
** 操作：模拟分配内存
** 参数：链表
** 返回值：
** 1. 若链表已满返回0
** 2. 否则返回被分配的内存的下标
*/
static static_size_t DLL_CALL Static_Malloc(PtrLL list)
{
    static_size_t i = MEMORY_POOL(list);
    MEMORY_POOL(list) = list[i].cur;
    return i;
}

/*
** 操作：模拟释放内存
** 参数：
** 1. 链表
** 2. 要释放的内存下标
*/
static void DLL_CALL Static_Free(PtrLL list, static_size_t i)
{
    list[i].cur = MEMORY_POOL(list);
    MEMORY_POOL(list) = i;
}