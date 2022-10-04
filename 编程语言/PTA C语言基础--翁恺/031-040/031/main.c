#include <stdio.h>
int sum_set(int N);
int main(void)
{
    int N;
    scanf("%d", &N);
    int i = 0;
    int Np;
    do {
        i++;
        Np = N;
        N = sum_set(N) * 3 + 1;
        printf("%d:%d\n", i, N);
    } while (N != Np);
}
int sum_set(int N)
{
    if (N < 10) {
        return N;
    }
    return (N % 10) + sum_set(N / 10);
}