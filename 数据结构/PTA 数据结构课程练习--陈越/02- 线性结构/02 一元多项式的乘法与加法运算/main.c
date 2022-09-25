#include <stdio.h>
#include <stdlib.h>


struct items
{
    int first;                  // 系数
    int point;                  // 指数
};                              // 数据项
typedef struct items ElemType;  // 数据元素

struct node
{
    ElemType data;
    struct node *next;
};                              // 结点定义
typedef struct node Node;       // 结点类型
typedef Node *PNode;            // 结点指针

struct list
{
    PNode head;                 // 头指针
    PNode last;                 // 尾指针
    int length;                 // 元素个数
};                              // 一元多项式定义
typedef struct list List;       // 一元多项式类型

// 初始化表, 添加一个头结点
void InitList(List *list);
// 向表尾插入一个元素
void ReadList(List *list, ElemType *elem);
// 将list1和list2相乘, 保存到list
void MultyList(List *list1, List *list2, List *list);
// 将list1和list2相加, 保存到list
void AddList(List *list1, List *list2, List *list);
// 打印一个表的内容
void ShowList(List *list);
// 释放一个表的内存, 包括头结点
void DestroyList(List *list);
// 将list2的内容写到list1中, 请保证list1是一个刚初始化的表
void ExchangeList(List *list1, List *list2);


int main(void)
{
    // 创建两个一元多项式
    List list1, list2;      // 用于输入
    InitList(&list1);
    InitList(&list2);

    List list3, list4;      // 用于输出
    InitList(&list3);
    InitList(&list4);

    // 读入多项式
    int n;                  // 读取将要写入的个数
    ElemType elem;          // 保存要写入的元素

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &elem.first, &elem.point);
        if (elem.first == 0) {          // 当遇到系数为0的项时, 跳过此次写入
            continue;
        }
        ReadList(&list1, &elem);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &elem.first, &elem.point);
        if (elem.first == 0) {          // 同上
            continue;
        }
        ReadList(&list2, &elem);
    }

    // 输出
    MultyList(&list1, &list2, &list3);
    AddList(&list1, &list2, &list4);
    ShowList(&list3);
    ShowList(&list4);

    // 释放
    DestroyList(&list1);
    DestroyList(&list2);
    DestroyList(&list3);
    DestroyList(&list4);

    return 0;
}

void InitList(List *list)
{
    // 创建头结点
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        exit(EXIT_FAILURE);
    }
    p->next = NULL;

    // 更改表的各项参数
    list->head = p;
    list->last = p;
    list->length = 0;
}

void ReadList(List *list, ElemType *elem)
{
    // 创建新结点
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        exit(EXIT_FAILURE);
    }
    p->data.first = elem->first;
    p->data.point = elem->point;
    p->next = NULL;

    // 更新表的参数
    list->last->next = p;
    list->last = p;
    list->length++;
}

void MultyList(List *list1, List *list2, List *list)
{
    // 前期准备
    List thistime;      // 用于保存当前一次乘法所得的表
    List sum;           // 作为中介保存每一次所得的表与之前的总和的和
    InitList(&thistime);
    InitList(&sum);
    ElemType elem;

    // 主体循环, list1从第一个元素开始, 每一个与list2求乘积并将该乘积与之前的总和求和
    for (PNode One = list1->head->next; One; One = One->next) {
        for (PNode Two = list2->head->next; Two; Two = Two->next) {
            elem.first = One->data.first * Two->data.first;
            elem.point = One->data.point + Two->data.point;
            ReadList(&thistime, &elem);
        }
        AddList(&thistime, list, &sum);         // 保存当前所得的表与以前的总和表求和, 保存到中介sum中
        DestroyList(list);                      // 由于list内是有值状态, 故在将新总和放到list之前先重置list表
        InitList(list);
        DestroyList(&thistime);                 // 为下一次循环做准备
        InitList(&thistime);
        ExchangeList(list, &sum);               // 将新总和保存到list中
        DestroyList(&sum);                      // 为下一次求新总和做准备
        InitList(&sum);
    }
    DestroyList(&thistime);
    DestroyList(&sum);
}

void AddList(List *list1, List *list2, List *list)
{
    PNode p = list1->head->next;
    PNode s = list2->head->next;
    while (p && s) {        // 当遇到某个表走到末尾时跳出
        if (p->data.point > s->data.point) {        // p所指的项指数更大时, 将p指向的内容写入到新表中
            ReadList(list, &(p->data));
            p = p->next;
        } else if (p->data.point < s->data.point) {     // s所指的项指数更大时, 将s指向的内容写入到新表中
            ReadList(list, &(s->data));
            s = s->next;
        } else {                                    // 当两项指数相等时, 系数求和, 指数不变, 写入到新表中
            ElemType elem;
            elem.first = p->data.first + s->data.first;
            if (elem.first == 0) {                  // 若两项系数和为0时, 跳过此次写入
                p = p->next;
                s = s->next;
                continue;
            }
            elem.point = p->data.point;
            ReadList(list, &elem);
            p = p->next;
            s = s->next;
        }
    }
    if (!p) {                               // 将没走到末尾的表的后续结点内容写入到新表中
        while (s) {
            ReadList(list, &(s->data));
            s = s->next;
        }
    } else {
        while (p) {
            ReadList(list, &(p->data));
            p = p->next;
        }
    }
}

void ShowList(List *list)
{
    PNode p = list->head->next;
    if (!p) {                   // 若头结点指向NULL, 说明无元素, 输出0 0
        printf("0 0\n");
        return;
    }
    while (p->next) {           // 其余情况, 依次输出结点内容, 选用p->next做判断是为了留下最后一个结点不输出末尾的空格
        printf("%d %d ", p->data.first, p->data.point);
        p = p->next;
    }
    printf("%d %d\n", p->data.first, p->data.point);
}

void DestroyList(List *list)
{
    PNode p = list->head;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
}

void ExchangeList(List *list1, List *list2)
{
    PNode p = list2->head->next;
    while (p) {
        ReadList(list1, &(p->data));
        p = p->next;
    }
}