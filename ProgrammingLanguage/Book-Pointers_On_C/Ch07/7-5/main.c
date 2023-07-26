#include <stdio.h>
#include <stdarg.h>
#include <string.h>
int myprintf(const char *string, ...);
int print_integer(int num);
int print_float(float num);
int main(void)
{
    char str[] = "this is a test string.";
    char ch = 'm';
    int a = 37;
    float b = 99.9;

    myprintf("int: %d\nfloat: %f\nchar: %c\nstring: %s\n", a, b, ch, str);

    return 0;
}
int myprintf(const char *string, ...)
{
    int cnt = 0;
    va_list list;
    va_start(list, string);
    while (*string) {
        if (*string == '%') {
            if (*(string + 1) == 'd') {
                print_integer(va_arg(list, int));
                cnt++;
            } else if (*(string + 1) == 'f') {
                print_float((float) va_arg(list, double));
                cnt++;
            } else if (*(string + 1) == 'c') {
                putchar((char) va_arg(list, int));
                cnt++;
            } else if (*(string + 1) == 's') {
                cnt++;
                char *str = va_arg(list, char *);
                while (*str) {
                    putchar(*str);
                    str++;
                }
            } else {
                putchar('%');
                putchar(*(string + 1));
            }
            string += 2;
        } else {
            putchar(*string);
            string++;
        }
    }
    va_end(list);
    return cnt;
}
int print_integer(int num)
{
    printf("%d", num);
}
int print_float(float num)
{
    printf("%.1f", num);
}