/* 单链表接口头文件List_SingleLink.h */
#ifndef __List_SingleLink_h__
#define __List_SingleLink_h__

#include <stdbool.h>

/* 数据类型定义 */
typedef int ElemType;           /*数据项包括一个int类型值*/
typedef struct node
{
    ElemType data;
    struct node * next;
}Node;                          /*一个节点包括一个数据元素和一个指向下一个元素的指针*/
typedef Node * LinkList;        /*若有LinkList *List;则*List为头节点,List为头指针,指向头节点即该链表*/

/* 接口函数声明 */

//操作:初始化链表
//前提条件:plist指向一个指针,该指针指向链表头节点
//后置条件:将头节点的指针置为NULL
void InitList(LinkList * plist);

//操作:删除该链表
//前提条件:plist是一个指向链表的指针
//后置条件:依次释放所有分配内存,并将头节点置为NULL.成功返回true,否则返回错误信息
bool ClearList(LinkList * plist);

//操作:判断链表是否为空
//前提条件:plist指向一个已初始化的链表
//后置条件:若为空返回true,否则返回false
bool ListIsEmpty(LinkList * plist);

//操作:判断链表是否已满
//前提条件:plist指向一个已初始化的链表
//后置条件:若已满返回true,否则返回false
bool ListIsFull(LinkList * plist);

//操作:在链表中插入元素
//前提条件:plist指向一个已初始化的链表,i是将插入的位置,elem是一个数据元素类型值
//后置条件:新建节点,将数据拷贝至节点,并将上一节点指针指向该节点,该节点指针指向下一元素,若为链表尾部,则置为NULL
bool ElemInsert(LinkList * plist,int i,ElemType elem);

//操作:删除链表中某位置元素
//前提条件:plist指向一个已初始化的链表,i是将删除的位置
//后置条件:将上一节点指针指向下一节点,释放该节点内存
bool ElemDelete(LinkList * plist,int i);

//操作:修改链表中某位置的元素
//前提条件:plist指向一个已初始化的链表,i是将修改的位置,elem是用于替换的值
//后置条件:将elem拷贝至该节点
bool ElemChange(LinkList * plist,int i,ElemType elem);

//操作:查找链表中某位置的元素
//前提条件:plist指向一个已初始化的链表,i是将查找的位置
//后置条件:返回该值
ElemType ElemFine(LinkList * plist,int i);

//操作:遍历链表中每个值
//前提条件:plist指向一个已初始化的链表
//后置条件:打印每个值
void ShowElem(LinkList * plist);

#endif