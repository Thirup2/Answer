#include <stdio.h>
#define MAXSIZE 32
void TransToChar(char bits[], unsigned int a);
void ShowBits(char bits[]);
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char bit_array[], unsigned bit_number);
void assign_bit(char bit_array[], unsigned bit_number, int value);
int test_bit(char bit_array[], unsigned bit_number);
int main(void)
{
    unsigned int a;
    scanf("%x", &a);
    char bits[MAXSIZE];
    TransToChar(bits, a);
    ShowBits(bits);
    unsigned bit_number;
    printf("请输入要测试的位：");
    scanf("%u", &bit_number);
    printf("请输入assign函数的第三参数: ");
    int value;
    scanf("%d", &value);
    printf("set_bit:\n");
    set_bit(bits, bit_number);
    ShowBits(bits);
    printf("clear_bit:\n");
    clear_bit(bits, bit_number);
    ShowBits(bits);
    printf("assign_bit:\n");
    assign_bit(bits, bit_number, value);
    ShowBits(bits);
    printf("test_bit:\n");
    if (test_bit(bits, bit_number)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
void TransToChar(char bits[], unsigned int a)
{
    unsigned int mask = 0x80000000;
    for (int i = 0; i < MAXSIZE; i++) {
        if ((mask & a) != 0) {
            bits[i] = '1';
        } else {
            bits[i] = '0';
        }
        mask >>= 1;
    }
}
void ShowBits(char bits[])
{
    for (int i = 0; i < MAXSIZE; i++) {
        printf("%c", bits[i]);
    }
    printf("\n");
}