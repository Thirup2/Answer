#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double sum = 0;
    double son = 1;
    double mother = 1;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            sum += son / mother;
        } else {
            sum -= son / mother;
        }
        mother += 3;
    }
    printf("sum = %.3lf\n", sum);

    return 0;
}