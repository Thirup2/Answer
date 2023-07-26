#include "my_strncat.h"
#include <string.h>

void my_strncat(char *dest, char *src, int dest_len)
{
    int len = strlen(dest);
    int i = 0;
    while (len + i + 1 < dest_len && src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
}