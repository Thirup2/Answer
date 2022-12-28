/* 定容数组接口实现 */
#ifndef _ARRAY_H_
#define _ARRAY_H_

/* 包含头文件 */
#include "Array_head.h"

/* 接口实现 */

/*
** 操作：初始化操作，建立一个空的定容数组
** 参数：数组大小
** 返回值：数组指针
*/
PtrArray InitArray(size_t size)
{
    // 首先分配定容数组结构的内存空间
    PtrArray array = (PtrArray) malloc(sizeof(Array));
    if (!array) {
        exit(EXIT_FAILURE);
    }

    // 然后根据参数为数组分配空间
    array->data = (PtrElem) calloc(size + 1, sizeof(ElemType));     // 大小比指定值大1，第一个元素留作哨兵
    if (!array->data) {
        exit(EXIT_FAILURE);
    }

    // 初始化其他成员
    array->size = size;
    array->length = 0;
    
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
    array->length = 0;
}

/*
** 操作：销毁数组
** 参数：数组指针
*/
void DestroyArray(PtrArray array)
{
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
** 1. 若数组为空，返回-2
** 2. 若指定位置不合理，返回-1
** 3. 若指定位置无值，返回1
** 4. 否则执行操作返回0
*/
int GetElem(cPtrArray array, size_t position, PtrElem elem)
{
    if (ArrayEmpty(array)) {
        return -2;
    }
    if (position < 1 || position > array->size) {
        return -1;
    }
    if (position > ArrayLength(array)) {
        return 1;
    }
    AssignElem(elem, &array->data[position]);
    return 0;
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
    AssignElem(&array->data[0], elem);
    size_t i;
    for (i = ArrayLength(array); !CompareElems(&array->data[i], elem); i--);
    return i;
}

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
int ArrayInsert(PtrArray array, size_t position, cPtrElem elem)
{
    // 判断数组是否已满
    if (ArrayLength(array) == array->size) {
        return -1;
    }

    // 判断插入位置是否合理
    if (position < 1 || position > ArrayLength(array) + 1) {
        return 1;
    }

    // 执行插入操作
    for (size_t i = ArrayLength(array); i >= position; i--) {       // 若在中间插入，需要将后面的元素全部后移
        AssignElem(&array->data[i + 1], &array->data[i]);
    }
    AssignElem(&array->data[position], elem);
    array->length++;
    
    return 0;
}

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
int ArrayDelete(PtrArray array, size_t position, PtrElem elem)
{
    // 判断数组是否为空
    if (ArrayEmpty(array)) {
        return -1;
    }

    // 判断删除位置是否合理
    if (position < 1 || position > array->length) {
        return 1;
    }

    // 执行删除操作
    AssignElem(elem, &array->data[position]);
    for (size_t i = position; i < array->length; i++) {         // 若在中间删除，则该位置之后的元素全部需要前移
        AssignElem(&array->data[i], &array->data[i + 1]);
    }
    array->length--;

    return 0;
}

/*
** 操作：返回数组有效元素个数
** 参数：数组指针
** 返回值：有效元素个数
*/
size_t ArrayLength(cPtrArray array)
{
    return array->length;
}

/*
** 操作：打印数组内容
** 参数：数组指针
*/
void PrintArray(cPtrArray array)
{
    for (size_t i = 0; i < array->length; i++) {
        PrintElem(&array->data[i + 1]);
    }
    printf("\n");
}

#endif