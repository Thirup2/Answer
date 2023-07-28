#include "StaticSeqList.h"
#include <stdio.h>

// 局部函数声明
// 无

// 接口函数定义
void InitList(PtrSSList list)
{
    list->length = 0;
}
int Length(cPtrSSList list)
{
    return list->length;
}
int LocateElem(cPtrSSList list, cPtrElem elem)
{
    // 数组第一个位置作哨兵
    CopyElems(&(list->data[0]), elem);
    int i;
    for (i = list->length; !EqualElems(elem, &(list->data[i])); i--);
    return i;
}
Status GetElem(cPtrSSList list, int pos, PtrElem elem)
{
    if (Empty(list)) {
        printf("表为空！\n");
        return ISEMPTY;
    }
    if (pos < 1 || pos > Length(list)) {
        printf("查找位置不存在元素！\n");
        return WRONGPOS;
    }
    CopyElems(elem, &(list->data[pos]));
    return SUCCESS;
}
Status ListInsert(PtrSSList list, int pos, cPtrElem elem)
{
    if (Length(list) == MAXSIZE - 1) {
        printf("表已满！\n");
        return ISFULL;
    }
    if (pos < 1 || pos > Length(list) + 1) {
        printf("插入位置不合理！\n");
        return WRONGPOS;
    }
    for (int i = Length(list) + 1; i > pos; i--) {
        CopyElems(&(list->data[i]), &(list->data[i - 1]));
    }
    CopyElems(&(list->data[pos]), elem);
    list->length++;
    return SUCCESS;
}
Status ListDelete(PtrSSList list, int pos, PtrElem elem)
{
    if (Empty(list)) {
        printf("表为空！\n");
        return ISEMPTY;
    }
    if (pos < 1 || pos > Length(list)) {
        printf("删除位置不合理！\n");
        return WRONGPOS;
    }
    CopyElems(elem, &(list->data[pos]));
    for (int i = pos; i < Length(list); i++) {
        CopyElems(&(list->data[i]), &(list->data[i + 1]));
    }
    list->length--;
    return SUCCESS;
}
void PrintList(cPtrSSList list)
{
    printf("List: ");
    for (int i = 1; i <= Length(list); i++) {
        printf(" ");    
        PrintElem(&(list->data[i]));
    }
    printf("\n");
}
bool Empty(cPtrSSList list)
{
    return Length(list) == 0;
}
void DestroyList(PtrSSList list)
{
    InitList(list);
}

// 局部函数定义
// 无