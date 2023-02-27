#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position) malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    for (P = L; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X)
{
    Position i = L;
    while (i) {
        if (i->Data == X) {
            return i;
        }
        i = i->Next;
    }
    return ERROR;
}
List Insert(List L, ElementType X, Position P)
{
    List newL;
    PtrToLNode node;
    if (P == L) {
        node = (PtrToLNode) malloc(sizeof(struct LNode));
        node->Next = L;
        node->Data = X;
        newL = node;
    } else {
        newL = L;
        Position i = L;
        while (i && i->Next != P) {
            i = i->Next;
        }
        if (!i) {
            printf("Wrong Position for Insertion\n");
            return ERROR;
        }
        node = (PtrToLNode) malloc(sizeof(struct LNode));
        node->Next = i->Next;
        i->Next = node;
        node->Data = X;
    }
    return newL;
}
List Delete(List L, Position P)
{
    List newL;
    if (P == L) {
        newL = L->Next;
        free(L);
    } else {
        newL = L;
        Position i = newL;
        while (i && i->Next != P) {
            i = i->Next;
        }
        if (!i) {
            printf("Wrong Position for Deletion\n");
            return ERROR;
        }
        PtrToLNode node = i->Next;
        i->Next = node->Next;
        free(node);
    }
    return newL;
}