#include <stdio.h>
#define S_M_H 60
int main(void)
{
    int some;
    int hour,min,mins;

    scanf("%d %d",&some,&mins);
    hour=some/100;
    min=hour*S_M_H+(some%100);
    min=min+mins;
    hour=min/60;
    min=min%60;
    some=hour*100+min;

    printf("%03d",some);

    return 0;
}