#include <stdio.h>
int main(void)
{
    unsigned price;
    unsigned rate;
    scanf("%u %u", &price, &rate);
    printf("%.2lf", (double) price * 0.1 * rate);

    return 0;
}