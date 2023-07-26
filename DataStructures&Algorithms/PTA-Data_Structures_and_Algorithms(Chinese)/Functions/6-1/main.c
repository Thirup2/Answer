#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */ /* 无头结点 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main()
{
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Reverse(List L)
{
    List list = NULL;
    PtrToNode node = L;
    PtrToNode next;
    while (node) {
        next = node->Next;
        node->Next = list;
        list = node;
        node = next;
    }
    return list;
}

/* 出题方实现函数 */
List Read()
{
    List list = NULL;
    PtrToNode *ptrnow = &list;
    PtrToNode now;
    size_t size;
    scanf("%lu", &size);
    ElementType elem;
    for (size_t i = 0; i < size; i++) {
        scanf("%d", &elem);
        now = (PtrToNode) malloc(sizeof(struct Node));
        now->Data = elem;
        now->Next = *ptrnow;
        *ptrnow = now;
        ptrnow = &(now->Next);
    }
    return list;
}

void Print(List L)
{
    PtrToNode node = L;
    while (node) {
        printf("%d ", node->Data);
        node = node->Next;
    }
    printf("\n");
}