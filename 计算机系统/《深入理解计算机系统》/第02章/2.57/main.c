#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len);
void show_short(short x);
void show_long(long x);
void show_double(double x);

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请输入一个参数!\n");
        return 1;
    }
    int val = strtol(argv[1], NULL, 0);
    printf("show_short\n");
    show_short(val);
    printf("show_long\n");
    show_long(val);
    printf("show_double\n");
    show_double(val);

    return 0;
}
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}
void show_short(short x)
{
    show_bytes((byte_pointer) &x, sizeof(short));
}
void show_long(long x)
{
    show_bytes((byte_pointer) &x, sizeof(long));
}
void show_double(double x)
{
    show_bytes((byte_pointer) &x, sizeof(double));
}