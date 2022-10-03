#include <stdio.h>
int rabbits(int i);
int main(void)
{
    int N;
    scanf("%d", &N);
    int i = 1;
    int mon;
    while (i) {
        if ((rabbits(i)) >= N) {
            printf("%d\n", i);
            return 0;
        }
        i++;
    }
}
int rabbits(int i)
{
    if (i == 1 || i == 2) {
        return 1;
    } else {
        return rabbits(i - 2) + rabbits(i - 1);
    }
}