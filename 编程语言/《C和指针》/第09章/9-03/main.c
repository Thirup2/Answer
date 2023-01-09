#include <stdio.h>

char *my_strcpy(char *dst, size_t size, const char *src);

int main(void)
{
    char dst[15];
    char src[20];
    printf("请输入用于复制的字符串内容：");
    fgets(src, 20, stdin);
    my_strcpy(dst, 15, src);
    printf("复制之后的字符串是：");
    printf("%s\n", dst);

    return 0;
}

char *my_strcpy(char *dst, size_t size, const char *src)
{
    size_t i = 0;
    while (i < size - 1 && src[i]) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';

    return dst;
}