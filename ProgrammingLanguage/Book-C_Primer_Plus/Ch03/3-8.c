#include <stdio.h>
#define Pint2Cup 2
#define Cup2Ounce 8
#define Ounce2Tablespoon 2
#define Tablespoon2Teaspoon 3

int main(void)
{
    double cup;
    printf("please input the value of water in cup: ");
    scanf("%lf", &cup);
    printf("%g Cup is %g Pint, is %g Ounce, is %g Tablespoon, is %g Teaspoon.\n", cup, cup / Pint2Cup, cup * Cup2Ounce, cup * Cup2Ounce * Ounce2Tablespoon, cup * Cup2Ounce * Ounce2Tablespoon * Tablespoon2Teaspoon);

    return 0;
}