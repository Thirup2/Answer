#include <stdio.h>
int main(void)
{
    char string[] = "I Love GPLT";
    for (int i = 0; i < sizeof(string) - 1; i++) {
        printf("%c\n", string[i]);
    }

    return 0;
}