#include <stdio.h>
int main(void)
{
    int y, f, n;
    scanf("%d", &n);
    for (y = 0; y < 100; y++) {
        for (f = 0; f < 100; f++) {
            if (2 * y * 100 + 2 * f + n == f * 100 + y) {
                printf("%d.%d\n", y, f);
                return 0;
            }
        }
    }
    printf("No Solution\n");
    return 0;
}