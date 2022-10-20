/* 一维数组接口函数定义文件Array.c */

/* 包含头文件 */
#include "Array.h"

/* 数据元素处理函数定义 */

/*
** 操作: 比较两个元素是否相同
** 参数: 两个元素的指针
** 返回值:
** 1. 若相同, 返回true
** 2. 否则, 返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2)
{
    if (elem1->x == elem2->x && elem1->y == elem2->y) {
        return true;
    }
    return false;
}

/*
** 操作: 交换两个数据元素的值
** 参数: 两个数据元素
*/
void ExchangeElem(ElemType *elem, ElemType *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素
** 参数: 数据元素指针
*/
void PrintElem(ElemType *elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/*
** 操作: 读取一个数据元素
** 参数: 存放地址
*/
void ScanElem(ElemType *elem)
{
    printf("请输入数据元素值(按\"x, y\"的格式输入): ");
    scanf("%d, %d", &(elem->x), &(elem->y));
}

/* 一维数组接口函数定义 */

/*
** 操作: 初始化数组
** 1. 创建一个空的线性表
** 2. 表长为1, 即哨兵位
** 返回值: 初始化的数组
*/
PArray InitArray(void)
{
    PArray array = (PArray) malloc(sizeof(Array));
    if (!array) {
        exit(EXIT_FAILURE);
    }
    array->data = (ElemType *) malloc(sizeof(ElemType));
    if (!array->data) {
        exit(EXIT_FAILURE);
    }
    array->length = 0;
    return array;
}

/*
** 操作: 判断数组是否为空
** 参数: 数组
** 返回值:
** 1. 若为空(只含有哨兵位)返回true
** 2. 否则返回false
*/
bool ArrayEmpty(PArray array)
{
    if (ArrayLength(array) == 0) {
        return true;
    }
    return false;
}

/*
** 操作: 将数组清空
** 参数: 数组
*/
void ClearArray(PArray array)
{
    array->data = (ElemType *) realloc(array->data, sizeof(ElemType));
    array->length = 0;
}

/*
** 操作: 销毁数组
** 参数: 数组
*/
void DestroyArray(PArray array)
{
    free(array->data);
    free(array);
}

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
int GetElem(PArray array, int i, ElemType *elem)
{
    if (ArrayEmpty(array)) {
        return -1;
    }
    if (i<1 || i>ArrayLength(array)) {
        return 1;
    }
    ExchangeElem(elem, &(array->data[i]));
    return 0;
}

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
int LocateElem(PArray array, ElemType *elem)
{
    if (ArrayEmpty(array)) {
        return -1;
    }
    array->data[0].x = elem->x;
    array->data[0].y = elem->y;
    int i = ArrayLength(array);
    while (!CompareElem(elem, &(array->data[i]))) {
        i--;
    }
    return i;
}

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
int ArrayInsert(PArray array, int i, ElemType *elem)
{
    if (i<1 || i>ArrayLength(array) + 1) {
        return 1;
    }
    array->data = (ElemType *) realloc(array->data, (ArrayLength(array) + 2) * sizeof(ElemType));
    if (!array->data) {
        return -1;
    }
    array->length++;
    for (int n = ArrayLength(array); n > i; n--) {
        ExchangeElem(&(array->data[n]), &(array->data[n - 1]));
    }
    ExchangeElem(&(array->data[i]), elem);
    return 0;
}

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
int ArrayDelete(PArray array, int i, ElemType *elem)
{
    if (ArrayLength(array) == 0) {
        return -1;
    }
    if (i<1 || i>ArrayLength(array)) {
        return 1;
    }
    ExchangeElem(elem, &(array->data[i]));
    for (; i < array->length; i++) {
        ExchangeElem(&(array->data[i]), &(array->data[i + 1]));
    }
    array->length--;
    return 0;
}

/*
** 操作: 返回数组的长度(有效值个数)
** 参数: 数组
** 返回值: 数组的长度
*/
int ArrayLength(PArray array)
{
    return array->length;
}