#include <stdio.h>
double average(double,double);
int main(void)
{
    double m,n;
    printf("请输入你想要求调和平均数的两个数:");
    scanf("%lf %lf",&m,&n);
    printf("%g 和 %g 的调和平均数是:%g\n",m,n,average(m,n));

    return 0;
}
double average(double m,double n)
{
    double average;
    average=1.0/(((1.0/m)+(1.0/n))/2.0);
    return average;
}