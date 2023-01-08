#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>
int main()
{
    printf("请输入字符串：");           // 测试时直接重定向到本文件即可
    char ch;
    size_t cntrlcnt = 0, spacecnt = 0, digitcnt = 0, lowercnt = 0, uppercnt = 0, punctcnt = 0, noprintcnt = 0;
    size_t cnt = 0;
    while ((ch = getchar()) != EOF) {
        if (iscntrl(ch)) {
            cntrlcnt++;
            cnt++;
        } else if (isspace(ch)) {
            spacecnt++;
            cnt++;
        } else if (isdigit(ch)) {
            digitcnt++;
            cnt++;
        } else if (islower(ch)) {
            lowercnt++;
            cnt++;
        } else if (isupper(ch)) {
            uppercnt++;
            cnt++;
        } else if (ispunct(ch)) {
            punctcnt++;
            cnt++;
        } else if (!isprint(ch)) {
            noprintcnt++;
            cnt++;
        }
    }
    printf("\n------------------------------------------------------------------------------\n");
    printf("|%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|\n", "cntrl", "space", "digit", "lower", "upper", "punct", "noprint");
    printf("------------------------------------------------------------------------------\n");
    printf("|%5.2lf%-5s|%5.2lf%-5s|%5.2lf%-5s|%5.2lf%-5s|%5.2lf%-5s|%5.2lf%-5s|%5.2lf%-5s|\n",
           (double) cntrlcnt / cnt * 100, "%",
           (double) spacecnt / cnt * 100, "%",
           (double) digitcnt / cnt * 100, "%",
           (double) lowercnt / cnt * 100, "%",
           (double) uppercnt / cnt * 100, "%",
           (double) punctcnt / cnt * 100, "%",
           (double) noprintcnt / cnt * 100, "%");
    printf("------------------------------------------------------------------------------\n");

    return 0;
}