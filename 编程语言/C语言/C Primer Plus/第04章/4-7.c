#include <stdio.h>
#include <float.h>
#define ONE 1.0
#define THREE 3.0
int main(void)
{
    //定义值
    float o_t;
    double O_T;

    //计算
    o_t = ONE/THREE;
    O_T = ONE/THREE;

    //打印
    printf("%-20s %-20s\n","float","double");
    printf("%-20.6f %-20.6lf\n",o_t,O_T);
    printf("%-20.12f %-20.12lf\n",o_t,O_T);
    printf("%-20.16f %-20.16lf\n",o_t,O_T);
    printf("%-20d %-20d\n",FLT_DIG,DBL_DIG);

    //函数返回值
    return 0;
}