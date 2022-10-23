#include <stdio.h>
#include <string.h>
int main(void)
{
    int k;
    scanf("%d", &k);
    int i = 1;
    char out[8];
    while (scanf("%s", out) && strcmp(out, "End")) {
        if (i % (k + 1) != 0) {
            if (!strcmp(out, "ChuiZi")) {
                printf("Bu\n");
            }
            if (!strcmp(out, "JianDao")) {
                printf("ChuiZi\n");
            }
            if (!strcmp(out, "Bu")) {
                printf("JianDao\n");
            }
        } else {
            printf("%s\n", out);
        }
        i++;
    }

    return 0;
}