#include <stdio.h>
int main(void)
{
    int N, C;
    scanf("%d %c", &N, &C);
    int line = N / 2;
    if (N / 2.0 >= (N / 2) + 0.5) {
        line++;
    }
    for (int i = 0; i < line; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", C);
        }
        printf("\n");
    }

    return 0;
}