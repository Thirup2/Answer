#include "my_strncat.h"
#include <stdio.h>

int main(void)
{
    printf("请输入待连接字符串的前端部分：");
    char pre_string[20];
    scanf("%s", pre_string);
    printf("请输入待连接字符串的后端部分：");
    char back_string[20];
    scanf("%s", back_string);
    my_strncat(pre_string, back_string, 20);
    printf("连接后的字符串：%s\n", pre_string);

    return 0;
}