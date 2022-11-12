#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int del_substr(char *str, char const *substr);
int IsItSub(char *str, char const *substr);
int main(int argc, char *argv[])
{
    char *substr;
    if (argc < 2) {
        printf("参数不足，请输入1-2个字符串作为参数！\n");
        return -1;
    } else if (argc < 3) {
        substr = (char *) malloc(sizeof(char));
        strcpy(substr, "");
    } else {
        int len = strlen(argv[2]);
        substr = (char *) malloc((len + 1) * sizeof(char));
        strcpy(substr, argv[2]);
    }
    int r = del_substr(argv[1], substr);
    if (r == 0) {
        printf("无匹配子串内容！\n");
        printf("%s\n", argv[1]);
    }
    if (r == 1) {
        printf("已删除！\n");
        printf("%s\n", argv[1]);
    }
    free(substr);

    return 0;
}
int del_substr(char *str, char const *substr)
{
    int pos = IsItSub(str, substr);
    if (pos == -2) {
        return 0;
    }
    if (pos == -1) {
        return 1;
    }
    int len = strlen(substr);
    int i;
    int j;
    for (i = pos, j = pos + len; *(str + j); i++, j++) {
        *(str + i) = *(str + j);
    }
    *(str + i) = '\0';
    return 1;
}
int IsItSub(char *str, char const *substr)
{
    if (strlen(substr) == 0) {
        return -1;
    }
    int flag = 1;
    int i;
    int j;
    for (i = 0; *(str + i); i++) {
        for (j = 0; *(substr + j); i++, j++) {
            if (*(str + i) != *(substr + j)) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            return i - j;
        } else {
            i = i - j;
            flag = 1;
        }
    }
    return -2;
}