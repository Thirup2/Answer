#include <stdio.h>
#include <ctype.h>
int main(void)
{
    int cnt[10] = {0};
    char ch;
    while ((ch = getchar()) != EOF) {
        if (isdigit(ch)) {
            cnt[ch - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            printf("%d:%d\n", i, cnt[i]);
        }
    }
    return 0;
}