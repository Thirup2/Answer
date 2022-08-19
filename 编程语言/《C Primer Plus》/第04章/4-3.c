#include <stdio.h>
int main(void)
{
    float some;
    printf("请输入一个浮点数:\n");
    while(scanf("%f",&some)==1){
        printf("The input is %.1f or %.1e.\n",some,some);
        printf("The input is %+.3f or %.3E.\n",some,some);
        printf("请输入一个浮点数:\n");
    }

    return 0;
}