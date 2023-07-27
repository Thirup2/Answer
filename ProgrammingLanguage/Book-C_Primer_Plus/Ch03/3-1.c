#include <stdio.h>
#include <limits.h>

int main(void)
{
    unsigned int uinta = UINT_MAX;
    signed int sintb = INT_MAX;
    printf("An unsigned int from %u to %u + 1 is: %u\n", uinta, uinta, uinta + 1);
    printf("A singned int from %d to %d + 1 is: %d\n", sintb, sintb, sintb + 1);

    float f1 = 3.4e38;
    float f2 = 3.4e-5;
    printf("A float from %f to %f * 10 is: %f\n", f1, f1, f1 * 10);
    printf("A float from %f to %f / 10 is: %f\n", f2, f2, f2 / 10);

    return 0;
}