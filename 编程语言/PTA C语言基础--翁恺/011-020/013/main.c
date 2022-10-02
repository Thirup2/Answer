#include <stdio.h>
#define D_W 7
int main(void)
{
    int d;

    scanf("%d", &d);
    if (d == 5) {
        printf("7");
    } else {
        printf("%d\n", (d + 2) % D_W);
    }

    return 0;
}