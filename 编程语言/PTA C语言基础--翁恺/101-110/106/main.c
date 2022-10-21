#include <stdio.h>
#include <math.h>
int main(void)
{
    double sum = 0;
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        sum += sqrt(i);
    }
    printf("sum = %.2lf", sum);
    return 0;
}