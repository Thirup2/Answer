#include <stdio.h>
int main(void)
{
    char han[10][5] = {
        "ling",
        "yi",
        "er",
        "san",
        "si",
        "wu",
        "liu",
        "qi",
        "ba",
        "jiu"
    };
    char ch;
    ch = getchar();
    if (ch == '-') {
        printf("fu");
    } else {
        printf("%s", han[ch - '0']);
    }
    while ((ch = getchar()) != EOF && ch != '\n') {
        printf(" %s", han[ch - '0']);
    }

    return 0;
}