#include <stdio.h>
int main(void)
{
    int sum = 0;
    int num;
    while (scanf("%d", &num) == 1 && num > 0) {
        if (num % 2 == 1) {
            sum += num;
        }
    }
    printf("%d\n", sum);

    return 0;
}