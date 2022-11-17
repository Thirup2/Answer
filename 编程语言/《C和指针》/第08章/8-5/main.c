#include <stdio.h>
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z);
int main(void)
{
    int m1[3 * 2] = {2, -6, 3, 5, 1, -1};
    int m2[2 * 4] = {4, -2, -4, -5, -7, -3, 6, 7};
    int r[3 * 4];
    matrix_multiply(m1, m2, r, 3, 2, 4);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%-5d", r[i * 4 + j]);
        }
        printf("\n");
    }

    return 0;
}
void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z)
{
    int sum = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < z; j++) {
            sum = 0;
            for (int k = 0; k < y; k++) {
                sum += m1[i * y + k] * m2[k * z + j];
            }
            r[i * z + j] = sum;
        }
    }
}