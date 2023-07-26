#include <stdio.h>
#include <stddef.h>

char *my_strcat(char *dst, size_t size, const char *src);

int main(void)
{
    char dst[64];
    char src[48];
    printf("请输入需要连接的前部分：\n");
    fgets(dst, 64, stdin);
    printf("请输入需要连接的后部分：\n");
    fgets(src, 48, stdin);
    my_strcat(dst, 64, src);
    printf("连接后的字符串是：\n%s\n", dst);

    return 0;
}

char *my_strcat(char *dst, size_t size, const char *src)
{
    size_t i = 0;
    while (i < size - 1 && dst[i]) {
        i++;
    }
    size_t j = 0;
    while (i < size - 1 && src[j]) {
        dst[i] = src[j];
        i++;
        j++;
    }
    dst[i] = '\0';
    return dst;
}