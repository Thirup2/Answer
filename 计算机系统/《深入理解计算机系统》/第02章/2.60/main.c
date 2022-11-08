#include <stdio.h>
#include <stdlib.h>
unsigned replace_byte(unsigned x, int i, unsigned char b);
int main(int argc, char *argv[])
{
    if (argc < 4) {
        printf("参数不足!\n");
        exit(EXIT_FAILURE);
    }
    unsigned x = strtol(argv[1], NULL, 0);
    int i = strtol(argv[2], NULL, 0);
    unsigned char b = strtol(argv[3], NULL, 0);
    printf("%#x\n", replace_byte(x, i, b));

    return 0;
}
unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    if (i < 0) {
        printf("i值为负!\n");
        exit(EXIT_FAILURE);
    }
    if (i > sizeof(unsigned) - 1) {
        printf("i值过大!\n");
        exit(EXIT_FAILURE);
    }
    unsigned mask = ((unsigned) 0xff) << (i << 3);
    unsigned pos_byte = ((unsigned) b) << (i << 3);
    return (x & (~mask)) | pos_byte;
}