#include <stdio.h>
#define CPI 2.54

int main(void)
{
    printf("Please input your height in inch: ");
    double height;
    scanf("%lf", &height);
    printf("You are %gcm height!\n", height * CPI);

    return 0;
}