#include <stdio.h>
int main(void)
{
    double x;
    scanf("%lf", &x);
    double result;
    if (x == 10) {
        result = 1.0 / x;
    } else {
        result = x;
    }
    printf("f(%.1lf) = %.1lf", x, result);

    return 0;
}