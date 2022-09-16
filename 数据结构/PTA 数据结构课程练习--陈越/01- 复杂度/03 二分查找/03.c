#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch(List L, ElementType X)
{
    Position j = MAXSIZE - 1;
    int cnt = 0;
    while (L->Data[j] == 0) {
        cnt++;
        j--;
    }
    Position front = 0;
    Position rear = MAXSIZE - cnt + 1;
    Position i = (rear - front) / 2;
    while (L->Data[i] != X) {
        if (L->Data[i] > X) {
            rear = i;
            i = front + (rear - front) / 2;
            if ((rear - front) / 2 == 0) {
                return NotFound;
            }
        } else if (L->Data[i] < X) {
            front = i;
            i = front + (rear - front) / 2;
            if ((rear - front) / 2 == 0) {
                return NotFound;
            }
        }
    }
    return i;
}