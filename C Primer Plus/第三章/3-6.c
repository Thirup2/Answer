#include <stdio.h>
#define KPF 3.0e-23     //一分子水的质量(克)
#define KPK 950         //一夸脱水的质量(克)
int main(void)
{
    //定义值
    double kwto;        //水的夸脱数
    double uvffzi;      //水分子数量

    //获取值
    printf("请输入水的夸脱数:");
    scanf("%lf",&kwto);

    //计算
    uvffzi = kwto * KPK / KPF;

    //打印
    printf("%g夸脱水大约有%g个水分子\n",kwto,uvffzi);

    //函数返回值
    return 0;
}