#include <stdio.h>
int main(void)
{
    int N;
    int m = 1;
    int count = 1;
    scanf("%d", &N);
    while (count < N) {
        m = (m + 1) * 2;
        count++;
    }
    printf("%d", m);

    return 0;
}