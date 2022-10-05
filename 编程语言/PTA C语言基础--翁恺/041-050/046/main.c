#include <stdio.h>
int main(void)
{
    int N, U, D;
    scanf("%d %d %d", &N, &U, &D);
    int height = 0;
    int time = 0;
    while (height < N) {
        height += U;
        time++;
        if (height >= N) {
            printf("%d\n", time);
            return 0;
        }
        height -= D;
        time++;
    }

    return 0;
}