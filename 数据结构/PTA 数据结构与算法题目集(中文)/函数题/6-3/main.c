#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

int Length(List L);

int main()
{
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
int Length(List L)
{
    int cnt = 0;
    PtrToLNode node = L;
    while (node) {
        cnt++;
        node = node->Next;
    }
    return cnt;
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