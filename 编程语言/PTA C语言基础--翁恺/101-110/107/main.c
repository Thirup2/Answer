#include <stdio.h>
int main(void)
{
    int min;
    int n;
    int num;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num);
        if (i == 1) {
            min = num;
        } else {
            if (num < min) {
                min = num;
            }
        }
    }
    printf("min = %d", min);
    return 0;
}