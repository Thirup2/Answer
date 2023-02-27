#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth(List L, int K);

int main()
{
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType FindKth(List L, int K)
{
    PtrToLNode node = L;
    while (node && K > 0) {
        K--;
        if (K == 0) {
            return node->Data;
        }
        node = node->Next;
    }
    return ERROR;
}

/* 出题方实现函数 */
List Read()
{
    List list = NULL;
    List *ptrlist = &list;
    PtrToLNode node;
    ElementType elem;
    while (scanf("%d", &elem) == 1) {
        if (elem < 0) {
            break;
        } else {
            node = (PtrToLNode) malloc(sizeof(struct LNode));
            if (!node) {
                exit(EXIT_FAILURE);
            }
            node->Data = elem;
            node->Next = *ptrlist;
            *ptrlist = node;
            ptrlist = &(node->Next);
        }
    }
    return list;
}