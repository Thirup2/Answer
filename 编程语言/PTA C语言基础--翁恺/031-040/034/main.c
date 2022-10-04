#include <stdio.h>
int main(void)
{
    int N;
    scanf("%d", &N);
    double son = 2;
    double mother = 1;
    double sum = 0;
    double temp;
    for (int i = 0; i < N; i++) {
        sum += son / mother;
        temp = son;
        son = son + mother;
        mother = temp;
    }
    printf("%.2lf\n", sum);

    return 0;
}