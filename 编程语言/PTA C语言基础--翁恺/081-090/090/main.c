#include <stdio.h>
int main(void)
{
    int ch;
    int count = 0;
    int let_cnt = 0;
    int bla_cnt = 0;
    int dig_cnt = 0;
    int oth_cnt = 0;
    while (count < 10) {
        ch = getchar();
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            ++let_cnt;
        } else if (ch == ' ' || ch == '\n') {
            ++bla_cnt;
        } else if (ch >= '0' && ch <= '9') {
            ++dig_cnt;
        } else {
            ++oth_cnt;
        }
        ++count;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", let_cnt, bla_cnt, dig_cnt, oth_cnt);

    return 0;
}