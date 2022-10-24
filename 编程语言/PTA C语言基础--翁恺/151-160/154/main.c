#include <stdio.h>
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int n = 0;
    int sum = 0;
    for (int i = a; i <= b; i++) {
        n++;
        printf("%5d", i);
        sum += i;
        if (n % 5 == 0) {
            printf("\n");
        }
    }
    if (n % 5 != 0) {
        printf("\n");
    }
    printf("Sum = %d\n", sum);

    return 0;
}