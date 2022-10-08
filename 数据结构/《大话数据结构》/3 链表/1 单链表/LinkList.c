/* 单链表接口函数文件LinkList.c */

/* 包含头文件 */
#include "LinkList.h"

/* 数据元素处理函数定义 */

/*
** 操作: 比较两个数据元素是否相同
** 参数: 两个数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若两元素相同则返回1;
** 3. 若不同返回0
*/
int CompareElems(ElemType const *elem1, ElemType const *elem2)
{
    if (!elem1) {
        printf("错误: 第一个参数指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem2) {
        printf("错误: 第二个参数指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (elem1->x == elem2->x) {
        if (elem1->y == elem2->y) {
            return 1;
        }
    }
    return 0;
}

/*
** 操作: 将一个数据元素赋值给另一个数组元素
** 参数: 第一个参数为被赋值的元素, 第二个参数为赋值的元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ChangeElem(ElemType *data, ElemType const *elem)
{
    if (!data) {
        printf("错误: 被赋值元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem) {
        printf("错误: 赋值元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    data->x = elem->x;
    data->y = elem->y;
}

/*
** 操作: 打印一个数据元素的内容
** 参数: 一个待打印的数据元素
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void ShowElem(ElemType const *elem)
{
    if (!elem) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    printf("(%d, %d) ", elem->x, elem->y);
}

/*
** 操作: 获取一个元素
** 参数: 一个元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出
*/
void GetElem(ElemType *elem)
{
    if (!elem) {
        printf("错误: 元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    printf("请输入用于修改的值, 按照以下形式输入: (x, y)\n");
c1: if (scanf("(%d, %d)", &(elem->x), &(elem->y))==2) {
        return;
    } else {
        printf("您的输入有误, 请重新输入: ");
        while (getchar() != '\n');
        goto c1;
    }
}

/* 单链表接口函数元素 */

/*
** 操作: 判断一个链表是否为空
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表为空, 返回1;
** 3. 否则返回0
*/
int ListEmpty(LinkList const *list)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (list->length == 0) {
        return 1;
    } else {
        return 0;
    }
}

/*
** 操作: 返回链表的元素个数
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 否则返回链表元素个数
*/
int ListLength(LinkList const *list)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    return list->length;
}

/*
** 操作: 打印链表所有元素的内容
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 链表未初始化返回-1;
** 3. 否则执行操作返回0
*/
int ListTraverse(LinkList const *list)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    PNode p = list->start;
    if (!p) {
        return -1;      // 链表未初始化
    }
    p = p->next;
    while (p) {
        ShowElem(&(p->data));
        p = p->next;
    }
    printf("\n");
    return 0;
}

/*
** 操作: 初始化链表, 创建一个头结点并使头指针指向头结点, 表长设置为0
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 头结点创建失败返回-1;
** 3. 否则执行操作返回0
*/
int InitList(LinkList *list)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        return -1;               // 创建结点失败
    }
    p->next = NULL;
    list->start = p;
    list->length = 0;
    return 0;
}

/*
** 操作: 清除链表内容, 只保留头结点, 表长置为0
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化则返回-1;
** 3. 否则执行操作返回0
*/
int ClearList(LinkList *list)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (list->start == NULL) {
        return -1;           // 链表未初始化
    }
    PNode p = list->start->next;
    PNode pc;
    while (p) {
        pc = p;
        p = p->next;
        free(pc);
    }
    list->start->next = NULL;
    list->length = 0;
    return 0;
}

/*
** 操作: 插入元素, 表长加1
** 参数: 一个链表指针, 待插入的位序, 待插入的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 链表未初始化返回-1
** 3. 若插入位序不合理返回1;
** 4. 若链表已满返回-2;
** 5. 否则执行操作返回0
*/
int ListInsert(LinkList *list, int i, ElemType const *elem)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem) {
        printf("错误: 待插入元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!list->start) {
        return -1;          // 链表未初始化
    }
    if (i <= 0 || i > list->length + 1) {
        return 1;           // 插入位序不合理
    }
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        return -2;          // 链表已满
    }
    PNode pc = list->start;
    int count = 0;
    while (count != i - 1) {
        pc = pc->next;
        ++count;
    }
    p->next = pc->next;
    pc->next = p;
    list->length++;
    ChangeElem(&(p->data), elem);
    return 0;
}

/*
** 操作: 删除元素, 表长减1, 并将被删除的元素赋值给第三参数
** 参数: 一个链表指针, 待删除的位序, 待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表无元素返回-2;
** 4. 若删除位序不合理返回1;
** 5. 否则执行操作返回0
*/
int ListDelete(LinkList *list, int i, ElemType *elem)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem) {
        printf("错误: 返回元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!list->start) {
        return -1;          // 链表未初始化
    }
    if (list->length == 0) {
        return -2;          // 链表无元素
    }
    if (i <= 0 || i > list->length) {
        return 1;           // 删除位序不合理
    }
    PNode pre = list->start->next;
    PNode beh = list->start;
    int count = 1;
    while (count != i) {
        pre = pre->next;
        beh = beh->next;
        ++count;
    }
    beh->next = pre->next;
    ChangeElem(elem, &(pre->data));
    free(pre);
    list->length--;
    return 0;
}

/*
** 操作: 修改元素内容, 并将被修改元素赋值给第四参数
** 参数: 一个链表指针, 待修改的位序, 用于修改的元素, 被修改的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表无元素返回-2;
** 4. 若位序不合理返回1;
** 5. 否则执行操作返回0
*/
int ListChange(LinkList *list, int i, ElemType const *data, ElemType *elem)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!data) {
        printf("错误: 修改元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem) {
        printf("错误: 被修改元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!list->start) {
        return -1;          // 链表未初始化
    }
    if (list->length == 0) {
        return -2;          // 链表无元素
    }
    if (i <= 0 || i > list->length) {
        return 1;           // 位序不合理
    }
    PNode p = list->start->next;
    int count = 1;
    while (count != i) {
        p = p->next;
        ++count;
    }
    ChangeElem(elem, &(p->data));
    ChangeElem(&(p->data), data);
    return 0;
}

/*
** 操作: 定位某个元素在链表中的位序
** 参数: 一个链表指针, 待查找的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表无元素返回-2;
** 4. 若未找到该值, 返回0;
** 5. 否则返回该值的位序
*/
int LocateElem(LinkList const *list, ElemType const *elem)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem) {
        printf("错误: 待查找元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!list->start) {
        return -1;          // 链表未初始化
    }
    if (list->length == 0) {
        return -2;          // 链表无元素
    }
    PNode pc = list->start->next;
    int count = 1;
    while (pc) {
        if (CompareElems(elem, &(pc->data))) {
            return count;
        }
        pc = pc->next;
        ++count;
    }
    return 0;
}

/*
** 操作: 将链表中某个位序的元素返回给元素指针
** 参数: 一个链表指针, 待查找的位序, 待返回的元素指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 若链表为空返回-2;
** 4. 若位序不合理返回1;
** 5. 否则执行操作返回0
*/
int ListSearch(LinkList const *list, int i, ElemType *elem)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!elem) {
        printf("错误: 返回元素指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!list->start) {
        return -1;              // 链表未初始化
    }
    if (list->length == 0) {
        return -2;              // 链表为空
    }
    if (i <= 0 || i > list->length) {
        return 1;               // 位序不合理
    }
    PNode p = list->start->next;
    int count = 1;
    while (count != i) {
        p = p->next;
        ++count;
    }
    ChangeElem(elem, &(p->data));
    return 0;
}

/*
** 操作: 销毁链表, 包括头结点
** 参数: 一个链表指针
** 返回值:
** 1. 若参数指针错误则打印错误信息并退出;
** 2. 若链表未初始化返回-1;
** 3. 否则执行操作返回0
*/
int DestroyList(LinkList *list)
{
    if (!list) {
        printf("错误: 链表指针错误!\n");
        exit(EXIT_FAILURE);
    }
    if (!list->start) {
        return -1;              // 链表未初始化
    }
    PNode p = list->start;
    PNode pc;
    while (p) {
        pc = p;
        p = p->next;
        free(pc);
    }
    list->start = NULL;
    list->length = 0;
    return 0;
}