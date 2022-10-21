#include <stdio.h>
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    double sum = 0.0;
    for (int i = m; i <= n; ++i) {
        sum += i * i + 1.0 / i;
    }
    printf("sum = %.6lf", sum);

    return 0;
}