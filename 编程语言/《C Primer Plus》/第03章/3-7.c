#include <stdio.h>
#define CmPFoot 2.54
int main(void)
{
    printf("请输入您的身高(/英寸): ");
    double foot;
    scanf("%lf", &foot);
    printf("%gfoot = %gcm\n", foot, foot * CmPFoot);

    return 0;
}