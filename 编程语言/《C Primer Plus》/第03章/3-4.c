#include <stdio.h>
int main(void)
{
    double f;
    printf("Enter a floating-point value: ");
    scanf("%lf", &f);
    printf("fixed-point notation: %lf\n", f);
    printf("exponential notation: %e\n", f);
    printf("p notation: %.2a\n", f);

    return 0;
}