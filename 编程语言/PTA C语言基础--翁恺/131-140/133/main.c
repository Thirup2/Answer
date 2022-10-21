#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int sn = 0;
    for (int i = n; i > 0; i--) {
        int q = 1;
        for (int j = 0; j < n - i; ++j) {
            q *= 10;
        }
        sn += q * 6 * i;
    }
    printf("%d", sn);
    return 0;
}