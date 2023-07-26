#include <stdio.h>
#include <string.h>
int main(void)
{
    char now[128];
    char pre[128];
    fgets(pre, 128, stdin);
    while (fgets(now, 128, stdin)) {
        if (strcmp(pre, now) == 0) {
            fputs(now, stdout);
            while (strcmp(pre, now) == 0) {
                if (fgets(now, 128, stdin) == NULL) {
                    return 0;
                }
            }
        }
        strcpy(pre, now);
    }
    return 0;
}