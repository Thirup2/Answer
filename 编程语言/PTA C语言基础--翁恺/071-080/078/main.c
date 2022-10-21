#include <stdio.h>
int main(void)
{
    const double Gas_90 = 6.95;
    const double Gas_93 = 7.44;
    const double Gas_97 = 7.93;
    int ml, kind;
    char level;
    double gas_price;
    scanf("%d %d %c", &ml, &kind, &level);
    switch (kind) {
        case 90:
            gas_price = Gas_90;
            break;
        case 93:
            gas_price = Gas_93;
            break;
        case 97:
            gas_price = Gas_97;
            break;
    }
    double rate;
    switch (level) {
        case 'm':
            rate = 0.95;
            break;
        case 'e':
            rate = 0.97;
            break;
    }
    printf("%.2lf", ml * gas_price * rate);

    return 0;
}