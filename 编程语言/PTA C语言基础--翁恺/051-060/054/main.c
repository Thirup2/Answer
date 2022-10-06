#include <stdio.h>
int fact(int n);
int main(void)
{
    int N;
    scanf("%d", &N);
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += fact(i);
    }
    printf("%d\n", sum);

    return 0;
}
int fact(int n)
{
    int sum = 1;
    for (int i = n; i >= 2; i--) {
        sum *= i;
    }
    return sum;
}