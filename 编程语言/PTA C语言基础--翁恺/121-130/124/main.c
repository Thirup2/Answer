#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int count = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = n - i; j > 0; --j) {
            printf("%4d", count);
            count++;
        }
        printf("\n");
    }
    return 0;
}