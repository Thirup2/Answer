#include <stdio.h>
int fact(int N);
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
int fact(int N)
{
    int re = 1;
    for (int i = N; i > 1; i--) {
        re *= i;
    }
    return re;
}