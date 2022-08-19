#include <stdio.h>
int pow_i(int base, int pow);
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        printf("pow(3,%d) = %d\n", i, pow_i(3, i));
    }
    return 0;
}
int pow_i(int base, int pow)
{
    int n = 1;
    for (int i = 0; i < pow; ++i) {
        n *= base;
    }
    return n;
}