#include <stdio.h>
int main(void)
{
    const int F = 150;
    int C;
    C = 5 * (F - 32) / 9.0;
    printf("fahr = %d, celsius = %d", F, C);
    return 0;
}