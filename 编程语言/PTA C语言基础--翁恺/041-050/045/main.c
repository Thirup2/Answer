#include <stdio.h>
int main(void)
{
    int m, n;
    int sum = 0;
    int k = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            k++;
            printf("%d = ", i);
            printf("1");
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    printf(" + %d", j);
                }
            }
            printf("\n");
        }
        sum = 0;
    }
    if (k == 0) {
        printf("None\n");
    }
    return 0;
}