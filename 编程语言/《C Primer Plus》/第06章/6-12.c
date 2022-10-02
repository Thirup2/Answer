#include <stdio.h>
double seq1(int n);
double seq2(int n);
int main(void)
{
    int N;
    while (scanf("%d", &N) == 1 && N > 0) {
        printf("1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 + ...\n");
        printf("times: %d\n", N);
        printf("result: %g\n", seq1(N));
        printf("1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 + ...\n");
        printf("times: %d\n", N);
        printf("result: %g\n", seq2(N));
        printf("Please enter next times: ");
    }
    printf("Bye!\n");

    return 0;
}
double seq1(int n)
{
    double mother = 1.0;
    double son = 1.0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += son / mother;
        mother += 1.0;
    }
    return sum;
}
double seq2(int n)
{
    double mother = 1.0;
    double son = 1.0;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += son / mother;
            mother += 1.0;
        } else {
            sum -= son / mother;
            mother += 1.0;
        }
    }
    return sum;
}