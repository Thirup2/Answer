#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, n;
    scanf("%d %d", &a, &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (n - i) * a * pow(10, i);
    }
    printf("s = %d", sum);

    return 0;
}