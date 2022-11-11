#include <stdio.h>
#include <stdlib.h>
int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit);
int main(void)
{
    int original_value;
    int value_to_store;
    unsigned starting_bit;
    unsigned ending_bit;
    printf("请输入原始值：");
    scanf("%x", &original_value);
    printf("请输入需要存储的值：");
    scanf("%x", &value_to_store);
    printf("请输入起始位置：");
    scanf("%u", &starting_bit);
    printf("请输入结束位置：");
    scanf("%u", &ending_bit);
    printf("返回值：");
    printf("%#x\n", store_bit_field(original_value, value_to_store, starting_bit, ending_bit));

    return 0;
}
int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit)
{
    if (starting_bit > sizeof(int) * 8 || ending_bit > sizeof(int) * 8 || starting_bit < ending_bit) {
        exit(EXIT_FAILURE);
    }
    int mask = 0;
    for (int i = starting_bit; i >= ending_bit; i--) {
        mask <<= 1;
        mask |= 1;
    }
    mask <<= ending_bit;
    original_value &= (~mask);
    value_to_store <<= ending_bit;
    value_to_store &= mask;
    return original_value | value_to_store;
}