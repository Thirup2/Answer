/* 请使用文件重定向将标准输入重定向到test.txt文件 */
#include <stdio.h>
int main(void)
{
    char ch;
    int at_beginning = 1;
    int line = 1;
    while ((ch = getchar()) != EOF) {
        if (at_beginning) {
            printf("%d: ", line++);
            at_beginning = 0;
        }
        if (ch == '\n') {
            at_beginning = 1;
        }
        putchar(ch);
    }

    return 0;
}