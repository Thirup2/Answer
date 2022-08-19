#include <stdio.h>
#define CM_IN 2.54
int main(void)
{
    float inch;
    printf("请输入您的身高(英寸):\n");
    while(scanf("%f",&inch)==1){
        printf("%g inches = %g cm\n",inch,inch*CM_IN);
        printf("请输入您的身高(英寸):\n");
    }

    return 0;
}