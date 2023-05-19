#define EXPORT

#include "SingleLinkList.h"
#include <stdlib.h>

// 局部函数声明
static SingleLList AllocateList(void);
static PtrNode AllocateNode(cPtrElem elem);

// 接口函数定义
SINGLELLIST_API SingleLList InitList(void)
{
    SingleLList list = AllocateList();
    return list;
}
SINGLELLIST_API int Length(SingleLList list)
{
    int cnt = 0;
    Iterator beg = Begin(list), end = End(list);
    while (beg != end) {
        beg = Next(beg);
        cnt++;
    }
    return cnt;
}
SINGLELLIST_API int LocateElem(SingleLList list, cPtrElem elem)
{
    int cnt = 1;
    Iterator beg = Begin(list);
    Iterator end = End(list);
    while (!EqualElems(StarIter(beg), elem) && beg != end) {
        cnt++;
        beg = Next(beg);
    }
    if (beg == end) {
        return 0;
    }
    return cnt;
}
SINGLELLIST_API PtrElem GetElem(SingleLList list, int i)
{
    if (Empty(list) || (i < 1 || i > Length(list))) {
        return NULL;
    }
    PtrNode now = list.head->next;
    while (i > 1) {
        i--;
        now = now->next;
    }
    return &(now->data);
}
SINGLELLIST_API Status ListInsert(SingleLList list, int i, cPtrElem elem)
{
    if (i < 1 || i > Length(list) + 1) {
        return WRONGPOS;
    }
    PtrNode pre = list.head;
    while (i > 1) {
        i--;
        pre = pre->next;
    }
    PtrNode now = AllocateNode(elem);
    now->next = pre->next;
    pre->next = now;
    return SUCCESS;
}
SINGLELLIST_API Status ListDelete(SingleLList list, int i, PtrElem elem)
{
    if (Empty(list)) {
        return ISEMPTY;
    }
    if (i < 1 || i > Length(list)) {
        return WRONGPOS;
    }
    PtrNode pre = list.head;
    while (i > 1) {
        i--;
        pre = pre->next;
    }
    PtrNode now = pre->next;
    CopyElems(elem, &(now->data));
    pre->next = now->next;
    free(now);
    return SUCCESS;
}
SINGLELLIST_API bool Empty(SingleLList list)
{
    return Length(list) == 0;
}
SINGLELLIST_API void DestroyList(SingleLList list)
{
    PtrNode del;
    Iterator beg = Begin(list), end = End(list);
    while (beg != end) {
        del = beg;
        beg = Next(beg);
        free(del);
    }
}
SINGLELLIST_API PtrElem StarIter(Iterator iter)
{
    return &(iter->data);
}
SINGLELLIST_API cPtrElem StarConstIter(constIterator iter)
{
    return StarIter((Iterator) iter);
}
SINGLELLIST_API Iterator Begin(SingleLList list)
{
    return list.head->next;
}
SINGLELLIST_API Iterator End(SingleLList list)
{
    return NULL;
}
SINGLELLIST_API Iterator Next(Iterator pre)
{
    return pre->next;
}
SINGLELLIST_API constIterator cBegin(SingleLList list)
{
    return Begin(list);
}
SINGLELLIST_API constIterator cEnd(SingleLList list)
{
    return End(list);
}
SINGLELLIST_API constIterator cNext(constIterator pre)
{
    return Next((Iterator) pre);
}

// 局部函数定义
static SingleLList AllocateList(void)
{
    SingleLList list;
    list.head = AllocateNode(NULL);
    return list;
    // 这里需要格外注意3点：
    // 1. 我们需要什么：我们实际上需要的是表里的指针所指向的实体，而不是这个指针实体
    // 2. 我们传递的是什么：实际上我们可以传递一个动态分配表内存的指针，但这里我们传递的只是表内指针的值
    // 3. 我们这样传递有效吗：我们将这个表里指针的值拷贝给另一个表实体中的指针，它仍然可以根据这个指针访问到我们的链表，所以是有效的
}
static PtrNode AllocateNode(cPtrElem elem)
{
    PtrNode node = (PtrNode) malloc(sizeof(Node));
    if (!node) {
        exit(EXIT_FAILURE);
    }
    if (elem) {
        CopyElems(&(node->data), elem);
    }
    node->next = NULL;
    return node;
}