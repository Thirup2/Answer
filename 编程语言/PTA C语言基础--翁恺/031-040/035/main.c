#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    int n = 1;
    for (int i = 0; i < N - 1; i++) {
        n = (n + 1) * 2;
    }
    printf("%d", n);

    return 0;
}