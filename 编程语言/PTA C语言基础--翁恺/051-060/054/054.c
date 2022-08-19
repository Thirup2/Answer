#include <stdio.h>
int step_multy(int n);
int main(void)
{
    int N;
    scanf("%d", &N);
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += step_multy(i);
    }
    printf("%lld", sum);
    return 0;
}
int step_multy(int n)
{
    int sum = 1;
    for (int i = 2; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}