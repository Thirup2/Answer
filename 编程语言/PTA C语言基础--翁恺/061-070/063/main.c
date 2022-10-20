#include <stdio.h>
int main(void)
{
    int n;
    double height;
    double sum = 0.0;
    scanf("%lf %d", &height, &n);
    double now = height;
    for (int i = 1; i <= n; ++i) {
        sum += 2 * now;
        now *= 0.5;
    }
    if (n == 0) {
        sum = height;
        now = 0;
    }
    printf("%.1lf %.1lf", sum - height, now);

    return 0;
}