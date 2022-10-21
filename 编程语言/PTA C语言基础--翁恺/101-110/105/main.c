#include <stdio.h>
int main(void)
{
    int n;
    int count = 0;
    while (scanf("%d", &n) == 1) {
        count++;
        if (n == 250) {
            printf("%d", count);
            return 0;
        }
    }
}