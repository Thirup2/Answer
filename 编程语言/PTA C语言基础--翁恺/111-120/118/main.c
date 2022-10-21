#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 2) {
        printf("%d", i);
        if (i + 2 <= n) {
            printf(" ");
        }
    }
    return 0;
}