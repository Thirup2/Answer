#include <stdio.h>
#define SPG 3.785       //一加仑升数
#define KPY 1.609       //一英里千米数
int main(void)
{
    //定义值
    double yl,gl,sh,km;
    double ypg,spbk;

    //获取值
    printf("请输入旅行的里程数(英里):");
    scanf("%lf",&yl);
    printf("请输入旅行消耗的汽油量(加仑):");
    scanf("%lf",&gl);

    //计算并打印
    //1.计算并显示消耗每加仑汽油行驶的英里数
    ypg = yl / gl;
    printf("你的汽车每消耗一加仑汽油能行驶%g英里\n",ypg);
    //2.将英里/加仑转换成升/100公里,显示小数点后1位数字
    spbk = (gl*SPG)/(yl*KPY/100);
    printf("%.1lf英里/加仑 = %.1lf升/100公里\n",ypg,spbk);

    //函数返回值
    return 0;
}