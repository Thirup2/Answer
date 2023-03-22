#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8

typedef int ElementType;

typedef enum
{
    push, pop, end
} Operation;

typedef enum
{
    false, true
} bool;

typedef int Position;

struct SNode
{
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */
static bool MyStrCmp(const char *str1, const char *str2);

int main()
{
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

// 经测试，出题方默认 Top1 为 -1 时栈 1 为空，Top2 为 MaxSize 时栈 2 为空
Stack CreateStack(int MaxSize)
{
    Stack S = (Stack) malloc(sizeof(struct SNode));
    if (!S) {
        exit(EXIT_FAILURE);
    }
    S->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
    if (!S->Data) {
        exit(EXIT_FAILURE);
    }
    S->MaxSize = MaxSize;
    S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}
bool Push(Stack S, ElementType X, int Tag)
{
    if (S->Top1 + 1 == S->Top2) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1) {
        S->Data[++S->Top1] = X;
    } else if (Tag == 2) {
        S->Data[--S->Top2] = X;
    } else {
        return false;
    }
    return true;
}
ElementType Pop(Stack S, int Tag)
{
    if (Tag == 1) {
        if (S->Top1 == -1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top1--];
    } else if (Tag == 2) {
        if (S->Top2 == S->MaxSize) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[S->Top2++];
    } else {
        return ERROR;
    }
}

/* 出题方实现代码 */
Operation GetOp()
{
    char operator[5];
    scanf("%s", operator);
    if (MyStrCmp(operator,"Push")) {
        return push;
    } else if (MyStrCmp(operator,"Pop")) {
        return pop;
    } else {
        return end;
    }
}
void PrintStack(Stack S, int Tag)
{
    printf("Pop from Stack %d: ", Tag);
    ElementType elem;
    while ((elem = Pop(S, Tag)) != ERROR) {
        printf("%d ", elem);
        if (Tag == 1) {
            if (S->Top1 == -1) {
                break;
            }
        } else if (Tag == 2) {
            if (S->Top2 == S->MaxSize) {
                break;
            }
        } else {
            break;
        }
    }
    printf("\n");
}
static bool MyStrCmp(const char *str1, const char *str2)
{
    while (*str1 && *str2) {
        if (*str1 == *str2) {
            str1++;
            str2++;
        } else {
            return false;
        }
    }
    if (*str1 != '\0' || *str2 != '\0') {
        return false;
    }
    return true;
}