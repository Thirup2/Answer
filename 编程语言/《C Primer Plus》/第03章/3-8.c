#include <stdio.h>
#define B_P 2       //1 品脱 = 2 杯
#define A_B 8       //1 杯 = 8 盎司
#define D_A 2       //1 盎司 = 2 大汤勺
#define C_D 3       //1 大汤勺 = 3 茶勺
int main(void)
{
    float b_num;
    printf("请输入杯数:\n");
    while(scanf("%f",&b_num)==1){
        printf("%g 杯 = %g 品脱 = %g 盎司 = %g 大汤勺 = %g 茶勺\n",
                b_num,b_num/B_P,b_num*A_B,b_num*A_B*D_A,b_num*A_B*D_A*C_D);
        printf("请输入杯数:\n");
    }

    return 0;
}