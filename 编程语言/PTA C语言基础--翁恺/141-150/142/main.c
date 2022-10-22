#include <stdio.h>
#include <stdlib.h>
int isthat(int **matrix, int n);
int main(void)
{
    int times;
    int n;
    scanf("%d", &times);
    int **matrix;
    for (int i = 0; i < times; i++) {
        scanf("%d", &n);
        matrix = (int **) malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            matrix[j] = (int *) malloc(n * sizeof(int));
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                scanf("%d", &matrix[x][y]);
            }
        }
        printf("%s\n", isthat(matrix, n) ? "YES" : "NO");
        for (int j = 0; j < n; j++) {
            free(matrix[j]);
        }
        free(matrix);
    }

    return 0;
}
int isthat(int **matrix, int n)
{
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return 0;
            }
        }
    }
    return 1;
}