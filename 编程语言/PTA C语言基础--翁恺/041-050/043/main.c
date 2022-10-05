#include<stdio.h>
#include <stdlib.h>
int main()
{
    char color[5] = {'S','H','C','D','J'};
    int P = 54;
    int *start = (int *) malloc(P * sizeof(int));
    if (!start) {
        exit(EXIT_FAILURE);
    }
    int *end = (int *) malloc(P * sizeof(int));
    if (!end) {
        exit(EXIT_FAILURE);
    }
    int *operate = (int *) malloc(P * sizeof(int));
    if (!operate) {
        exit(EXIT_FAILURE);
    }
    int K, i;
    for (i = 0; i < P; i++) {
        start[i] = i + 1;
    }
    scanf("%d", &K);
    for (i = 0; i < P; i++) {
        scanf("%d", &operate[i]);
    }
    for (int step = 0; step < K; step++) {
        for (i = 0; i < P; i++) {
            end[operate[i] - 1] = start[i];
        }
        for (i = 0; i < P; i++) {
            start[i] = end[i];
        }
    }
    for (i = 0; i < P; i++) {
        start[i]--;
        if (i != 0)printf(" ");
        printf("%c%d", color[start[i] / 13], start[i] % 13 + 1);
    }
    free(start);
    free(end);
    free(operate);

    return 0;
}