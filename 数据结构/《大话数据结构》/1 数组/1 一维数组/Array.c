/* 一维数组接口函数文件Array.c */
/* 包含头文件 */
#include "Array.h"


/* 数据处理函数定义 */

/*
** 操作: 比较两数据元素是否相同
** 参数: 两个元素为将要进行比较的数据元素, 以指针形式传入
** 返回值: 若参数一为NULL返回-1, 若参数二为NULL, 返回-2; 若两数据元素相同, 返回0, 不相同则返回1
*/
int CompareElems(ElemType const *data, ElemType const *elem)
{
    if (!data) {
        return -1;          // 参数一为NULL
    }
    if (!elem) {
        return -2;          // 参数二为NULL
    }
    if (*data == *elem) {
        return 0;           // 两元素相同
    } else {
        return 1;           // 两元素不同
    }
}

/*
** 操作: 将一个数据元素的值赋值给另一个数据元素
** 参数: 第一个参数是被修改的元素, 第二个参数是用于修改的值. 两元素都以指针形式传入
** 返回值: 参数一为NULL, 返回-1, 若参数二为NULL, 返回-2; 操作成功返回0
*/
int ChangeElem(ElemType *data, ElemType const *elem)
{
    if (!data) {
        return -1;          // 某参数为NULL
    }
    if (!elem) {
        return -2;          // 参数二为NULL
    }
    *data = *elem;
    return 0;
}

/*
** 操作: 将一个数据元素显示出来
** 参数: 将要显示的元素的指针
** 返回值: 若指针为NULL, 返回false, 否则返回true
*/
bool ShowElem(ElemType const *data)
{
    if (!data) {
        return false;           // 参数为NULL
    }
    printf("%d ", *data);
    return true;
}


/* 接口函数定义 */

/*
** 操作: 初始化一个一维数组. 数组长度置为0
** 参数: 一个准备初始化的数组指针
** 返回值: 若参数为NULL, 返回false, 否则进行初始化并返回true
*/
bool InitArray(Array *array)
{
    if (!array) {
        return false;       // 参数为NULL
    }
    array->length = 0;
    return true;
}

/*
** 操作: 清空数组
** 参数: 待操作的数组指针
** 返回值: 若参数为NULL, 返回false, 否则执行操作返回true
*/
bool ClearArray(Array *array)
{
    if (!array) {
        return false;
    }
    array->length = 0;
    return true;
}

/*
** 操作: 判断数组是否为空
** 参数: 指向数组的指针
** 返回值: 若参数为NULL, 返回-1; 若数组为空, 返回0, 否则返回非0
*/
int ArrayEmpty(Array const *array)
{
    if (!array) {
        return -1;
    }
    return array->length;
}

/*
** 操作: 打印数组当前所有值
** 参数: 指向数组的指针
** 返回值: 若参数为NULL, 返回false; 否则执行操作返回true
*/
bool ArrayTraverse(Array const *array)
{
    if (!array) {
        return false;
    }
    if (array->length != 0) {
        for (int i = 0; i < array->length; ++i) {
            ShowElem(&(array->data[i]));
        }
    }
    printf("\n");
    return true;
}

/*
** 操作: 插入值
** 参数: 指向数组的指针, 即将插入的位序, 以及即将插入的新值的指针
** 返回值: 若数组指针为NULL, 返回-1. 若新值指针为NULL, 返回-2. 若数组已满, 返回1. 若位序不合理, 返回2. 操作成功返回0
*/
int ArrayInsert(Array *array, int i, ElemType const *elem)
{
    if (!array) {
        return -1;
    }
    if (!elem) {
        return -2;
    }
    if (array->length == MAXSIZE) {
        return 1;
    }
    if (i <= 0 || i > array->length + 1) {
        return 2;
    }
    for (int j = array->length; j >= i; j--) {
        array->data[j] = array->data[j - 1];
    }
    array->data[i - 1] = *elem;
    array->length++;
    return 0;
}

/*
** 操作: 按序删除值, 并将被删除值赋给第三参数
** 参数: 数组指针, 删除位序
** 返回值: 若数组指针为NULL, 返回-1. 若返回参数为NULL, 返回-2. 若位序不合理, 返回1.
*/
int ArrayDelete(Array *array, int i, ElemType *elem)
{
    if (!array) {
        return -1;
    }
    if (!elem) {
        return -2;
    }
    if (i <= 0 || i > array->length) {
        return 1;
    }
    *elem = array->data[i - 1];
    for (; i < array->length; ++i) {
        array->data[i - 1] = array->data[i];
    }
    array->length--;
    return 0;
}

/*
** 操作: 按序更改值, 并将被更改值赋给第四参数
** 参数: 数组指针, 待更改位序, 待替换值, 被替换值
** 返回值: 若数组指针为NULL, 返回-1. 若位序不合理, 返回-2. 若被替换值为NULL, 返回-3. 若替换值为NULL, 返回-4. 操作成功返回0
*/
int ArrayChange(Array *array, int i, ElemType const *elem, ElemType *data)
{
    if (!array) {
        return -1;
    }
    if (!data) {
        return -3;
    }
    if (!elem) {
        return -4;
    }
    if (i <= 0 || i > array->length) {
        return -2;
    }
    *data = array->data[i - 1];
    array->data[i - 1] = *elem;
    return 0;
}

/*
** 操作: 查找某个值的位序
** 参数: 数组指针, 待查找值
** 返回值: 待查找值在数组中的位序. 若数组指针为NULL, 返回-1. 若待查找值为NULL, 返回-2. 若不存在该值返回0
*/
int ArrayLocate(Array *array, ElemType const *elem)
{
    if (!array) {
        return -1;
    }
    if (!elem) {
        return -2;
    }
    for (int i = 0; i < array->length; ++i) {
        if (array->data[i] == *elem) {
            return i + 1;
        }
    }
    return 0;
}

/*
** 操作: 查找某个位序的值, 并将该值赋给第三参数
** 参数: 数组指针, 待查位序, 被查找值
** 返回值: 若数组指针为NULL, 返回-1. 若待查值为NULL, 返回-2. 若位序不合理, 返回-3. 否则返回0
*/
int ArraySearch(Array *array, int i, ElemType *elem)
{
    if (!array) {
        return -1;
    }
    if (!elem) {
        return -2;
    }
    if (i <= 0 || i > array->length) {
        return -3;
    }
    *elem = array->data[i - 1];
    return 0;
}