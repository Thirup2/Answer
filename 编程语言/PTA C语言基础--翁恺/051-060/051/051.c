#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double son = 1;
    double mother = 1;
    int count = 0;
    double sum = 0;
    for (; count < N; ++count) {
        sum += son / mother;
        mother += 2;
    }
    printf("sum = %.6lf", sum);

    return 0;
}