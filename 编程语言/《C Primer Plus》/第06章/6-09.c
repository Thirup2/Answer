#include <stdio.h>
double work(double n1, double n2);
int main(void)
{
    double d1, d2;
    while (scanf("%lf %lf", &d1, &d2) == 2) {
        if (d1 * d2 == 0) {
            printf("作为被除数的乘积为0, 请重新输入: ");
            continue;
        }
        printf("(%g - %g) / (%g * %g) = %g\n", d1, d2, d1, d2, work(d1, d2));
        printf("请输入下一组数据(按q退出): ");
    }

    return 0;
}
double work(double n1, double n2)
{
    return (n1 - n2) / (n1 * n2);
}