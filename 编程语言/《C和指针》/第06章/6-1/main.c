#include <stdio.h>
char *find_char(char const *source, char const *chars);
int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("参数不足，请输入两个字符串!\n");
        return -1;
    }
    char *ret = find_char(argv[1], argv[2]);
    if (ret == NULL) {
        printf("NULL\n");
    } else {
        printf("%c\n", *ret);
    }
    
    return 0;
}
char *find_char(char const *source, char const *chars)
{
    if (!source || !chars) {
        return NULL;
    }
    if (*source == '\0' || *chars == '\0') {
        return NULL;
    }
    while (*source) {
        for (int i = 0; *(chars + i); i++) {
            if (*source == *(chars + i)) {
                return (char *) source;
            }
        }
        source++;
    }
    return NULL;
}