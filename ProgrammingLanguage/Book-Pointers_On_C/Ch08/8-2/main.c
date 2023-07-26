#include <stdio.h>
#include <stdlib.h>
float single_tax(float income);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请至少输入一个值作为income!\n");
        return -1;
    }
    float income;
    for (int i = 1; i < argc; i++) {
        income = atof(argv[i]);
        printf("%g: %g\n", income, single_tax(income));
    }

    return 0;
}
float single_tax(float income)      // 数字一大就引发错误？
{
    static float base_tax[5] = {0.f, 3502.50f, 12798.50f, 31832.50f, 81710.50f};
    static float tax_rate[5] = {0.15f, 0.28f, 0.31f, 0.36f, 0.396f};
    static float start_base[5] = {0.f, 23350.f, 56550.f, 117950.f, 256500.f};
    int i = 0;
    for (; income > start_base[i]; i++);
    i--;
    return base_tax[i] + tax_rate[i] * (income - start_base[i]);
}