#include <stdio.h>
int main(void)
{
    unsigned n;
    scanf("%u", &n);
    int single_line = (n - 1) / 2;
    for (int i = 0; i < single_line; ++i) {
        for (int j = 0; j < single_line - i; ++j) {
            printf("  ");
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < n; ++i) {
        printf("* ");
    }
    printf("\n");
    for (int i = 0; i < single_line; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("  ");
        }
        for (int j = 0; j < (single_line - i) * 2 - 1; ++j) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}