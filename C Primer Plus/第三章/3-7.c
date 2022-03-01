#include <stdio.h>
#define CPF 2.54        //一英寸厘米数
int main(void)
{
    //定义值
    double height;
    double c_height;

    //获取值
    printf("请输入您的身高(英寸):");
    scanf("%lf",&height);

    //计算
    c_height = height * CPF;

    //打印
    printf("您的身高 = %g厘米\n",c_height);

    //函数返回值
    return 0;
}