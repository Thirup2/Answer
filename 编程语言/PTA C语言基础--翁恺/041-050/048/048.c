#include <stdio.h>
double fact(int n);
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    double mm, mn, nmm;
    mm = fact(m);
    mn = fact(n);
    nmm = fact(n - m);
    double result;
    result = mn / (mm * nmm);
    printf("result = %g", result);

    return 0;
}
double fact(int n)
{
    double result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}