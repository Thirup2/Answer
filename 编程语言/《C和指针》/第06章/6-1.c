#include <stdio.h>
char *find_char(char const *source, char const *chars);
int main(void)
{
    char const *source = "ABCDEF";
    char const *chars = "XRCQEF";
    char *answer;
    if (answer = find_char(source, chars)) {
        printf("%c", *answer);
    } else {
        printf("NULL\n");
    }
    return 0;
}
char *find_char(char const *source, char const *chars)
{
    if (!(source && chars)) {
        return NULL;
    }
    char const *chars_copy = chars;
    while (*source != '\0') {
        while (*chars_copy != '\0') {
            if (*source == *chars_copy) {
                return (char *)source;
            }
            ++chars_copy;
        }
        chars_copy = chars;
        ++source;
    }
    return NULL;
}