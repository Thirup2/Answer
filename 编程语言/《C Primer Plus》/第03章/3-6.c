#include <stdio.h>
#define G_F 3.0e-23     //一个水分子的质量
#define G_K 950         //一夸脱水的质量
int main(void)
{
    float kw;
    printf("请输入水的夸脱数:\n");
    while(scanf("%f",&kw)==1){
        printf("%g 夸脱 = %g 水分子\n",kw,kw*G_K/G_F);
        printf("请输入水的夸脱数:\n");
    }

    return 0;
}