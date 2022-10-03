#include <stdio.h>
static int i = 0;
int num_sum(int n);
int main(void)
{
    int N;
    scanf("%d", &N);
    int sum;
    if (N) {
        sum = num_sum(N);
    }
    printf("%d %d\n", i, sum);

    return 0;
}
int num_sum(int n)
{
    if (n == 0) {
        return 0;
    }
    i++;
    return (n % 10) + num_sum(n / 10);
}