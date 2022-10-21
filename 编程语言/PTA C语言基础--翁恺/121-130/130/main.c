#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int sum = 0;
    int num;
    while (n--) {
        scanf("%d", &num);
        sum += num;
    }
    printf("%d", sum);
    return 0;
}