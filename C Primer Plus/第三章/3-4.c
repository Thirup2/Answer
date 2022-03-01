#include <stdio.h>
int main(void)
{
    //定义值
    double some;

    //获取值
    printf("Enter a floating-point value: ");
    scanf("%lf",&some);

    //第一种输出格式
    printf("fixed-point notation: %lf\n",some);
    //第二种输出格式
    printf("exponential notation: %le\n",some);
    //第三种输出格式
    printf("p notation: %.2la\n",some);

    //函数返回值
    return 0;
}