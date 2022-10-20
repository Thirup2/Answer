#include <stdio.h>
int main(void)
{
    int ch;
    int count = 0;
    while ((ch = getchar()) != '\n') {
        if (ch >= 'A' && ch <= 'Z') {
            if (ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') {
                ++count;
            }
        }
    }
    printf("%d", count);

    return 0;
}