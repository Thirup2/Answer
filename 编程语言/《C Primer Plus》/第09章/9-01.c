#include <stdio.h>
double min(double,double);
int main(void)
{
    double m,n;
    printf("请输入两个数:");
    scanf("%lf %lf",&m,&n);
    printf("较小值是:%g\n",min(m,n));

    return 0;
}
double min(double m,double n)
{
    return m<n?m:n;
}