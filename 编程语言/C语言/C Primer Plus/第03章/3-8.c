#include <stdio.h>
#define BPP 2       //一品脱杯数
#define APB 8       //一杯盎司数
#define DPA 2       //一盎司大汤勺数
#define CPD 3       //一大汤勺茶勺数
int main(void)
{
    //定义值
    double B;
    double P,A,D,C;

    //获取值
    printf("请输入杯数:");
    scanf("%lf",&B);

    //计算值
    P = B / BPP;
    A = B * APB;
    D = A * DPA;
    C = D * CPD;

    //打印
    printf("%g杯 = %g品脱 = %g盎司 = %g大汤勺 = %g茶勺\n",B,P,A,D,C);


    //函数返回值
    return 0;
}