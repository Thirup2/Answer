/* 一维数组接口头文件Linear_Array.h */
#ifndef _LINEAR_ARRAY_H_
#define _LINEAR_ARRAY_H_

/* 包含头文件 */
#include <stdbool.h>        // 使用bool类型

/* 数据类型定义 */
#define MAXSIZE 20          // 数组的最大长度
typedef int ElemType;       // 定义数据元素
typedef struct
{
    ElemType data[MAXSIZE];
    int length;
}L_Array;                   // 定义一维数组

/* 接口函数原型 */
// 操作: 初始化一维数组
void InitArray(L_Array *parr);

// 操作: 判断数组是否为空
// 前提条件: 数组arr已存在
// 后置条件: 若为空数组, 返回true, 否则返回false
bool ArrayEmpty(L_Array arr);

// 操作: 将数组重置为空数组
// 前提条件: 数组arr已存在
void ClearArray(L_Array *parr);

// 操作: 返回数组中元素个数
// 前提条件: 数组arr已存在
int ArrayLength(L_Array arr);

// 操作: 用elem返回数组第i个元素的值
int GetElem(L_Array arr, int i, ElemType *elem);

// 操作: 返回数组中第1个与elem相等的位序
// 后置条件: 若这样的数据元素不存在, 则返回值为0
int LocateElem(L_Array arr, ElemType elem);

// 操作: 在数组arr第i个位置之前插入新的数据元素elem
// 后置条件: 表长加1
int ArrayInsert(L_Array *parr, int i, ElemType elem);

// 操作: 删除arr的第i个数据元素, 用elem返回其值
// 后置条件: 表长减1
bool ArrayDelete(L_Array *parr, int i, ElemType *elem);

// 操作: 依次对arr的每个数据元素输出
void ArrayTraverse(L_Array arr);

// 操作: 将所有的在数组arr_b中但不在arr_a中的数据元素插入到arr_a中
void UnionArray(L_Array *arr_a, L_Array arr_b);

#endif