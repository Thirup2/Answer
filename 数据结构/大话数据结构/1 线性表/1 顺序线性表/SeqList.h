/* 顺序线性表接口头文件SeqList.h */
#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdbool.h>
/* 数据结构定义 */
#define MAXSIZE 20      // 存储空间初始分配量
typedef int ElemType;   // ElemType类型根据实际情况而定, 这里为int
typedef struct
{
    ElemType data[MAXSIZE];     // 数组, 存储数据元素
    int length;                 // 线性表当前长度
} SeqList;                      // 顺序线性表

/* 接口函数原型 */

// 操作: 初始化操作, 创建一个空的线性表
// 前提条件: plist是一个指向线性表的指针
// 后置条件: 将线性表长度置为0
void InitList(SeqList *plist);

// 操作: 判断线性表是否为空
// 前提条件: list是一个已初始化的线性表
// 后置条件: 若线性表为空, 返回true, 否则返回false
bool ListEmpty(SeqList list);

// 操作: 将线性表清空
// 前提条件: plist是一个指向线性表的指针
// 后置条件: 将线性表长度置为0
void ClearList(SeqList *plist);

// 操作: 将线性表中的第i个元素返回给elem
// 前提条件: list是一个已初始化的线性表
bool GetElem(SeqList list, int i, ElemType *elem);

// 操作: 查找与给定值相同的元素
// 前提条件: list是一个已初始化的线性表
// 后置条件: 成功则返回该元素所在位置的序号, 否则返回0
int LocateElem(SeqList list, ElemType elem);

// 操作: 在线性表第i个位置插入新元素
// 前提条件: plist是一个指向线性表的指针
// 后置条件: 在对应位置插入元素, 并将其后所有元素后移
int ListInsert(SeqList *plist, int i, ElemType elem);

// 操作: 删除线性表第i个位置的元素
// 前提条件: plist是一个指向线性表的指针
// 后置条件: 删除对应位置的元素, 并将其后所有元素前移
int ListDelete(SeqList *plist, int i, ElemType *elem);

// 操作: 返回线性表的元素个数
// 前提条件: list是一个已初始化的线性表
int ListLength(SeqList list);

#endif