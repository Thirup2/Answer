#include <stdio.h>
int main(void)
{
    double income;
    double rate;
    scanf("%lf", &income);
    if (income <= 1600) {
        rate = 0;
    } else if (income <= 2500) {
        rate = 0.05;
    } else if (income <= 3500) {
        rate = 0.1;
    } else if (income <= 4500) {
        rate = 0.15;
    } else {
        rate = 0.2;
    }
    double price;
    if (income > 1600) {
        price = (income - 1600) * rate;
    } else {
        price = 0;
    }
    printf("%.2lf", price);

    return 0;
}