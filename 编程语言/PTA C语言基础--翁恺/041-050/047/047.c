#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    int i = 0;
    if (n > 0) {
        sum++;
        ++i;
    }
    while (n > 0 && sum < n) {
        sum *= 2;
        i++;
    }
    if (n < 0) {
        i = 32;
    }
    printf("%d", 32 - i);

    return 0;
}