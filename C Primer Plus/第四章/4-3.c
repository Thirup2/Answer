#include <stdio.h>
int main(void)
{
    //定义值
    double some;

    //获取值
    printf("请输入一个数:");
    scanf("%lf",&some);

    //打印值
    printf("a. The input is %.1lf or %.1le.\n",some,some);
    printf("b. The input is %+.3lf or %.3LE.\n",some,some);

    //函数返回值
    return 0;
}