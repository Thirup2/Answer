/* 顺序线性表接口函数定义SeqList.c */
#include "SeqList.h"

/* 接口函数定义 */

// 操作: 初始化操作, 创建一个空的线性表
void InitList(SeqList *plist)
{
    plist->length = 0;
}

// 操作: 判断线性表是否为空
bool ListEmpty(SeqList list)
{
    if (list.length == 0) {
        return true;
    } else {
        return false;
    }
}

// 操作: 将线性表清空
void ClearList(SeqList *plist)
{
    plist->length = 0;
}

// 操作: 将线性表中的第i个元素返回给elem
bool GetElem(SeqList list, int i, ElemType *elem)
{
    if (i <= 0 || i > list.length) {
        return false;
    }
    *elem = list.data[i - 1];
    return true;
}

// 操作: 查找与给定值相同的元素
int LocateElem(SeqList list, ElemType elem)
{
    for (int i = 0; i < list.length; i++) {
        if (list.data[i] == elem) {
            return i + 1;
        }
    }
    return 0;
}

// 操作: 在线性表第i个位置插入新元素
int ListInsert(SeqList *plist, int i, ElemType elem)
{
    if (i <= 0 || i > plist->length + 1) {
        return -2;              // 位置不合理
    }
    if (plist->length == MAXSIZE) {
        return -1;              // 已满
    }
    int n = 0;
    for (n = plist->length; n > i - 1; n--) {
        plist->data[n] = plist->data[n-1];
    }
    plist->data[n] = elem;
    plist->length++;
    return 0;                   // 成功
}

// 操作: 删除线性表第i个位置的元素
int ListDelete(SeqList *plist, int i, ElemType *elem)
{
    if (i <= 0 || i > plist->length) {
        return -2;              // 位置不合理
    }
    *elem = plist->data[i - 1];
    for (int n = i - 1; n < plist->length - 1; n++) {
        plist->data[n] = plist->data[n + 1];
    }
    plist->length--;
    return 0;
}

// 操作: 返回线性表的元素个数
int ListLength(SeqList list)
{
    return list.length;
}