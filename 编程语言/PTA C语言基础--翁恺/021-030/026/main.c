#include <stdio.h>
int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    if (M > N) {
        int temp;
        temp = M;
        M = N;
        N = temp;
    }
    for (int i = M; i > 0; i--) {
        if (M % i == 0 && N % i == 0) {
            printf("%d ", i);
            break;
        }
    }
    for (int i = N; i <= M * N; i++) {
        if (i % M == 0 && i % N == 0) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}