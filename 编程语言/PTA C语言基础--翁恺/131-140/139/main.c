#include <stdio.h>
int main(void)
{
    int m, k;
    scanf("%d %d", &m, &k);
    int days = 0;
    while (m) {
        days++;
        m--;
        if (days % k == 0) {
            m++;
        }
    }
    printf("%d", days);
    return 0;
}