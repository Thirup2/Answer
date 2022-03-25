#include <stdio.h>
int main(void)
{
    int yyyy,mm,dd;

    scanf("%d-%d-%d",&mm,&dd,&yyyy);

    printf("%02d-%02d-%02d",yyyy,mm,dd);

    return 0;
}