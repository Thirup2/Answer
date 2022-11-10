#include <stdio.h>
int WhatKindOfTryangle(int a, int b, int c);
int main(void)
{
    int a, b, c;
    printf("请输入三角形的三边长： ");
    scanf("%d %d %d", &a, &b, &c);
    int r = WhatKindOfTryangle(a, b, c);
    if (r == 1) {
        printf("这是一个等边三角形！\n");
    } else if (r == 2) {
        printf("这是一个等腰三角形！\n");
    } else if (r == 3) {
        printf("这是一个不等边三角形！\n");
    } else if (r == 0) {
        printf("无法构成一个三角形！\n");
    }
    return 0;
}
int WhatKindOfTryangle(int a, int b, int c)
{
    if (a + b <= c || a + c <= b || c + b <= a) {
        return 0;
    }
    if (a == b && a == c) {
        return 1;
    } else if (a == b || a == c || b == c) {
        return 2;
    } else {
        return 3;
    }
}