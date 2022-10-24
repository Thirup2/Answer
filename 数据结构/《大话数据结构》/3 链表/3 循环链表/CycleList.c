/* 循环链表接口函数文件CycleList.c */

/* 包含头文件 */
#include "CycleList.h"

/* 数据元素处理函数原型 */

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

/* 链表接口函数原型 */

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
    list->length = 0;
    list->head = NULL;
    list->head = (PtrNode) malloc(sizeof(Node));
    if (!list->head) {
        exit(EXIT_FAILURE);
    }
    list->head->next = NULL;
    list->last = list->head;
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
    PtrNode p = list->head->next;
    PtrNode s;
    while (p != list->last) {
        s = p;
        p = p->next;
        free(s);
    }
    free(p);
    list->head->next = NULL;
    list->last = list->head;
    list->length = 0;
}

/*
** 操作: 销毁链表
** 参数: 链表指针
*/
void DestroyList(List list)
{
    PtrNode p = list->head;
    PtrNode s;
    while (p != list->last) {
        s = p;
        p = p->next;
        free(s);
    }
    free(p);
    free(list);
    list = NULL;
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
    PtrNode p = list->head->next;
    int n = 1;
    while (n < i) {
        n++;
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
    int n = 1;
    PtrNode p = list->head->next;
    while (p != list->last) {
        if (CompareElem(elem, &(p->data))) {
            return n;
        }
        n++;
        p = p->next;
    }
    if (CompareElem(elem, &(p->data))) {
        return n;
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
    PtrNode Nod = (PtrNode) malloc(sizeof(Node));
    if (!Nod) {
        return -1;
    }
    CopyElem(&(Nod->data), elem);
    if (ListLength(list) == 0) {
        list->head->next = Nod;
        Nod->next = Nod;
        list->last = Nod;
    } else if (i == ListLength(list) + 1) {
        Nod->next = list->last->next;
        list->last->next = Nod;
        list->last = Nod;
    } else {
        int k = 2;
        PtrNode p = list->head->next;
        while (k < i) {
            k++;
            p = p->next;
        }
        Nod->next = p->next;
        p->next = Nod;
    }
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
    PtrNode p = list->head;
    PtrNode s;
    int k = 1;
    while (k < i) {
        p = p->next;
        k++;
    }
    s = p->next;
    CopyElem(elem, &(s->data));
    p->next = s->next;
    free(s);
    if (i == ListLength(list)) {
        list->last = p;
    }
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
    PtrNode p = list->head;
    while (list->last != p) {
        p = p->next;
        PrintElem(&(p->data));
    }
    printf("\n");
}