/* 一维数组接口函数文件Linear_array.c */

/* 包含头文件 */
#include "Linear_Array.h"
#include <stdio.h>

/* 局部函数原型 */
// 操作: 打印elem
static void visit(ElemType elem);

/* 接口函数定义 */
// 操作: 初始化一维数组
void InitArray(L_Array *parr)
{
    for (int i = 0; i < MAXSIZE; ++i) {
        parr->data[i] = 0;
    }
    parr->length = 0;
}

// 操作: 判断数组是否为空
bool ArrayEmpty(L_Array arr)
{
    if (arr.length == 0) {
        return true;
    } else {
        return false;
    }
}

// 操作: 将数组重置为空数组
void ClearArray(L_Array *parr)
{
    for (int i = 0; i < MAXSIZE; ++i) {
        parr->data[i] = 0;
    }
    parr->length = 0;
}

// 操作: 返回数组中元素个数
int ArrayLength(L_Array arr)
{
    return arr.length;
}

// 操作: 用elem返回数组第i个元素的值
int GetElem(L_Array arr, int i, ElemType *elem)
{
    if (i > MAXSIZE) {
        return -2;          // 待取位置不合理
    }
    if (arr.length < i) {
        return -1;          // 元素不存在
    }
    *elem = arr.data[i - 1];
    return 0;               // 返回成功
}

// 操作: 返回数组中第1个与elem相等的位序
int LocateElem(L_Array arr, ElemType elem)
{
    for (int i = 0; i < arr.length; ++i) {
        if (arr.data[i] == elem) {
            return i + 1;
        }
    }
    return 0;
}

// 操作: 在数组arr第i个位置之前插入新的数据元素elem
int ArrayInsert(L_Array *parr, int i, ElemType elem)
{
    if (parr->length == MAXSIZE) {
        return -1;                  // 数组已满
    }
    if (i > parr->length + 1) {
        return -2;                  // 插入位置不合理
    }
    for (int n = parr->length; n >= i; --n) {
        parr->data[n] = parr->data[n - 1];
    }
    parr->data[i - 1] = elem;
    ++parr->length;
    return 0;
}

// 操作: 删除arr的第i个数据元素, 用elem返回其值
bool ArrayDelete(L_Array *parr, int i, ElemType *elem)
{
    if (i <= 0 || i > parr->length) {
        return false;
    }
    *elem = parr->data[i - 1];
    for (int n = i; n <= parr->length; ++n) {
        parr->data[n - 1] = parr->data[n];
    }
    --parr->length;
    return true;
}

// 操作: 依次对arr的每个数据元素输出
void ArrayTraverse(L_Array arr)
{
    for (int i = 0; i < arr.length; ++i) {
        visit(arr.data[i]);
    }
    printf("\n");
}

// 操作: 将所有的在数组arr_b中但不在arr_a中的数据元素插入到arr_a中
void UnionArray(L_Array *arr_a, L_Array arr_b)
{
    int arra_len, arrb_len, i;
    ElemType elem;
    arra_len = ArrayLength(*arr_a);
    arrb_len = ArrayLength(arr_b);
    for (i = 1; i <= arrb_len; ++i) {
        GetElem(arr_b, i, &elem);
        if (!LocateElem(*arr_a, elem)) {
            ArrayInsert(arr_a, ++arra_len, elem);
        }
    }
}

/* 局部函数定义 */
// 操作: 打印elem
static void visit(ElemType elem)
{
    printf("%d ", elem);
}