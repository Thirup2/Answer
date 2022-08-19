#include <stdio.h>
int main(void)
{
    int m, n;
    int sum = 0;
    int r = 0;
    int count = 0;
    scanf("%d %d", &m, &n);
    for (int i = m; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (sum == i) {
            r = 1;
            count++;
        }
        if (r) {
            printf("%d = 1", i);
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    printf(" + %d", j);
                }
            }
            printf("\n");
        }
        r = 0;
        sum = 0;
    }
    if (count == 0) {
        printf("None");
    }
    return 0;
}