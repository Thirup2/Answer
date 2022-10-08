/* 静态链表接口头文件StaticList.h */
#ifndef _STATICLIST_H_
#define _STATICLIST_H_

/* 包含头文件 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 数据结构定义 */
#define MAXSIZE 1000                // 静态链表初始内存大小
struct elem
{
    int x;
    int y;
};                                  // 数据项
typedef struct elem ElemType;       // 数据元素类型
struct node
{
    ElemType data;                  // 数据域
    int next;                       // 链
};
typedef struct node Node;           // 结点类型
typedef Node StaticList[MAXSIZE];   // 静态链表类型
#define LENGTH [MAXSIZE-1].data.x   // 最后一个元素的数据域的x成员为表长

/* 数据元素处理函数原型 */

/*
** 操作: 比较两个数据元素是否相同
** 参数: 两个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若两元素相同则返回true;
** 3. 若两元素不相同则返回false
*/
bool CompareElems(ElemType const *elem1, ElemType const *elem2);

/*
** 操作: 将一个数据元素赋值给另一个数据元素
** 参数: 两个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ChangeElem(ElemType *elem, ElemType const *data);

/*
** 操作: 打印一个数据元素的内容
** 参数: 一个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ShowElem(ElemType const *elem);

/* 静态链表接口函数原型 */

/*
** 操作: 判断静态链表是否为空
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空则返回true
** 3. 不为空返回false
*/
bool ListEmpty(StaticList list);

/*
** 操作: 返回静态链表的长度
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 返回链表的长度
*/
int ListLength(StaticList list);

/*
** 操作: 打印静态链表所有元素的内容
** 参数: 一个静态链表
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ListTraverse(StaticList list);

/*
** 操作: 初始化静态链表, 初始化内容如下:
** 1. 各元素的next成员初始化为下一个元素的下标, 最后一个元素初始化为0
** 2. list.LENGTH初始化为0
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void InitList(StaticList list);

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
int ListInsert(StaticList list, int i, ElemType const *elem);

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
int ListDelete(StaticList list, int i, ElemType *elem);

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
int ListChange(StaticList list, int i, ElemType const *data, ElemType *elem);

/*
** 操作: 查找元素位序
** 参数: 一个链表指针, 一个待查找元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空返回-1;
** 3. 若待查找元素不存在返回0;
** 4. 否则返回该元素的位序
*/
int LocateElem(StaticList list, ElemType const *elem);

/*
** 操作: 查找元素, 并将该元素赋值给待返回参数
** 参数: 一个链表指针, 一个待查找位序, 一个待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空返回-1;
** 3. 若查找位序不合理返回1;
** 4. 否则执行操作返回0
*/
int ListSearch(StaticList list, int i, ElemType *elem);

/*
** 操作: 销毁或清空链表
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
*/
void ClearList(StaticList list);

#endif