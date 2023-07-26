#include <stdio.h>
#include <stdbool.h>
bool identity_matrix(int matrix[][10]);
int main(void)
{
    int matrix[10][10] = {0};
    for (int i = 0, j = 0; i < 10; i++, j++) {
        matrix[i][j] = 1;
    }
    // matrix[1][1] = 0;
    // matrix[1][1] = 2;
    // matrix[2][3] = 1;
    // matrix[2][3] = 2;
    printf("%s\n", identity_matrix(matrix) ? "是单位矩阵" : "不是单位矩阵");

    return 0;
}
bool identity_matrix(int matrix[][10])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != 1) {
                return false;
            }
            if (i == j && matrix[i][j] != 1) {
                return false;
            }
            if (matrix[i][j] == 1 && i != j) {
                return false;
            }
        }
    }
    return true;
}