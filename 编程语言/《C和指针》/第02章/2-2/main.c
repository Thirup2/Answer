/* 可直接重定向本文件进行测试 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ch;
    int braces;

    braces = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == '{') {
            braces += 1;            // 当检测到一个左括号就将braces加1, 表示未匹配的括号数
        }
        if (ch == '}') {            // 遇到右括号就减少一个未匹配的括号数
            if (braces == 0) {      // 如果减少之前没有未匹配的括号, 则说明这个右括号没有匹配的左括号
                printf("Extra closing brace!\n");
            } else {
                braces -= 1;
            }
        }
    }
    if (braces > 0) {               // 若括号没匹配完则输出未匹配的个数
        printf("%d numatched opening brace(s)!\n", braces);
    }

    return 0;
}