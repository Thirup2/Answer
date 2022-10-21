/* 单链表接口函数文件LinkList.c */

/* 包含头文件 */
#include "LinkList.h"

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
    scanf("%d, %d", &(elem->x), &(elem->y));
}

/* 链表接口函数元素 */

/*
** 操作: 初始化操作, 建立一个空链表(包含一个头结点)
** 返回值: 链表指针类型
*/
List InitList(void)
{
    List list = (List) malloc(sizeof(LinkList));
    if (!list) {
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    list->head = (PNode) malloc(sizeof(Node));
    if (!list->head) {
        exit(EXIT_FAILURE);
    }
    list->head->next = NULL;
    list->length = 0;
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
    if (list->length == 0) {
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
    PNode p = list->head->next;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
    list->head->next = NULL;
    list->length = 0;
}

/*
** 操作: 销毁链表
** 参数: 链表指针
*/
void DestroyList(List list)
{
    PNode p = list->head;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
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
    PNode p = list->head->next;
    int j = 1;
    for (; j < i; j++) {
        p = p->next;
    }
    CopyElem(elem, &(p->data));
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
    PNode p = list->head->next;
    int i = 1;
    while (p) {
        if (CompareElem(elem, &(p->data))) {
            return i;
        }
        i++;
        p = p->next;
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
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        return -1;
    }
    CopyElem(&(p->data), elem);
    int j = 1;
    PNode s = list->head;
    for (; j < i; j++) {
        s = s->next;
    }
    p->next = s->next;
    s->next = p;
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
    int j = 1;
    PNode p = list->head;
    for (; j < i; j++) {
        p = p->next;
    }
    PNode s = p->next;
    CopyElem(elem, &(s->data));
    p->next = s->next;
    free(s);
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
    PNode p = list->head->next;
    while (p) {
        PrintElem(&(p->data));
        p = p->next;
    }
    printf("\n");
}