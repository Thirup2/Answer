#include <stdio.h>
#include <math.h>
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d %d\n", n % 2, m * (int) pow(2, n / 2));

    return 0;
}