#include <stdio.h>
int main(void)
{
    char strs[4][80];
    for (int i = 0; i < 4; i++) {
        scanf("%s", strs[i]);
    }
    char head[13];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            head[i * 3 + j] = strs[i][j];
        }
    }
    head[12] = '\0';
    printf("%s", head);

    return 0;
}