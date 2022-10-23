/* 静态链表接口函数文件StaticList.c */

/* 包含头文件 */
#include "StaticList.h"

/* 局部函数原型 */

/*
** 操作: 模拟malloc函数
** 参数: 静态链表
** 返回值: 被申请的位置下标
*/
int Malloc_SSL(List list);

/*
** 操作: 模拟free函数
** 参数:
** 1. 静态链表
** 2. 需要释放的内存
*/
void Free_SSL(List list, int k);

/* 数据元素处理函数定义 */

/*
** 操作: 比较两个数据元素
** 参数: 两个数据元素指针
** 返回值:
** 1. 若相同返回true
** 2. 否则返回false
*/
bool CompareElem(ElemType *elem1, ElemType *elem2)
{
    if (elem1->x == elem2->x && elem1->y == elem2->y) {
        return true;
    }
    return false;
}

/*
** 操作: 给数据元素赋值
** 参数:
** 1. 被赋值的元素
** 2. 用于赋值的元素
*/
void CopyElem(ElemType *elem, ElemType *data)
{
    elem->x = data->x;
    elem->y = data->y;
}

/*
** 操作: 打印一个数据元素
** 参数: 一个数据元素
*/
void PrintElem(ElemType *elem)
{
    printf("(%d, %d) ", elem->x, elem->y);
}

/*
** 操作: 读取一个数据元素
** 参数: 一个元素指针
*/
void ScanElem(ElemType *elem)
{
    printf("请输入一个数据元素(按\"x, y\"的格式): ");
    scanf("%d, %d", &elem->x, &elem->y);
}

/* 链表接口函数定义 */

/*
** 操作: 初始化操作, 建立一个空链表
** 返回值: 链表指针类型
*/
List InitList(void)
{
    List list = (List) malloc(sizeof(LinkList));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->array = NULL;
    list->array = (PtrComponent) malloc(MAXSIZE * sizeof(Component));
    if (!list->array) {
        exit(EXIT_FAILURE);
    }
    list->length = 0;
    for (int i = 0; i < MAXSIZE - 1; i++) {
        list->array[i].cur = i + 1;
    }
    list->array[MAXSIZE - 1].cur = 0;
    return list;
}

/*
** 操作: 判断链表是否为空
** 参数: 链表指针
** 返回值:
** 1. 若链表为空返回true
** 2. 否则返回false
*/
bool ListEmpty(List list)
{
    if (ListLength(list) == 0) {
        return true;
    }
    return false;
}

/*
** 操作: 将链表清空
** 参数: 链表指针
*/
void ClearList(List list)
{
    list->length = 0;
    for (int i = 0; i < MAXSIZE - 1; i++) {
        list->array[i].cur = i + 1;
    }
    list->array[MAXSIZE - 1].cur = 0;
}

/*
** 操作: 销毁链表
** 参数: 链表指针
*/
void DestroyList(List list)
{
    free(list->array);
    free(list);
}

/*
** 操作: 返回链表中第i个位置的元素
** 参数:
** 1. 链表指针
** 2. 位置i
** 3. 用于返回元素的指针
** 返回值:
** 1. 若链表为空, 返回-1
** 2. 若位置不合理, 返回1
** 3. 否则执行操作返回0
*/
int GetElem(List list, int i, ElemType *elem)
{
    if (ListEmpty(list)) {
        return -1;
    }
    if (i<1 || i>ListLength(list)) {
        return 1;
    }
    int cnt = 1;
    int k = list->array[HEAD].cur;
    while (cnt != i) {
        k = list->array[k].cur;
        cnt++;
    }
    CopyElem(elem, &(list->array[k].data));
    return 0;
}

/*
** 操作: 定位元素在链表中的位置
** 参数:
** 1. 链表指针
** 2. 待定位的元素指针
** 返回值:
** 1. 若链表为空则返回-1
** 2. 若无该元素返回0
** 3. 否则返回该元素的位序
*/
int LocateElem(List list, ElemType *elem)
{
    if (ListEmpty(list)) {
        return -1;
    }
    int k = 1;
    int i = list->array[HEAD].cur;
    while (i) {
        if (CompareElem(elem, &(list->array[i].data))) {
            return k;
        }
        k++;
        i = list->array[i].cur;
    }
    return 0;
}

/*
** 操作: 插入元素到链表
** 参数:
** 1. 链表指针
** 2. 插入位序
** 3. 插入元素
** 返回值:
** 1. 若链表已满返回-1
** 2. 若插入位序不合理返回1
** 3. 否则执行操作返回0
*/
int ListInsert(List list, int i, ElemType *elem)
{
    if (i<1 || i>ListLength(list) + 1) {
        return 1;
    }
    int p = Malloc_SSL(list);
    if (!p) {
        return -1;
    }
    int h = HEAD;
    while (list->array[h].cur) {
        h = list->array[h].cur;
    }
    list->array[p].cur = list->array[h].cur;
    list->array[h].cur = p;
    CopyElem(&(list->array[p].data), elem);
    list->length++;
    return 0;
}

/*
** 操作: 删除链表中第i个位置的元素
** 参数:
** 1. 链表指针
** 2. 删除位序
** 3. 用于返回的元素
** 返回值:
** 1. 若链表为空返回-1
** 2. 若删除位序不合理返回1
** 3. 否则执行操作返回0
*/
int ListDelete(List list, int i, ElemType *elem)
{
    if (ListEmpty(list)) {
        return -1;
    }
    if (i<1 || i>ListLength(list)) {
        return 1;
    }
    int k = HEAD;
    int cnt = 1;
    while (cnt != i) {
        cnt++;
        k = list->array[k].cur;
    }
    int p = list->array[k].cur;
    CopyElem(elem, &(list->array[p].data));
    list->array[k].cur = list->array[p].cur;
    Free_SSL(list, p);
    list->length--;
    return 0;
}

/*
** 操作: 返回链表的元素个数
** 参数: 链表指针
** 返回值: 链表元素个数
*/
int ListLength(List list)
{
    return list->length;
}

/*
** 操作: 打印链表元素
** 参数: 链表指针
*/
void PrintList(List list)
{
    int i = list->array[HEAD].cur;
    while (i) {
        PrintElem(&(list->array[i].data));
        i = list->array[i].cur;
    }
    printf("\n");
}

/* 局部函数定义 */

/*
** 操作: 模拟malloc函数
** 参数: 静态链表
** 返回值: 被申请的位置下标
*/
int Malloc_SSL(List list)
{
    if (ListLength(list) == MAXSIZE - 2) {
        return 0;
    }
    int r = list->array[PRELIST].cur;
    list->array[PRELIST].cur = list->array[r].cur;
    return r;
}

/*
** 操作: 模拟free函数
** 参数:
** 1. 静态链表
** 2. 需要释放的内存
*/
void Free_SSL(List list, int k)
{
    list->array[k].cur = list->array[PRELIST].cur;
    list->array[PRELIST].cur = k;
}