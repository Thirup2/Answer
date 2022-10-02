#include <stdio.h>
double price(double s, int time);
int main(void)
{
    double s;
    int time;
    scanf("%lf %d", &s, &time);
    printf("%.0lf\n", price(s, time));

    return 0;
}
double price(double s, int time)
{
    double sum = 0;
    if (time >= 5) {
        sum += (time) / 5 * 2;
    }
    if (s <= 3) {
        sum += 10;
    } else if (s <= 10) {
        sum += 10 + (s - 3) * 2;
    } else {
        sum += 24 + (s - 10) * 3;
    }

    return sum;
}