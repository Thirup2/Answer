#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double son = 1.0;
    double mother = 1.0;
    int count = 0;
    double sum = 0.0;
    for (; count < N; ++count) {
        if (count % 2 == 0) {
            sum += son / mother;
        } else {
            sum -= son / mother;
        }
        mother += 3;
    }
    printf("sum = %.3lf", sum);

    return 0;
}