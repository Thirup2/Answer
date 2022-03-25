#include <stdio.h>
int main(void)
{
    double sum1,sum2,sum;
    int t;
    double s;

    scanf("%lf %d",&s,&t);
    if(s>0&&s<=3){
        sum1=10;
    }else if(s<=10){
        sum1=10+2*(s-3);
    }else{
        sum1=10+2*(10-3)+3*(s-10);
    }
    sum2 = 0;
    if(t>=5){
        t=t/5;
        sum2=t*2;
    }
        sum=sum1+sum2;
        printf("%.0lf",sum);

    return 0;
}