#include <stdio.h>
#define SPY 3.156e7
int main(void)
{
    printf("请输入您的年龄: ");
    int age;
    scanf("%d", &age);
    printf("年龄: %d\n", age);
    printf("秒数: %g\n", age * SPY);

    return 0;
}