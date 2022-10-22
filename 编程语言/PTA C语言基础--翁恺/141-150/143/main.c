#include <stdio.h>
#include <string.h>
#include <ctype.h>
void swap(char *str1, char *str2);
int main(void)
{
    char strs[5][80];
    for (int i = 0; i < 5; i++) {
        scanf("%s", strs[i]);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 4; j > i; j--) {
            if (strcmp(strs[j], strs[j - 1]) < 0) {
                swap(strs[j], strs[j - 1]);
            }
        }
    }
    printf("After sorted:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", strs[i]);
    }

    return 0;
}
void swap(char *str1, char *str2)
{
    char str[80];
    strcpy(str, str1);
    strcpy(str1, str2);
    strcpy(str2, str);
}