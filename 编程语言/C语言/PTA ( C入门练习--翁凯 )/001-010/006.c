#include <stdio.h>
#define CM_M 100        //一米100厘米
#define M_FOOT 0.3048   //一英尺米数
#define F_I 12          //一英尺英寸数
int main(void)
{
    int cm;
    double foot;
    int feet;
    int inch;
    
    scanf("%d",&cm);
    
    foot = (double)cm/CM_M/M_FOOT;
    inch = foot * F_I;
    feet = inch / F_I;
    inch = inch % F_I;
    printf("%d %d",feet,inch);
    
    return 0;
}