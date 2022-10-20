#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double son = 1.0;
    double mother = 1.0;
    double sum = 0.0;
    for (int i = 1; i <= N; ++i) {
        sum += son / mother;
        mother += 1.0;
    }
    printf("sum = %.6lf", sum);

    return 0;
}