#include <stdio.h>
int main(void)
{
    double a=0;
    double ai;
    double x;
    printf("请输入想要求取平方根的数:\n");
    scanf("%lf",&x);
    ai=1;
    while(ai!=a){
        a=ai;
        ai=(a+x/a)/2;
        printf("近似值为%g\n",ai);
    }
    printf("平方根是:%g",ai);
    return 0;
}