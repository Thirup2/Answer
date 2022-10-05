#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int cnt = 0;
    if (n < 0) {
        printf("0\n");
        return 0;
    }
    while (n > 0) {
        n /= 2;
        cnt++;
    }
    printf("%d\n", 32 - cnt);

    return 0;
}