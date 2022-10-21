#include <stdio.h>
#include <string.h>
int main(void)
{
    int Pre_Is_Blank = 0;
    char ch;
    int word = 0;
    int count = 0;
    while (scanf("%c", &ch) == 1 && ch != '.') {
        if (ch != ' ') {
            ++count;
            Pre_Is_Blank = 0;
            continue;
        } else {
            if (Pre_Is_Blank == 0) {
                if (count > 0) {
                    word++;
                    if (word == 1) {
                        printf("%d", count);
                    } else {
                        printf(" %d", count);
                    }
                }
                count = 0;
                Pre_Is_Blank = 1;
                continue;
            }
        }
    }
    if (count > 0) {
        word++;
        if (word == 1) {
            printf("%d", count);
        } else {
            printf(" %d", count);
        }
    }
    return 0;
}