#include <stdio.h>
int main(void)
{
    double n;
    scanf("%lf", &n);
    double a = 1;
    double ao;
    ao = (a + (n / a)) / 2;
    while (a != ao) {
        a = ao;
        printf("%lf\n", a);
        ao = (a + (n / a)) / 2;
    }
    return 0;
}