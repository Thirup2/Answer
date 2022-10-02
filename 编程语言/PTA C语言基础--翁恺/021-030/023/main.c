#include <stdio.h>
double sumofwater(double n);
int main(void)
{
    double amount;
    scanf("%lf", &amount);
    printf("%.2lf\n", sumofwater(amount));

    return 0;
}
double sumofwater(double n)
{
    if (n <= 15) {
        return 4 * n / 3;
    } else {
        return 2.5 * n - 17.5;
    }
}