#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char ch;
    int cnt = 0;
    while ((ch = getchar()) != EOF) {
        if (isblank(ch)) {
            continue;
        }
        if (isgraph(ch)) {
            cnt++;
            while ((ch = getchar()) && isgraph(ch)) {
                continue;
            }
        }
    }
    printf("%d", cnt);

    return 0;
}