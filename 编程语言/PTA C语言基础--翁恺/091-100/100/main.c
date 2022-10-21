#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int a, b, c;
    int r = 0;
    c = n % 10;
    n /= 10;
    b = n % 10;
    n /= 10;
    a = n % 10;
    n /= 10;
    if (c != 0) {
        printf("%d", c);
        r = 1;
    }
    if (b != 0 || (b == 0 && r == 1)) {
        printf("%d", b);
        r = 1;
    }
    if (a != 0 || (a == 0 && r == 1)) {
        printf("%d", a);
    }
    return 0;
}