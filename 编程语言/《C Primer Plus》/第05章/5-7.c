#include <stdio.h>
void lifh(double);
int main(void)
{
    //定义值
    double some;

    //获取值
    printf("请输入你想要求立方的值:");
    while(scanf("%lf",&some)==1){
        lifh(some);
        printf("请输入下一个想要求立方的值:");
    }

    //函数返回值
    return 0;
}
void lifh(double n)
{
    printf("%lf\n",n*n*n);
}