#include <stdio.h>
int main(void)
{
    unsigned lower;
    unsigned upper;
    scanf("%u %u", &lower, &upper);
    if (lower > upper) {
        printf("Invalid.");
        return 0;
    }
    printf("fahr celsius\n");
    for (int i = lower; i <= upper; i += 2) {
        printf("%d", i);
        printf("%6.1f\n", 5.0 * (i - 32) / 9);
    }
    return 0;
}