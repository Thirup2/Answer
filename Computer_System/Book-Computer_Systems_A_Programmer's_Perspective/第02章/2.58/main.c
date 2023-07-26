#include <stdio.h>
int is_little_endian(void);
int main(void)
{
    if (is_little_endian() == 1) {
        printf("小端法\n");
    }
    if (is_little_endian() == 0) {
        printf("大端法\n");
    }
    if (is_little_endian() == -1) {
        printf("程序错误\n");
    }

    return 0;
}
int is_little_endian(void)
{
    int test = 0x12345678;
    unsigned char *FirstByte = (unsigned char *) &test;
    if (*FirstByte = 0x78) {
        return 1;
    } else if (*FirstByte = 0x12) {
        return 0;
    } else {
        return -1;
    }
}