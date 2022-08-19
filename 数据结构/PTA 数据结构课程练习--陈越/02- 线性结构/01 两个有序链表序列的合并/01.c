#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Merge(List L1, List L2)
{
    List pa, pb, pc, L;
    pa = L1->Next;  // L1和L2都有头结点
    pb = L2->Next;
    L = (List) malloc(sizeof(struct Node)); // 题目要求带头结点
    pc = L;
    while (pa && pb) {      // 当pa和pb都不指向空指针时
        if (pa->Data <= pb->Data) {
            pc->Next = pa;      // 将小的结点交给pc所指结点的next指针
            pc = pc->Next;      // pc走向该next指针
            pa = pa->Next;      // pa指向该链表上下一个结点
        } else {
            pc->Next = pb;
            pc = pc->Next;
            pb = pb->Next;
        }
    }
    pc->Next = pa ? pa : pb;    // 若pa为空则将pc所指结点的next指针指向pb, 若pb为空则反之
    L1->Next = NULL;    // 题目要求最后L1和L2输出NULL
    L2->Next = NULL;
    return L;
}