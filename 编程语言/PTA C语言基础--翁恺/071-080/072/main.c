#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    if (N % 5 > 3 || N % 5 == 0) {
        printf("Drying in day %d", N);
    } else {
        printf("Fishing in day %d", N);
    }
    return 0;
}