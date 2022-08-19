#include <stdio.h>
void retbit(unsigned long);
int main(void)
{
    unsigned long n;
    scanf("%lu", &n);
    retbit(n);

    return 0;
}
void retbit(unsigned long n)
{
    int i;
    i = n % 10;
    n = n / 10;
    if (n != 0) {
        retbit(n);
    }
    printf("%d ", i);
}