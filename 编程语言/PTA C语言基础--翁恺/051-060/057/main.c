#include <stdio.h>
double step_multy(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    double son = 1.0;
    double sum = 1.0;
    for (int i = 1; i <= n; ++i) {
        sum += son / step_multy(i);
    }
    printf("%.8lf", sum);

    return 0;
}
double step_multy(int n)
{
    double sum = 1.0;
    for (int i = 2; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}