#include <stdio.h>
#include <stdlib.h>
int gcd(int M, int N);
int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("请输入两个整型数作为参数\n");
        return -1;
    }
    int M = atoi(argv[1]);
    int N = atoi(argv[2]);
    if (M < N) {
        int temp = M;
        M = N;
        N = temp;
    }
    printf("gcd(M, N) = %d\n", gcd(M, N));

    return 0;
}
int gcd(int M, int N)
{
    if (M <= 0 || N <= 0) {
        return 0;
    }
    if (M % N == 0) {
        return N;
    } else {
        return gcd(N, M % N);
    }
}