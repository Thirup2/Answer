#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double son = 1;
    double mother = 1;
    double sum = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            sum += son / mother;
        } else {
            sum -= son / mother;
        }
        son++;
        mother += 2;
    }
    printf("%.3lf\n", sum);

    return 0;
}