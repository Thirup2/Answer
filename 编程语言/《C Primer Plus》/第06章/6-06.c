#include <stdio.h>
int main(void)
{
    int min, max;
    printf("请输入两个整数作为上下限: ");
    scanf("%d %d", &min, &max);
    if (min > max) {
        int temp;
        temp = max;
        max = min;
        min = temp;
    }
    printf("----------------------------------\n");
    printf("|%-10s|%-10s|%-10s|\n", "Integer", "Sqaure", "Cubic");
    printf("----------------------------------\n");
    while (min <= max) {
        printf("|%-10d|%-10d|%-10d|\n", min, min * min, min * min * min);
        printf("----------------------------------\n");
        min++;
    }
    return 0;
}