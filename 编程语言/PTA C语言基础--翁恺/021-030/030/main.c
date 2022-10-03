#include <stdio.h>
char num[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void sit(int N);
int main(void)
{
    int N;
    scanf("%d", &N);
    if (N < 0) {
        printf("fu ");
        N = -N;
    }
    sit(N / 10);
    printf("%s\n", num[N % 10]);
    return 0;
}
void sit(int N)
{
    if (N == 0) {
        return;
    }
    sit(N / 10);
    printf("%s ", num[N % 10]);
}