#include "Problem.h"

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2)
{
    List L = (List) malloc(sizeof(struct Node));
    L->Next = NULL;
    List p = L;
    List m = L1->Next;
    List n = L2->Next;
    while (m && n) {
        if (m->Data <= n->Data) {
            p->Next = m;
            m = m->Next;
            p = p->Next;
        } else {
            p->Next = n;
            n = n->Next;
            p = p->Next;
        }
    }
    if (!m) {
        p->Next = n;
    } else {
        p->Next = m;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return L;
}