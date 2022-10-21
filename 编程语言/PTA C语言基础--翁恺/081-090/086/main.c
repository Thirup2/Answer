#include <stdio.h>
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d + %d = %d\n", m, n, m + n);
    printf("%d - %d = %d\n", m, n, m - n);
    printf("%d * %d = %d\n", m, n, m * n);
    printf("%d / %d = %d", m, n, m / n);
    return 0;
}