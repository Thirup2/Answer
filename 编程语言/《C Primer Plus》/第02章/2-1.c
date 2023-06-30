#include <stdio.h>

#define FN "Gustav"
#define LN "Mahler"

int main(void)
{
    printf("%s %s\n", FN, LN);
    printf("%s\n%s\n", FN, LN);
    printf("%s ", FN);
    printf("%s\n", LN);

    return 0;
}