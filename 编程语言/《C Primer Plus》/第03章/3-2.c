#include <stdio.h>
int main(void)
{
    printf("请输入一个ASCII码: ");
    int asc;
    scanf("%d", &asc);
    printf("ASCII: %d\n", asc);
    printf("char: %c\n", asc);

    return 0;
}