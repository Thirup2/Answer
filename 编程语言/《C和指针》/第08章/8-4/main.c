#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool identity_matrix(int n, int **matrix);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请输入一个数指定数组的大小\n");
        return -1;
    }
    int n = atoi(argv[1]);
    int **matrix = (int **) malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *) calloc(n, sizeof(int));
    }
    for (int i = 0, j = 0; i < n; i++, j++) {
        matrix[i][j] = 1;
    }
    // matrix[n - 1][n - 1] = 2;
    // matrix[n - 1][n - 1] = 0;
    // matrix[n - 1][n - 2] = 2;
    // matrix[n - 1][n - 2] = 1;
    printf("%s\n", identity_matrix(n, matrix) ? "是单位矩阵" : "不是单位矩阵");

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
bool identity_matrix(int n, int **matrix)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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