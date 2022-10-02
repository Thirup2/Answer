#include <stdio.h>
int main(void)
{
    int some[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d", &some[i]);
    }
    for (int i = 7; i > 0; i--) {
        printf("%d ", some[i]);
    }
    printf("%d\n", some[0]);

    return 0;
}