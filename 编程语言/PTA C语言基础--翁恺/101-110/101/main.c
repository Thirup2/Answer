#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < 75; ++j) {
            if (i * 5 + 2 * j + (100 - i - j) == 150) {
                printf("%d %d %d\n", i, j, 100 - i - j);
            }
        }
    }
    return 0;
}