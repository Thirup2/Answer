#include <stdio.h>
#define SIZE 10
int del_substr(char *str, char const *substr);
int main(void)
{
    char string1[SIZE];
    char string2[SIZE];
    scanf("%s", string1);
    scanf("%s", string2);
    char *str = string1;
    char const *substr = string2;
    printf("%d %s\n", del_substr(str, substr), str);

    return 0;
}
int del_substr(char *str, char const *substr)
{
    if ((!(str && substr)) || *substr == '\0') {
        return 0;
    }
    char *ps = str;
    char *take_ps;
    char const *psubstr = substr;
    int sub_len = 0;
    while (*psubstr != '\0') {
        sub_len++;
        ++psubstr;
    }
    psubstr = substr;
    int r = 0;
    char *mem = NULL;
    while (*(ps + sub_len - 1) != '\0') {
        take_ps = ps;
        while (*psubstr != '\0') {
            if (*take_ps == *psubstr) {
                r = 1;
                mem = take_ps;
                while (*++psubstr != '\0') {
                    ++take_ps;
                    if (*take_ps != *psubstr) {
                        r = 0;
                        break;
                    }
                }
            }
            break;
        }
        if (r == 1) {
            break;
        }
        psubstr = substr;
        ++ps;
    }
    char *ano_mem = mem + sub_len;
    if (r == 1) {
        while (*ano_mem != '\0') {
            *mem = *ano_mem;    // 该编译器(MinGW-W64-builds-4.3.5)只能是以数组形式保存的字符串才能修改
            ++mem;
            ++ano_mem;
        }
        *mem = *ano_mem;
        return 1;
    } else {
        return 0;
    }
}