#include <stdio.h>
unsigned int reverse_bits(unsigned int value);
void PrintBits(unsigned int value);
int main(void)
{
    unsigned int a;
    scanf("%x", &a);
    PrintBits(a);
    PrintBits(reverse_bits(a));

    return 0;
}
unsigned int reverse_bits(unsigned int value)
{
    unsigned int mask_a = 1;
    unsigned int mask_b = 1;
    unsigned int result = 0;
    for (int i = 0; i < sizeof(unsigned int) * 8; i++) {
        if ((mask_a & value) != 0) {
            result = result | mask_b;
            if (i != sizeof(unsigned int) * 8 - 1) {            // 不移最后一次
                result <<= 1;
            }
        } else {
            if (i != sizeof(unsigned int) * 8 - 1) {
                result <<= 1;
            }
        }
        mask_a <<= 1;
    }
    return result;
}
void PrintBits(unsigned int value)
{
    unsigned int mask = 1;
    mask = mask << (sizeof(unsigned int) * 8 - 1);
    for (int i = 0; i < (sizeof(unsigned int) * 8); i++) {
        if ((mask & value) != 0) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;
    }
    printf("\n");
}