#include <stdio.h>
double son(int x);
double mother(int n);
int main(void)
{
    double x;
    scanf("%lf", &x);
    double sum = 0;
    double n;
    n = son(0) / mother(0);
    for (int i = 0; n >= x; ++i) {
        n = son(i) / mother(i);
        sum += n;
    }
    printf("%.6lf", 2.0 * sum);
    return 0;
}
double son(int x)
{
    if (x == 0) {
        return 1;
    }
    double result = 1;
    for (int i = 1; i <= x; ++i) {
        result *= i;
    }
    return result;
}
double mother(int n)
{
    double result = 1;
    for (int i = 0; i <= n; ++i) {
        result *= 2.0 * i + 1.0;
    }
    return result;
}