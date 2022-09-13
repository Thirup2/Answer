#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
struct node
{
    ElemType data;
    struct node *next;
};
typedef struct node Node;
typedef Node *PNode;
struct list
{
    Node *head;
    Node *last;
};
typedef struct list List;
void InitList(List *plist);
void AddNode(List *plist, ElemType const *data);
void DestroyList(List *plist);
int MaxSum(List *plist);
int main(void)
{
    List list;
    InitList(&list);
    int K;
    scanf("%d", &K);
    ElemType n;
    if (K == 1) {
        scanf("%d", &n);
        printf("%d", n);
        return 0;
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &n);
        AddNode(&list, &n);
    }
    int sum;
    sum = MaxSum(&list);
    DestroyList(&list);
    printf("%d", sum);
    return 0;
}
void InitList(List *plist)
{
    plist->head = NULL;
    plist->last = NULL;
}
void AddNode(List *plist, ElemType const *data)
{
    PNode p = (PNode) malloc(sizeof(Node));
    if (!p) {
        exit(EXIT_FAILURE);
    }
    p->data = *data;
    PNode s = plist->last;
    if (s) {
        p->next = s->next;
        s->next = p;
        plist->last = p;
    } else {
        p->next = NULL;
        plist->head = p;
        plist->last = p;
    }
}
void DestroyList(List *plist)
{
    PNode p = plist->head;
    PNode s;
    while (p) {
        s = p;
        p = p->next;
        free(s);
    }
}
int MaxSum(List *plist)
{
    int maxsum = 0;
    int thissum = 0;
    PNode p = plist->head;
    while (p) {
        thissum += p->data;
        if (thissum > maxsum) {
            maxsum = thissum;
        }
        if (thissum < 0) {
            thissum = 0;
        }
        p = p->next;
    }
    return maxsum;
}