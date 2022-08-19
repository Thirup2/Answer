#include <stdio.h>
#define DA 0.1
#define DE 0.05
#define OR 100
int main(void)
{
    double sum1,sum2;
    int year;
    for(year=0,sum1=OR,sum2=OR;sum2<=sum1;year++){
        sum1+=OR*DA;
        sum2=sum2*(1+DE);
    }
    printf("一共需要%d年,Deirdre的投资额才会超过Daphne,\n此时Daphne:%-20lfDeirdre:%-20lf\n",year,sum1,sum2);

    return 0;
}