#include <stdio.h>
void Temperatures(double);
int main(void)
{
    //定义值
    double tem;

    //获取值
    printf("请输入一个华氏温度:");
    while(scanf("%lf",&tem)==1){
        Temperatures(tem);
        printf("请输入下一个华氏温度:");
    }

    //函数返回值
    return 0;
}
void Temperatures(double n)
{
    const double FIVE = 5.0;
    const double NINE = 9.0;
    const double THTW = 32.0;
    const double KK = 273.16;
    double C,K;
    C = FIVE/NINE*(n-THTW);
    K = C + KK;
    printf("%g 华氏度 = %g 摄氏度 = %g 开氏度\n",n,C,K);
}