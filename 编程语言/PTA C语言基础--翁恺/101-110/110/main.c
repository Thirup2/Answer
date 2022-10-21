#include <stdio.h>
int main(void)
{
    int A;
    int count = 0;
    scanf("%d", &A);
    for (int i = A; i < A + 4; ++i) {
        for (int j = A; j < A + 4; ++j) {
            for (int q = A; q < A + 4; ++q) {
                if (i != j && i != q && j != q) {
                    printf("%d%d%d", i, j, q);
                    count++;
                    if (count % 6 != 0) {
                        printf(" ");
                    } else {
                        printf("\n");
                    }
                }
            }
        }
    }
    return 0;
}