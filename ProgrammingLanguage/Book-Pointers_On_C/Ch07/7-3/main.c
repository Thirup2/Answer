#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int ascii_to_integer(char *string);
int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("请输入一个字符串作为参数！\n");
        return -1;
    }
    printf("%d\n", ascii_to_integer(argv[1]));

    return 0;
}
int ascii_to_integer(char *string)
{
    int result = 0;
    while (*string) {
        if (!isdigit(*string)) {
            return 0;
        }
        result *= 10;
        result += *string - '0';
        string++;
    }
    return result;
}