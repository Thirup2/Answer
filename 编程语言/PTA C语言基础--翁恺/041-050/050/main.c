#include <stdio.h>
int main(void)
{
    double lower, upper;
    scanf("%lf %lf", &lower, &upper);
    if (upper < lower) {
        printf("Invalid.\n");
        return 0;
    }
    printf("fahr celsius\n");
    while (lower <= upper) {
        printf("%g%6.1lf\n", lower, 5.0 * (lower - 32) / 9.0);
        lower += 2;
    }
    return 0;
}