/* 静态顺序线性表接口头文件List_StaticSeq.h */
#ifndef __List_StaticSeq_h__
#define __List_StaticSeq_h__

#include <stdbool.h>

/* 数据类型定义 */
#define LSIZE 20
typedef int ElemType;               /*数据项包括一个int*/
typedef struct
{
    ElemType data[LSIZE];
    int length;
}SqList;                              /*一个线性表包括主要元素数组和该线性表的实时长度*/

/* 操作集 */

//操作:初始化线性表
//前提条件:plist是一个指向线性表的指针
//后置条件:所有数据重置为0(根据实际情况考虑),长度置为0
void InitList(SqList * plist);

//操作:删除该线性表
//前提条件:plist是一个指向线性表的指针
//后置条件:所有数据重置为0(根据实际情况考虑),长度置为0
void ClearList(SqList * plist);

//操作:判断线性表是否为空
//前提条件:list是一个已初始化的线性表
//后置条件:若为空返回true,否则返回false
bool ListIsEmpty(SqList list);

//操作:判断线性表是否已满
//前提条件:list是一个已初始化的线性表
//后置条件:若已满返回true,否则返回false
bool ListIsFull(SqList list);

//操作:在线性表中插入元素(行尾及行尾以前)
//前提条件:plist是一个指向线性表的指针,i是插入位置,elem是将插入元素
//后置条件:若位置超过行尾,抛出错误;若线性表已满,抛出错误;若在行尾,插入,length+1,返回true;若在行内,插入,后续元素后移,length+1,返回true
bool ElemInsert(SqList * plist,int i,ElemType elem);

//操作:删除线性表中某位置元素
//前提条件:plist是一个指向线性表的指针,i是待删除元素位置
//后置条件:若i处无元素,抛出错误;核验i的范围(i>0&&i<=LSIZE);删除成功,后续元素前移,length-1,返回true;
bool LElemDelete(SqList * plist,int i);

//操作:删除线性表中某值元素
//前提条件:plist是一个指向线性表的指针,elem是待删除的元素
//后置条件:若不存在该值,返回0;若存在该值,列出所有位置,提供删除选项,根据选择进行删除,相应后续元素前移,length减相应个数,返回成功删除个数
int ElemDelete(SqList * plist,ElemType elem);

//操作:修改线性表中某位置元素
//前提条件:plist是一个指向线性表的指针,i是待删除元素位置,data为覆盖数据
//后置条件:校验i的范围;若i处无元素,抛出错误;修改成功后返回true
bool LElemChange(SqList * plist,int i,ElemType data);

//操作:修改线性表中某值元素
//前提条件:plist是一个指向线性表的指针,data_pre是待查找元素,data_now是待覆盖数据
//后置条件:若不存在该值,返回0;若存在,列出所有位置,提供修改选项,根据选择进行修改,返回成功修改个数
int ElemChange(SqList * plist,ElemType data_pre,ElemType data_now);

//操作:查找线性表中某位置元素
//前提条件:list是一个线性表,i是待查找位置
//后置条件:校验i的范围;若i处无元素,返回0;查找成功后返回该位置元素
ElemType LElemFind(SqList list,int i);

//操作:查找线性表中某值元素
//前提条件:list是一个线性表,elem是待查找元素
//后置条件:若不存在该值,返回0;若存在,列出所有位置,返回查找到的个数
int ElemFind(SqList list,ElemType elem);

//操作:遍历线性表中每元素
//前提条件:list是一个线性表
//后置条件:打印每个值
void ShowElem(SqList list);

#endif