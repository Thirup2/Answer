/* 静态链表接口函数文件StaticList.c */

/* 包含头文件 */
#include "StaticList.h"

/* 局部函数原型 */

/*
** 操作: 模拟malloc函数, 返回备用链表第一个元素的下标, 并设置新的备用链表
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 返回备用链表的第一个元素的下标
*/
int malloc_sl(StaticList list);

/*
** 操作: 模拟free函数, 将被释放元素的next指向之前的备用链表, 更新备用链表信息
** 参数: 一个静态链表, 一个待释放的元素的下标
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void free_sl(StaticList list, int i);

/*
** 操作: 打印错误信息
** 参数: 一个字符串
*/
void printerr(const char *err);

/* 数据元素处理函数定义 */

/*
** 操作: 比较两个数据元素是否相同
** 参数: 两个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若两元素相同则返回true;
** 3. 若两元素不相同则返回false
*/
bool CompareElems(ElemType const *elem1, ElemType const *elem2)
{
    if (!elem1) {
        printerr("参数一");
    }
    if (!elem2) {
        printerr("参数二");
    }
    if (elem1->x == elem2->x) {
        if (elem1->y == elem2->y) {
            return true;
        }
    }
    return false;
}

/*
** 操作: 将一个数据元素赋值给另一个数据元素
** 参数: 两个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ChangeElem(ElemType *elem, ElemType const *data)
{
    if (!elem) {
        printerr("待赋值元素");
    }
    if (!data) {
        printerr("赋值元素");
    }
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素的内容
** 参数: 一个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ShowElem(ElemType const *elem)
{
    if (!elem) {
        printerr("待打印元素");
    }
    printf("(%d, %d) ", elem->x, elem->y);
}

/* 静态链表接口函数定义 */

/*
** 操作: 判断静态链表是否为空
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空则返回true
** 3. 不为空返回false
*/
bool ListEmpty(StaticList list)
{
    if (!list) {
        printerr("静态链表");
    }
    if (list[MAXSIZE - 1].data.x == 0) {
        return true;
    } else {
        return false;
    }
}

/*
** 操作: 返回静态链表的长度
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 返回链表的长度
*/
int ListLength(StaticList list)
{
    if (!list) {
        printerr("静态链表");
    }
    return list[MAXSIZE - 1].data.x;
}

/*
** 操作: 打印静态链表所有元素的内容
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ListTraverse(StaticList list)
{
    if (!list) {
        printerr("静态链表");
    }
    int i = list[MAXSIZE - 1].next;
    while (i) {
        ShowElem(&(list[i].data));
        i = list[i].next;
    }
    printf("\n");
}

/*
** 操作: 初始化静态链表, 初始化内容如下:
** 1. 各元素的next成员初始化为下一个元素的下标, 最后一个元素初始化为0
** 2. list.LENGTH初始化为0
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void InitList(StaticList list)
{
    if (!list) {
        printerr("静态链表");
    }
    for (int i = 0; i < MAXSIZE - 1; i++) {
        list[i].next = i + 1;
    }
    list[MAXSIZE - 1].next = 0;
    list LENGTH = 0;
}

/*
** 操作: 插入元素, 具体操作如下:
** 1. 在指定位置插入元素
** 2. 表长++
** 参数: 一个链表指针, 一个位序, 一个待插入元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表已满返回-1;
** 3. 若插入位序不合理则返回1;
** 4. 否则执行操作并返回0
*/
int ListInsert(StaticList list, int i, ElemType const *elem)
{
    if (!list) {
        printerr("静态链表");
    }
    if (!elem) {
        printerr("待插入元素");
    }
    if (list[0].next == MAXSIZE - 1) {
        return -1;
    }
    if (i <= 0 || i > ListLength(list) + 1) {
        return 1;
    }
    int m = MAXSIZE - 1;
    int count = 1;
    while (count != i) {
        m = list[m].next;
        count++;
    }
    int n = malloc_sl(list);
    list[n].next = list[m].next;
    list[m].next = n;
    ChangeElem(&(list[n].data), elem);
    list LENGTH++;
    return 0;
}

/*
** 操作: 删除元素, 具体操作如下:
** 1. 将待删除位置的元素赋给第三参数
** 2. 删除指定位置的元素
** 3. 表长--
** 参数: 一个链表指针, 一个待删除位序, 一个待返回指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空则返回-1;
** 3. 若位序不合理则返回1;
** 4. 否则执行操作并返回0
*/
int ListDelete(StaticList list, int i, ElemType *elem)
{
    if (!list) {
        printerr("静态链表");
    }
    if (!elem) {
        printerr("待返回元素");
    }
    if (ListEmpty(list)) {
        return -1;
    }
    if (i <= 0 || i > ListLength(list)) {
        return 1;
    }
    int j = MAXSIZE - 1;
    int k = list[j].next;
    int count = 1;
    while (count != i) {
        j = k;
        k = list[k].next;
        count++;
    }
    ChangeElem(elem, &(list[k].data));
    list[j].next = list[k].next;
    free_sl(list, k);
    list LENGTH--;
    return 0;
}

/*
** 操作: 修改元素, 具体操作如下:
** 1. 将待修改元素赋值给第四参数
** 2. 用第三参数修改待修改位序的元素
** 参数: 一个链表指针, 一个待修改位序, 一个用于修改的元素指针, 一个待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空返回-1;
** 3. 若待修改位序不合理返回1;
** 4. 否则执行操作返回0
*/
int ListChange(StaticList list, int i, ElemType const *data, ElemType *elem)
{
    if (!list) {
        printerr("静态链表");
    }
    if (!data) {
        printerr("修改元素");
    }
    if (!elem) {
        printf("待返回元素");
    }
    if (ListEmpty(list)) {
        return -1;
    }
    if (i <= 0 || i > ListLength(list)) {
        return 1;
    }
    int j = MAXSIZE - 1;
    int count = 0;
    while (count != i) {
        j = list[j].next;
        count++;
    }
    ChangeElem(elem, &(list[j].data));
    ChangeElem(&(list[j].data), data);
    return 0;
}

/*
** 操作: 查找元素位序
** 参数: 一个链表指针, 一个待查找元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空返回-1;
** 3. 若待查找元素不存在返回0;
** 4. 否则返回该元素的位序
*/
int LocateElem(StaticList list, ElemType const *elem)
{
    if (!list) {
        printerr("静态链表");
    }
    if (!elem) {
        printerr("待查找元素");
    }
    if (ListEmpty(list)) {
        return -1;
    }
    int count = 1;
    int i = list[MAXSIZE - 1].next;
    while (i) {
        if (CompareElems(&(list[i].data), elem)) {
            return count;
        }
        i = list[i].next;
        count++;
    }
    return 0;
}

/*
** 操作: 查找元素, 并将该元素赋值给待返回参数
** 参数: 一个链表指针, 一个待查找位序, 一个待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空返回-1;
** 3. 若查找位序不合理返回1;
** 4. 否则执行操作返回0
*/
int ListSearch(StaticList list, int i, ElemType *elem)
{
    if (!list) {
        printerr("静态链表");
    }
    if (!elem) {
        printerr("待返回元素");
    }
    if (ListEmpty(list)) {
        return -1;
    }
    if (i <= 0 || i > list LENGTH) {
        return 1;
    }
    int j = MAXSIZE - 1;
    int count = 0;
    while (count != i) {
        j = list[j].next;
        count++;
    }
    ChangeElem(elem, &(list[j].data));
    return 0;
}

/*
** 操作: 销毁或清空链表
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ClearList(StaticList list)
{
    if (!list) {
        printerr("静态链表");
    }
    for (int i = 0; i < MAXSIZE - 1; ++i) {
        list[i].next = i + 1;
    }
    list[MAXSIZE - 1].next = 0;
    list LENGTH = 0;
}

/* 局部函数定义 */

/*
** 操作: 模拟malloc函数, 返回备用链表第一个元素的下标, 并设置新的备用链表
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 返回备用链表的第一个元素的下标
*/
int malloc_sl(StaticList list)
{
    if (!list) {
        printerr("静态链表");
    }
    int i = list[0].next;
    list[0].next = list[i].next;

    return i;
}

/*
** 操作: 模拟free函数, 将被释放元素的next指向之前的备用链表, 更新备用链表信息
** 参数: 一个静态链表, 一个待释放的元素的下标
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void free_sl(StaticList list, int i)
{
    if (!list) {
        printerr("静态链表");
    }
    list[i].next = list[0].next;
    list[0].next = i;
}

/*
** 操作: 打印错误信息
** 参数: 一个字符串
*/
void printerr(const char *err)
{
    printf("错误: %s指针错误!\n", err);
    exit(EXIT_FAILURE);
}