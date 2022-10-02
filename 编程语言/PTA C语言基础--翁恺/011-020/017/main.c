#include <stdio.h>
int main(void)
{
    char level[6] = {'E','D','C','B','A','A'};
    int n;
    scanf("%d", &n);
    if (n < 50) {
        printf("E\n");
        return 0;
    }
    printf("%c\n", level[(n - 50) / 10]);

    return 0;
}