#include <stdio.h>
#include <math.h>
int main(void)
{
    double x;
    scanf("%lf", &x);
    double result;
    if (x >= 0) {
        result = sqrt(x);
    } else {
        result = pow(x + 1, 2) + 2 * x + 1 / x;
    }
    printf("f(%.2lf) = %.2lf", x, result);

    return 0;
}