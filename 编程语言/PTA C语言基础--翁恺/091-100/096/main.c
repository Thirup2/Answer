#include <stdio.h>
#include <math.h>
int main(void)
{
    double money, year, rate;
    scanf("%lf %lf %lf", &money, &year, &rate);
    double interest;
    interest = money * pow(1 + rate, year) - money;
    printf("interest = %.2lf", interest);

    return 0;
}