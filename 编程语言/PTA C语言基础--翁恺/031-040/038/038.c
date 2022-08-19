#include <stdio.h>
int main(void)
{
    int y;
    int f;
    int sum_fen;
    int n;
    scanf("%d", &n);
    for (y = 0; y < 100; y++) {
        for (f = 0; f < 100; f++) {
            sum_fen = f * 100 + y;
            if (sum_fen - n == 2 * y * 100 + 2 * f) {
                printf("%d.%d", y, f);
                return 0;
            }
        }
    }
    printf("No Solution");
    return 0;
}