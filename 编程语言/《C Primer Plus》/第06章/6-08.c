#include <stdio.h>
int main(void)
{
    double m,n;
    printf("请输入两个数:");
    while(scanf("%lf %lf",&m,&n)==2){
        printf("( m - n ) / ( m * n ) = %lf\n",(m-n)/(m*n));
        printf("请输入两个数:");
    }

    return 0;
}