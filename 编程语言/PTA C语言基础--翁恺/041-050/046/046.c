#include <stdio.h>
int main(void)
{
    int N, U, D;
    scanf("%d %d %d", &N, &U, &D);
    int time = 0;
    int len = 0;
    while (len < N) {
        ++time;
        len += U;
        if (len < N) {
            ++time;
            len -= D;
        }
    }
    printf("%d", time);

    return 0;
}