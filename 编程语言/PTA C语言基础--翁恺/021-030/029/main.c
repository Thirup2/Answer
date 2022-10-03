#include <stdio.h>
static double a3, a2, a1, a0;
double fx(double x);
int main(void)
{
    double a, b;
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &a, &b);
    while (b - a >= 0.01) {
        if (fx((a + b) / 2) == 0) {
            printf("%.2lf\n", (a + b) / 2);
            return 0;
        } else if (fx((a + b) / 2) * fx(a) > 0) {
            a = (a + b) / 2;
            continue;
        } else if (fx((a + b) / 2) * fx(b) > 0) {
            b = (a + b) / 2;
            continue;
        }
    }
    printf("%.2lf\n", (a + b) / 2);

    return 0;
}
double fx(double x)
{
    return a3 * x * x * x + a2 * x * x + a1 * x + a0;
}