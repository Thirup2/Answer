#include <stdio.h>
#define SOME 152
int main(void)
{
    int a,b,c;
    a=SOME/100;
    b=SOME/10-a*10;
    c=SOME%10;
    printf("152 = %d + %d*10 + %d*100",c,b,a);

    return 0;
}