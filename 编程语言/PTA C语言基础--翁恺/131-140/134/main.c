#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; ++i) {
        printf("%d ", i);
    }
    for (int i = n; i > 0; --i) {
        printf("%d", i);
        if (i != 1) {
            printf(" ");
        }
    }
    return 0;
}