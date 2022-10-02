#include <stdio.h>
#include <string.h>
int main(void)
{
    char arr[50];
    scanf("%s", arr);
    for (int i = strlen(arr) - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    printf("\n");

    return 0;
}