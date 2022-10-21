#include <stdio.h>
int pow_t(int x, int y);
int main(void)
{
    int N;
    int count = 0;
    scanf("%d", &N);
    for (int i = 1; pow_t(i, 2) < N; ++i) {
        for (int j = i; pow_t(j, 2) < N; ++j) {
            if (pow_t(i, 2) + pow_t(j, 2) == N) {
                printf("%d %d\n", i, j);
                ++count;
            }
        }
    }
    if (count == 0) {
        printf("No Solution");
    }
    return 0;
}
int pow_t(int x, int y)
{
    int result = 1;
    for (int i = 1; i <= y; ++i) {
        result *= x;
    }
    return result;
}