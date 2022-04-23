#include <stdio.h>
#include <float.h>
int main(void)
{
    double some = 1.0/3.0;
    float some2 = 1.0/3.0;
    printf("%-20s%-20s\n","double","float");
    printf("%-20.6lf%-20.6f\n",some,some2);
    printf("%-20.12lf%-20.12f\n",some,some2);
    printf("%-20.16lf%-20.16f\n",some,some2);
    printf("%-20d%-20d\n",DBL_DIG,FLT_DIG);

    return 0;
}