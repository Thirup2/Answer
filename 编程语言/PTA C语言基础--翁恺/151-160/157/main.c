#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int k = 1;
    for (int i = 0; i < n; i++) {
        k *= 2;
    }
    printf("2^%d = %d\n", n, k);

    return 0;
}