#include <stdio.h>
int step(int N);
int main(void)
{
    int N;
    scanf("%d", &N);
    int sum = 1;
    for (int i = 2; i <= N; i++) {
        sum += step(i);
    }
    printf("%d\n", sum);

    return 0;
}
int step(int N)
{
    int sum = 2;
    for (int i = N; i > 2; i--) {
        sum *= i;
    }
    return sum;
}