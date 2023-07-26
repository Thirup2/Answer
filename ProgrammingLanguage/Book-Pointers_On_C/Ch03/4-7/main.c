#include <stdio.h>
void deblank(char string[]);
int main(void)
{
    char str[100];
    fgets(str, 100, stdin);
    deblank(str);
    fputs(str, stdout);

    return 0;
}
void deblank(char string[])
{
    int i = 0;
    int j = 0;
    while (string[j] != '\0') {
        string[i] = string[j];
        if (string[i] == ' ') {
            while (string[j + 1] == ' ') {
                j++;
            }
        }
        i++;
        j++;
    }
    string[i] = '\0';
}