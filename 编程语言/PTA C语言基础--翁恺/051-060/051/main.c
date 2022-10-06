#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double sum = 0;
    double son = 1;
    double mother = 1;
    for (int i = 0; i < N; i++) {
        sum += son / mother;
        mother += 2;
    }
    printf("sum = %.6lf\n", sum);

    return 0;
}