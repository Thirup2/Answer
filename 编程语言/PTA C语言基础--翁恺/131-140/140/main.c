#include <stdio.h>
int Febo(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", Febo(n-1));
    return 0;
}
int Febo(int n)
{
    if (n == 0) {
        return 0;
    }else if (n == 1) {
        return 1;
    } else {
        return Febo(n - 1) + Febo(n - 2);
    }
}