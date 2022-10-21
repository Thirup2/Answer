#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int count = i + 1;
        for (int j = n - i, q = n; j > 0; --j, --q) {
            printf("%4d", count);
            count += q;
        }
        printf("\n");
    }
    return 0;
}