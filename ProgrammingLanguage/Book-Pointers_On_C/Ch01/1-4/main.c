/* 请使用文件重定向到将标准输入重定向为test.txt */
#include <stdio.h>
#include <string.h>
#define MAXSIZE 1001
int main(void)
{
    char max[MAXSIZE];
    char now[MAXSIZE];
    char ch;
    int max_num = 0;
    int sum = 0;
    while ((ch = getchar()) != EOF) {
        if (ch != '\n') {
            now[sum] = ch;
            sum++;
        } else {
            now[sum] = '\0';
            if (sum > max_num) {
                max_num = sum;
                strcpy(max, now);
            }
            sum = 0;
        }
    }
    printf("%s\n%d\n", max, max_num);

    return 0;
}