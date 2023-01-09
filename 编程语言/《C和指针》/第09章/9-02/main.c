#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t my_strlen(const char *string, size_t size);

int main(void)
{
    char str[1024];
    printf("请输入一个字符串：");
    fgets(str, 1024, stdin);
    printf("1. 无末尾NUL字符：%lu\n", my_strlen(str, strlen(str)));
    printf("2. 刚好含末尾NUL字符：%lu\n", my_strlen(str, strlen(str) + 1));
    printf("3. 原数组大小：%lu\n", my_strlen(str, 1024));

    return 0;
}

size_t my_strlen(const char *string, size_t size)
{
    int i = 0;
    while (i < size && string[i]) {
        i++;
    }
    return i;
}