//
// Created by sn on 23-2-6.
//
#define EXPORT
#include "ElemType.h"
#include <stdio.h>

/* 接口实现 */

/*
** 操作：为数据元素赋值
** 参数：
** 1. 待赋值数据元素指针
** 2. 赋值数据元素指针
*/
void DLL_CALL AssignElem(PtrElem elem, cPtrElem data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作：比较两个数据元素
** 参数：待比较的两个数据元素指针
** 返回值：
** 1. 若两个数据元素相同返回true
** 2. 否则返回false
*/
bool DLL_CALL CompareElems(cPtrElem elem1, cPtrElem elem2)
{
    if (elem1->x == elem2->x && elem1->y == elem2->y) {
        return true;
    }
    return false;
}

/*
** 操作：打印一个元素内容
** 参数：一个元素指针
*/
void DLL_CALL PrintElem(cPtrElem elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/*
** 操作：读取一个元素内容
** 参数：待读取的元素指针
** 返回值：
** 1. 若scanf返回值与待读取值个数相同返回true
** 2. 否则返回false
*/
bool DLL_CALL ReadElem(PtrElem elem)
{
    printf("请输入数据元素（按\"x, y\"的格式）：");
    if (scanf("%d, %d", &elem->x, &elem->y) == 2) {
        return true;
    } else {
        return false;
    }
}