#include <stdio.h>
#include <math.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        printf("pow(3,%d) = ", i);
        printf("%d\n", (int) pow(3, i));
    }
    return 0;
}