#include <stdio.h>
double makeresult(double,double);
int main(void)
{
    double m,n;
    printf("请输入两个浮点数:");
    while(scanf("%lf %lf",&m,&n)==2){
        printf("( m - n ) / ( m * n ) = %lf\n",makeresult(m,n));
        printf("请输入两个浮点数");
    }

    return 0;
}
double makeresult(double m,double n)
{
    return ((m-n)/(m*n));
}