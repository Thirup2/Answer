#include <stdio.h>
int main(void)
{
    int N;
    double son = 2.0;
    double mother = 1.0;
    double temp;
    double sum = son / mother;
    int count = 1;
    scanf("%d", &N);
    while (count < N) {
        temp = mother;
        mother = son;
        son = temp + son;
        sum += son / mother;
        count++;
    }
    printf("%.2lf", sum);

    return 0;
}