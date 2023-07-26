#include <stdio.h>
#include <stdlib.h>
int hermite(int n, int x);
int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("请输入两个整型数作为参数（第一个为n，第二个为x）\n");
        return -1;
    }
    int n = atoi(argv[1]);
    int x = atoi(argv[2]);
    printf("H_n(x) = %d\n", hermite(n, x));

    return 0;
}
int hermite(int n, int x)
{
    if (n <= 0) {
        return 1;
    }
    if (n == 1) {
        return 2 * x;
    } else {
        return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
    }
}