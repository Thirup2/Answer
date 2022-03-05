#include <stdio.h>
void larger_of(double*,double*);
int main(void)
{
    double m,n;
    printf("请输入两个数:");
    scanf("%lf %lf",&m,&n);
    larger_of(&m,&n);
    printf("m = %g\nn = %g\n",m,n);

    return 0;
}
void larger_of(double *m,double *n)
{
    if(*m>*n){
        *n=*m;
    }else{
        *m=*n;
    }
}