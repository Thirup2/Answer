#include <stdio.h>
int Febo(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", Febo(n));
    return 0;
}
int Febo(int n)
{
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return Febo(n - 2) + Febo(n - 1);
    }
}