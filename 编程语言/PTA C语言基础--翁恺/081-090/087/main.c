#include <stdio.h>
int main(void)
{
    double x;
    scanf("%lf", &x);
    double result;
    if (x == 0) {
        result = 0;
    } else {
        result = 1 / x;
    }
    printf("f(%.1lf) = %.1lf", x, result);

    return 0;
}