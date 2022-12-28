/* 定容类型头文件 */
#ifndef _ARRAY_HEAD_H_
#define _ARRAY_HEAD_H_

/* 包含头文件 */
#include "ElemType.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 定容数组类型定义 */
struct array
{
    size_t size;
    size_t length;
    PtrElem data;
};
typedef struct array Array;
typedef Array *PtrArray;
typedef const Array *cPtrArray;

/* 定容数组函数接口 */

/*
** 操作：初始化操作，建立一个空的定容数组
** 参数：数组大小
** 返回值：数组指针
*/
PtrArray InitArray(size_t size);

/*
** 操作：判断数组是否为空
** 参数：数组指针
** 返回值：
** 1. 若数组为空则返回true
** 2. 否则返回false
*/
bool ArrayEmpty(cPtrArray array);

/*
** 操作：清空数组
** 参数：数组指针
*/
void ClearArray(PtrArray array);

/*
** 操作：销毁数组
** 参数：数组指针
*/
void DestroyArray(PtrArray array);

/*
** 操作：返回数组某位置的值
** 参数：
** 1. 数组指针
** 2. 指定位置
** 3. 用于返回的元素指针
** 返回值：
** 1. 若数组为空，返回-2
** 2. 若指定位置不合理，返回-1
** 3. 若指定位置无值，返回1
** 4. 否则执行操作返回0
*/
int GetElem(cPtrArray array, size_t position, PtrElem elem);

/*
** 操作：查找数据元素的位置
** 参数：
** 1. 数组指针
** 2. 待查找的元素指针
** 返回值：
** 1. 若找到该元素，则返回在数组中的位置
** 2. 否则返回0
*/
size_t LocateElem(PtrArray array, cPtrElem elem);

/*
** 操作：在数组指定位置之前插入元素
** 参数：
** 1. 数组指针
** 2. 待插入的位置
** 3. 待插入的元素指针
** 返回值：
** 1. 若数组已满返回-1
** 2. 若插入位置不合理返回1
** 3. 否则执行操作返回0
*/
int ArrayInsert(PtrArray array, size_t position, cPtrElem elem);

/*
** 操作：删除数组指定位置的值，并返回其值
** 参数：
** 1. 数组指针
** 2. 待删除的位置
** 3. 用于返回元素的指针
** 返回值：
** 1. 若数组为空返回-1
** 2. 若指定位置不合理，返回1
** 3. 否则执行操作返回0
*/
int ArrayDelete(PtrArray array, size_t position, PtrElem elem);

/*
** 操作：返回数组有效元素个数
** 参数：数组指针
** 返回值：有效元素个数
*/
size_t ArrayLength(cPtrArray array);

/*
** 操作：打印数组内容
** 参数：数组指针
*/
void PrintArray(cPtrArray array);

#endif