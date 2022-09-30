#include <stdio.h>
#define GPF 3.0e-23
#define GPK 950
int main(void)
{
    printf("请输入水的夸脱数: ");
    int kwto;
    scanf("%d", &kwto);
    printf("%d夸脱 = %g分子\n", kwto, kwto * GPK / GPF);

    return 0;
}