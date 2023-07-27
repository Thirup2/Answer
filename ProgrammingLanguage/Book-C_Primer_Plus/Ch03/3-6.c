#include <stdio.h>
#define GPQ 950
#define GPM 3.0e-23

int main(void)
{
    double quart;
    printf("please input the quality of water in quart: ");
    scanf("%lf", &quart);
    printf("%g quarts of water contains about %g water molecules.\n", quart, quart * GPQ / GPM);

    return 0;
}