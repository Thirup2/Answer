#include <stdio.h>
int main(void)
{
    int ch;
    scanf("%c", &ch);
    for (int i = 'A'; i <= ch; ++i) {
        for (int j = 1; j < 40 - (i - 'A'); ++j) {
            printf(" ");
        }
        if (i != ch) {
            int r = 0;
            printf("%c", i);
            for (int j = i - 'A', count = 0; count < j * 2 - 1; ++count) {
                printf(" ");
                r = 1;
            }
            if (r == 1) {
                printf("%c", i);
            }
            printf("\n");
        } else {
            for (int j = i - 'A', count = 0; count < j * 2 + 1; ++count) {
                printf("%c", i);
            }
        }
    }
    return 0;
}