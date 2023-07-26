#include "my_strcpy_end.h"
#include <stdio.h>

int main(void)
{
    char *wait2copy = "this is a string";
    char copystring[20];
    char *target = my_strcpy_end(copystring, wait2copy);
    int i = 0;
    while (copystring + i != target) {
        putchar(copystring[i]);
        i++;
    }
    printf("\n");
    return 0;
}