#include <stdio.h>
void Put_set(int N);
int main(void)
{
    int N;
    scanf("%d", &N);
    Put_set(N);

    return 0;
}
void Put_set(int N)
{
    if (N < 10) {
        printf("%d ", N);
        return;
    }
    Put_set(N / 10);
    printf("%d ", N % 10);
}