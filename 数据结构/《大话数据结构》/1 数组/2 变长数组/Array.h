/* 变长数组类型头文件 */
#ifndef _ARRAY_H_
#define _ARRAY_H_

/* 包含头文件 */
#include "../../0 Head/ElemType.h"
#include "../../0 Head/Status.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 变长数组类型定义 */
struct array
{
    PtrElem data;
    size_t size;
};
typedef struct array Array;
typedef Array *PtrArray;
typedef const Array *cPtrArray;

/* 变长数组函数接口 */

/*
** 操作：初始化操作，建立一个空的变长数组
** 返回值：数组指针
*/
PtrArray InitArray(void);

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
** 1. 若数组为空，返回ISEMPTY
** 2. 若指定位置不合理，返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status GetElem(cPtrArray array, size_t position, PtrElem elem);

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
** 1. 若数组已满返回ISFULL
** 2. 若插入位置不合理返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status ArrayInsert(PtrArray array, size_t position, cPtrElem elem);

/*
** 操作：删除数组指定位置的值，并返回其值
** 参数：
** 1. 数组指针
** 2. 待删除的位置
** 3. 用于返回元素的指针
** 返回值：
** 1. 若数组为空返回ISEMPTY
** 2. 若指定位置不合理，返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status ArrayDelete(PtrArray array, size_t position, PtrElem elem);

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

/* 接口实现 */

/*
** 操作：初始化操作，建立一个空的变长数组
** 返回值：数组指针
*/
PtrArray InitArray(void)
{
    // 首先为数组结构分配空间
    PtrArray array = (PtrArray) malloc(sizeof(Array));
    if (!array) {
        exit(EXIT_FAILURE);
    }

    // 然后为数组分配空间
    array->data = (PtrElem) malloc(sizeof(ElemType));      // 首先分配一个元素空间，留作哨兵
    if (!array->data) {
        exit(EXIT_FAILURE);
    }

    // 初始化其他成员
    array->size = 0;

    return array;
}

/*
** 操作：判断数组是否为空
** 参数：数组指针
** 返回值：
** 1. 若数组为空则返回true
** 2. 否则返回false
*/
bool ArrayEmpty(cPtrArray array)
{
    // 通过数组长度判断是否为空
    if (ArrayLength(array) == 0) {
        return true;
    }
    return false;
}

/*
** 操作：清空数组
** 参数：数组指针
*/
void ClearArray(PtrArray array)
{
    // 清空除了哨兵之外的其他元素
    array->data = (PtrElem) realloc(array->data, sizeof(ElemType));
    if (!array->data) {
        exit(EXIT_FAILURE);
    }
    array->size = 0;
}

/*
** 操作：销毁数组
** 参数：数组指针
*/
void DestroyArray(PtrArray array)
{
    // 清空包括哨兵在内的所有元素，以及整个数组结构
    free(array->data);
    free(array);
}

/*
** 操作：返回数组某位置的值
** 参数：
** 1. 数组指针
** 2. 指定位置
** 3. 用于返回的元素指针
** 返回值：
** 1. 若数组为空，返回ISEMPTY
** 2. 若指定位置不合理，返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status GetElem(cPtrArray array, size_t position, PtrElem elem)
{
    // 判断数组是否为空
    if (ArrayEmpty(array)) {
        return ISEMPTY;
    }

    // 判断指定位置是否合理
    if (position < 1 || position > array->size) {
        return WRONGPOS;
    }

    // 执行操作返回SUCCESS
    AssignElem(elem, &array->data[position]);
    return SUCCESS;
}

/*
** 操作：查找数据元素的位置
** 参数：
** 1. 数组指针
** 2. 待查找的元素指针
** 返回值：
** 1. 若找到该元素，则返回在数组中的位置
** 2. 否则返回0
*/
size_t LocateElem(PtrArray array, cPtrElem elem)
{
    // 布置哨兵
    AssignElem(&array->data[0], elem);

    // 从数组尾开始往前遍历，直到匹配为止
    size_t i;
    for (i = array->size; !CompareElems(&array->data[i], elem); i--);

    // 返回匹配的位置，若为0，说明没有匹配值
    return i;
}

/*
** 操作：在数组指定位置之前插入元素
** 参数：
** 1. 数组指针
** 2. 待插入的位置
** 3. 待插入的元素指针
** 返回值：
** 1. 若插入位置不合理返回WRONGPOS
** 2. 否则执行操作返回SUCCESS
*/
Status ArrayInsert(PtrArray array, size_t position, cPtrElem elem)
{
    // 判断插入位置是否合理
    if (position < 1 || position > array->size + 1) {
        return WRONGPOS;
    }

    // 执行插入操作
    array->size++;
    array->data = (PtrElem) realloc(array->data, (array->size + 1) * sizeof(ElemType));
    for (size_t i = array->size; i > position; i--) {
        AssignElem(&array->data[i], &array->data[i - 1]);
    }
    AssignElem(&array->data[position], elem);

    return SUCCESS;
}

/*
** 操作：删除数组指定位置的值，并返回其值
** 参数：
** 1. 数组指针
** 2. 待删除的位置
** 3. 用于返回元素的指针
** 返回值：
** 1. 若数组为空返回ISEMPTY
** 2. 若指定位置不合理，返回WRONGPOS
** 3. 否则执行操作返回SUCCESS
*/
Status ArrayDelete(PtrArray array, size_t position, PtrElem elem)
{
    // 判断数组是否为空
    if (ArrayEmpty(array)) {
        return ISEMPTY;
    }

    // 判断删除位置是否合理
    if (position < 1 || position > array->size) {
        return WRONGPOS;
    }

    // 执行删除操作
    AssignElem(elem, &array->data[position]);
    for (size_t i = position; i < array->size; i++) {
        AssignElem(&array->data[i], &array->data[i + 1]);
    }
    array->size--;
    array->data = (PtrElem) realloc(array->data, (array->size + 1) * sizeof(ElemType));

    return SUCCESS;
}

/*
** 操作：返回数组有效元素个数
** 参数：数组指针
** 返回值：有效元素个数
*/
size_t ArrayLength(cPtrArray array)
{
    return array->size;
}

/*
** 操作：打印数组内容
** 参数：数组指针
*/
void PrintArray(cPtrArray array)
{
    for (size_t i = 1; i <= array->size; i++) {
        PrintElem(&array->data[i]);
    }
    printf("\n");
}

#endif