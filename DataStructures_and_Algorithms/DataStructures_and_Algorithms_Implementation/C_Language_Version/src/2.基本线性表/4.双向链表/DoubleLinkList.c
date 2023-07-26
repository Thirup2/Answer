#define EXPORT

#include "DoubleLinkList.h"
#include <stdlib.h>

// 局部函数声明
static DoubleLList AllocateList(void);
static PtrNode AllocateNode(cPtrElem elem);

// 接口函数定义
DOUBLELLIST_API DoubleLList InitList(void)
{
    DoubleLList list = AllocateList();
    return list;
}
DOUBLELLIST_API int Length(DoubleLList list)
{
    int cnt = 0;
    Iterator beg = Begin(list), end = End(list);
    while (beg != end) {
        beg = Next(beg);
        cnt++;
    }
    return cnt;
}
DOUBLELLIST_API int LocateElem(DoubleLList list, cPtrElem elem)
{
    int cnt = 1;
    Iterator beg = Begin(list), end = End(list);
    while (!EqualElems(StarIter(beg), elem) && beg != end) {
        cnt++;
        beg = Next(beg);
    }
    if (beg == end) {
        return 0;
    }
    return cnt;
}
DOUBLELLIST_API PtrElem GetElem(DoubleLList list, int i)
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
DOUBLELLIST_API Status ListInsert(DoubleLList list, int i, cPtrElem elem)
{
    if (i < 1 || i > Length(list) + 1) {
        return WRONGPOS;
    }
    PtrNode pre = list.head;
    while (i > 1) {
        pre = pre->next;
        i--;
    }
    PtrNode now = AllocateNode(elem);
    now->next = pre->next;
    now->pre = pre;
    pre->next = now;
    now->next->pre = now;
    return SUCCESS;
}
DOUBLELLIST_API Status ListDelete(DoubleLList list, int i, PtrElem elem)
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
    PtrNode next = now->next;
    pre->next = next;
    next->pre = pre;
    free(now);
    return SUCCESS;
}
DOUBLELLIST_API bool Empty(DoubleLList list)
{
    return Length(list) == 0;
}
DOUBLELLIST_API void DestroyList(DoubleLList list)
{
    PtrNode first = list.head;
    PtrNode del;
    while (first) {
        del = first;
        first = first->next;
        free(del);
    }
}
DOUBLELLIST_API PtrElem StarIter(Iterator iter)
{
    return &(iter->data);
}
DOUBLELLIST_API cPtrElem StarConstIter(constIterator iter)
{
    return StarIter((Iterator) iter);
}
DOUBLELLIST_API Iterator Begin(DoubleLList list)
{
    return list.head->next;
}
DOUBLELLIST_API Iterator End(DoubleLList list)
{
    return list.last;
}
DOUBLELLIST_API Iterator Next(Iterator pre)
{
    return pre->next;
}
DOUBLELLIST_API constIterator cBegin(DoubleLList list)
{
    return Begin(list);
}
DOUBLELLIST_API constIterator cEnd(DoubleLList list)
{
    return End(list);
}
DOUBLELLIST_API constIterator cNext(constIterator pre)
{
    return Next((Iterator) pre);
}
DOUBLELLIST_API reverseIterator rBegin(DoubleLList list)
{
    return list.last->pre;
}
DOUBLELLIST_API reverseIterator rEnd(DoubleLList list)
{
    return list.head;
}
DOUBLELLIST_API reverseIterator rNext(reverseIterator pre)
{
    return pre->pre;
}
DOUBLELLIST_API constReverseIterator rcBegin(DoubleLList list)
{
    return rBegin(list);
}
DOUBLELLIST_API constReverseIterator rcEnd(DoubleLList list)
{
    return rEnd(list);
}
DOUBLELLIST_API constReverseIterator rcNext(constReverseIterator pre)
{
    return rNext((reverseIterator) pre);
}

// 局部函数定义
static DoubleLList AllocateList(void)
{
    DoubleLList list;
    list.head = AllocateNode(NULL);
    list.last = AllocateNode(NULL);
    // 既有头结点又有尾结点，这样插入或删除一个元素就不用对任何位置进行特殊化处理
    list.head->next = list.last;
    list.last->pre = list.head;
    list.head->pre = NULL;
    list.last->next = NULL;
    return list;
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
    node->pre = NULL;
    return node;
}