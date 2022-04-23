#include <stdio.h>
#define SPG 3.785       //一加仑升数
#define KPY 1.609       //一英里千米数
int main(void)
{
    float yl,gl,sh,km;
    float ypg,spbk;
    printf("请输入旅程的里程数(英里)和消耗的汽油量(加仑):\n");
    while(scanf("%f %f",&yl,&gl)==2){
        printf("你的汽车每消耗一加仑汽油能行驶%g英里\n",yl / gl);
        printf("%.1lf英里/加仑 = %.1lf升/100公里\n",yl / gl,(gl*SPG)/(yl*KPY/100));
        printf("请输入旅程的里程数(英里)和消耗的汽油量(加仑):\n");
    }

    return 0;
}