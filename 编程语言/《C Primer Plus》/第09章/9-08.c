#include <stdio.h>
double power(double,int);
int main(void)
{
    double n;
    int p;
    printf("请输入你想要求幂的数以及指数:");
    while(scanf("%lf %d",&n,&p)==2){
        if(n==0&&p==0){
            printf("0的0次幂未定义,因此把该值处理为1\n");
        }else{
            printf("%g的%d次幂的结果是:%g\n",n,p,power(n,p));
        }
    }
    
    return 0;
}
double power(double n,int p)
{
    double some=1;
    if(n==0){
        return 0;
    }else if(p==0){
        return 1;
    }else{
        if(p>0){
            for(int i=0;i<p;i++){
                some*=n;
            }
            return some;
        }else{
            for(int i=0;i<(-p);i++){
                some*=n;
            }
            return 1.0/some;
        }
    }
}