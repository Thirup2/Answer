/* 一维数组接口头文件Array.h */
#ifndef _ARRAY_H_
#define _ARRAY_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 数据结构定义 */
struct items
{
    int x;                              // 数据项1
    int y;                              // 数据项2
};
typedef struct items ElemType;          // 数据元素类型

struct array
{
    ElemType *data;                     // 数组内容(动态数组)
    int length;                         // 数组有效长度
};
typedef struct array Array;             // 数组类型
typedef Array *PArray;                  // 数组指针

/* 数据元素处理函数原型 */

/*
** 操作: 比较两个元素是否相同
** 参数: 两个元素的指针
** 返回值:
** 1. 若相同, 返回true
** 2. 否则, 返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2);

/*
** 操作: 交换两个数据元素的值
** 参数: 两个数据元素
*/
void ExchangeElem(ElemType *elem, ElemType *data);

/*
** 操作: 打印一个数据元素
** 参数: 数据元素指针
*/
void PrintElem(ElemType *elem);

/*
** 操作: 读取一个数据元素
** 参数: 存放地址
*/
void ScanElem(ElemType *elem);

/* 一维数组接口函数原型 */

/*
** 操作: 初始化数组
** 1. 创建一个空的线性表
** 2. 表长为1, 即哨兵位
** 返回值: 初始化的数组
*/
PArray InitArray(void);

/*
** 操作: 判断数组是否为空
** 参数: 数组
** 返回值:
** 1. 若为空(只含有哨兵位)返回true
** 2. 否则返回false
*/
bool ArrayEmpty(PArray array);

/*
** 操作: 将数组清空
** 参数: 数组
*/
void ClearArray(PArray array);

/*
** 操作: 销毁数组
** 参数: 数组
*/
void DestroyArray(PArray array);

/*
** 操作: 返回数组中第i个位置的元素
** 参数:
** 1. 数组
** 2. 位置i
** 3. 用于返回值的指针
** 返回值:
** 1. 若查找位置不合理, 返回1
** 2. 若数组为空, 返回-1
** 3. 否则查找成功返回0
*/
int GetElem(PArray array, int i, ElemType *elem);

/*
** 操作: 定位元素在数组中的位置
** 参数:
** 1. 数组
** 2. 需要定位的元素
** 返回值:
** 1. 若数组为空, 返回-1
** 2. 若元素不存在, 返回0
** 3. 否则查找成功返回位序
*/
int LocateElem(PArray array, ElemType *elem);

/*
** 操作: 插入元素到数组第i个位置
** 参数:
** 1. 数组
** 2. 位置i
** 3. 待插入元素
** 返回值:
** 1. 若数组已满返回-1
** 2. 若插入位置不合理返回1
** 3. 否则执行操作返回0
*/
int ArrayInsert(PArray array, int i, ElemType *elem);

/*
** 操作: 删除数组中第i个位置的元素
** 参数:
** 1. 数组
** 2. 位置i
** 3. 用于返回被删除的元素
** 返回值:
** 1. 若数组为空返回-1
** 2. 若删除位置不合理返回1
** 3. 否则执行操作返回0
*/
int ArrayDelete(PArray array, int i, ElemType *elem);

/*
** 操作: 返回数组的长度(有效值个数)
** 参数: 数组
** 返回值: 数组的长度
*/
int ArrayLength(PArray array);

#endif