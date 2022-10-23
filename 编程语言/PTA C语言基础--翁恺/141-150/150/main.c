#include<stdio.h>
int main()
{
    int i, j = 1, x = 0, y = 0, rest, N;
    char C;
    scanf("%d %c", &N, &C);
    while (2 * j * j - 1 <= N)//计算层数
    {
        j++;
    }
    j--;
    y = 2 * j - 1;
    rest = N - 2 * j * j + 1;//剩下字符的数量
    while (y > 0)//输出沙漏上半部分
    {
        for (i = 0; i < x; i++)
            printf(" ");
        for (i = 0; i < y; i++)
            printf("%c", C);
        printf("\n");
        x++;
        y -= 2;
    }
    x--;
    y += 2;
    while (x > 0)//输出沙漏下半部分
    {
        x--;
        y += 2;
        for (i = 0; i < x; i++)
            printf(" ");
        for (i = 0; i < y; i++)
            printf("%c", C);
        printf("\n");
    }
    printf("%d", rest);
    return 0;
}