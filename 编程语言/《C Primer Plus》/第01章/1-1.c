#include <stdio.h>
#define SWAP 2.54
int main(void)
{
    printf("请输入一个英寸值:");
    double foot;
    scanf("%lf", &foot);
    printf("%gfoot = %gcm\n", foot, foot * SWAP);

    return 0;
}