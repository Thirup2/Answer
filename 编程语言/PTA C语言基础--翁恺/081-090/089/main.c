#include <stdio.h>
int main(void)
{
    const int Line = 50;
    const double Under_Line = 0.53;
    const double Up_Line = 0.05;
    double n;
    scanf("%lf", &n);
    if (n < 0) {
        printf("Invalid Value!");
        return 0;
    }
    double price;
    if (n <= Line) {
        price = n * Under_Line;
    } else {
        price = n * Under_Line + (n - Line) * Up_Line;
    }
    printf("cost = %.2lf", price);

    return 0;
}