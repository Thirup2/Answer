#include <stdio.h>
double fact(int n);
int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("result = ");
    printf("%d\n", (int) (fact(n) / (fact(m) * fact(n - m))));

    return 0;
}
double fact(int n)
{
    double result = 1;
    for (int i = n; i > 1; i--) {
        result *= i;
    }
    return result;
}