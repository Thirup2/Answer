#include <stdio.h>
double pow_d(double x, int n);
double step_multy(int n);
int main(void)
{
    double x;
    scanf("%lf", &x);
    int i = 1;
    double sum = 1.0 + x;
    while (pow_d(x, i) / step_multy(i) >= 0.00001) {
        ++i;
        sum += pow_d(x, i) / step_multy(i);
    }
    printf("%.4lf", sum);

    return 0;
}
double pow_d(double x, int n)
{
    double result = 1.0;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}
double step_multy(int n)
{
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}