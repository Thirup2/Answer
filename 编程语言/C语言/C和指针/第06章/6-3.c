#include <stdio.h>
#define SIZE 10
void reverse_string(char *string);
int main(void)
{
    char str[SIZE];
    scanf("%s", str);
    char *string = str;
    printf("%s\n", string);
    reverse_string(string);
    printf("%s\n", string);

    return 0;
}
void reverse_string(char *string)
{
    char *last_char;
    for (last_char = string; *last_char != '\0'; ++last_char);
    last_char--;
    while (string < last_char) {
        char temp;
        temp = *string;
        *string++ = *last_char;
        *last_char-- = temp;
    }
}