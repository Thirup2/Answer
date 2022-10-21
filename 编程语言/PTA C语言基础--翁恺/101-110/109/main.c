#include <stdio.h>
int main(void)
{
    int year, hours;
    scanf("%d %d", &year, &hours);
    int price;
    if (year >= 5) {
        price = 50;
    } else {
        price = 30;
    }
    int rate;
    if (hours <= 40) {
        printf("%.2lf", (double) hours * price);
    } else {
        printf("%.2lf", (hours - 40) * 1.5 * price + 40 * price);
    }
    return 0;
}